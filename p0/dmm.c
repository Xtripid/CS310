#include <stdio.h>  // needed for size_t
#include <unistd.h> // needed for sbrk
#include <assert.h> // needed for asserts
#include "dmm.h"

/* You can improve the below metadata structure using the concepts from Bryant
 * and OHallaron book (chapter 9).
 */

typedef struct metadata {
  /* size_t is the return type of the sizeof operator. Since the size of an
   * object depends on the architecture and its implementation, size_t is used
   * to represent the maximum size of any object in the particular
   * implementation. size contains the size of the data object or the number of
   * free bytes
   */
  size_t size;
  struct metadata* next;
  struct metadata* prev;
  bool isFree;
} metadata_t;

/* freelist maintains all the blocks which are not in use; freelist is kept
 * sorted to improve coalescing efficiency
 */

static metadata_t* freelist = NULL;

void* dmalloc(size_t numbytes) {
    /* initialize through sbrk call first time */
    if(freelist == NULL) {
        if(!dmalloc_init())
            return NULL;
    }

    assert(numbytes > 0);

    metadata_t* runner = freelist;

    metadata_t* temp = NULL;

    // printf("start malloc...\n");
    while (runner != NULL) {
        if (runner->isFree && runner->size >= (ALIGN(numbytes) + METADATA_T_ALIGNED)) {
            // printf("found potential block\n");
            if (temp) {
                // printf("temp already exists\n");
                if (runner->size < temp->size) {
                    // printf("replacing temp\n");
                    temp = runner;
                }
            } else {
                // printf("temp does not exist, first initialization\n");
                temp = runner;
            }
        }

        // printf("move to next block\n");
        runner = runner->next;
    }

    if (temp == NULL) {
        // printf("temp is null\n");
        return NULL;
    }

    temp->isFree = false;
    // printf("set temp to not free\n");

    if (temp->size > (ALIGN(numbytes) + METADATA_T_ALIGNED)) {
        // printf("temp size needs to be split\n");
        metadata_t* block = temp;
        block = ((metadata_t*) (((void*) block) + ALIGN(numbytes) + METADATA_T_ALIGNED));
        block->size = temp->size - ALIGN(numbytes) - METADATA_T_ALIGNED;
        temp->size = ALIGN(numbytes);

        block->next = temp->next;
        block->prev = temp;
        block->isFree = true;

        if (temp->next) {
            temp->next->prev = block;
        }

        temp->next = block;
    }

    return ((void*) temp) + METADATA_T_ALIGNED;

  /* Go through the free blocks and find the smallest block that fits
   * Split up the free heap block into the part that is needed and the part
   * that will be empty HELLO
   * Make next from previous block point towards the new malloc'd memory
   * Make next from malloc'd memory point towards the remaining block
   * Make next from the remaining block point towards what the previous block
   * was pointing to
  */
}

void dfree(void* ptr) {

  /* Take the given pointer's block and put it back in freelist
   * Check to see if the new block in freelist has any free spots next to it
   * If it does, coalesce
  */

  /* First check to see if the list is empty. If it is, make it the new freed
   * block
  */

    // printf("dfree\n")

    metadata_t* pointer = (metadata_t*) ptr;

    // printf("move pointer to top\n");
    pointer = pointer - 1;
    // printf("set free to true\n");
    pointer->isFree = true;

    if (pointer->next && pointer->next->isFree) {
        // printf("coalesce next block\n");
        pointer->size = pointer->size + pointer->next->size;

        // printf("moving pointer->next to next next block\n");
        if (pointer->next->next != NULL) {
            // printf("next next block exists, move prev pointer\n");
            pointer->next->next->prev = pointer;
        }

        pointer->next = pointer->next->next;

        // printf("make sure isFree is true\n");
        pointer->isFree = true;
    }

    if (pointer->prev && pointer->prev->isFree) {
        pointer->prev->size = pointer->prev->size + pointer->size;

        if (pointer->next) {
            pointer->next->prev = pointer->prev;
        }

        pointer->prev->next = pointer->next;

        pointer->prev->isFree = true;
    }
}

bool dmalloc_init() {

  /* Two choices:
   * 1. Append prologue and epilogue blocks to the start and the
   * end of the freelist
   *
   * 2. Initialize freelist pointers to NULL
   *
   * Note: We provide the code for 2. Using 1 will help you to tackle the
   * corner cases succinctly.
   */

  size_t max_bytes = ALIGN(MAX_HEAP_SIZE);
  /* returns heap_region, which is initialized to freelist */
  freelist = (metadata_t*) sbrk(max_bytes);
  /* Q: Why casting is used? i.e., why (void*)-1? */
  if (freelist == (void *)-1)
    return false;
  freelist->next = NULL;
  freelist->prev = NULL;
  freelist->isFree = true;
  freelist->size = max_bytes-METADATA_T_ALIGNED;
  return true;
}

/* for debugging; can be turned off through -NDEBUG flag*/
void print_freelist() {
  metadata_t *freelist_head = freelist;
  while(freelist_head != NULL) {
    DEBUG("\tFreelist Size:%zd, Head:%p, Prev:%p, Next:%p\t",
	  freelist_head->size,
	  freelist_head,
	  freelist_head->prev,
	  freelist_head->next);
    freelist_head = freelist_head->next;
  }
  DEBUG("\n");
}

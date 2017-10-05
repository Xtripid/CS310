#include <stdlib.h>
#include <stdio.h>

#include "dmm.h"

int main(int argc, char* argv[]) {
    void* array1[5];

    int size = MAX_HEAP_SIZE/4;

    printf("%d\n", size);

    printf("malloc\n");
    array1[0] = dmalloc(size);
    array1[1] = dmalloc(size);
    array1[2] = dmalloc(size);

    printf("free 1\n");
    dfree(array1[0]);
    // print_freelist();
    printf("\n");
    printf("free 2\n");
    dfree(array1[2]);
    // print_freelist();
    printf("\n");
    printf("free 3\n");
    dfree(array1[1]);
    // print_freelist();

    int temp = size*3;
    array1[3] = dmalloc(temp);

    if (array1[3] == NULL) {
        printf("help.");
    }
}

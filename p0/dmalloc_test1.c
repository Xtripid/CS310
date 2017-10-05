#include <stdio.h>
#include <stdlib.h>

#include "dmm.h"

int main(int argc, char* argv[]) {
    int* x;
    printf("%zd\n", x);

    x = x + 1;

    printf("%zd\n", x);
}

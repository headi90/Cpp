#include <stdint.h>
#include <stdio.h>

int is_big_endian(void)
{
    union {
        uint32_t i;
        char c[4];
    } bint;

    bint.i = 0x01020304;

    printf("0x%08x  -->  0x%02x 0x%02x 0x%02x 0x%02x\n", bint.i, bint.c[0], bint.c[1], bint.c[2], bint.c[3]);

    return bint.c[0] == 1;
}

int main(void)
{
    printf("Is big endian? %s\n", is_big_endian() == 1 ? "YES" : "NO");
    return 0;
}
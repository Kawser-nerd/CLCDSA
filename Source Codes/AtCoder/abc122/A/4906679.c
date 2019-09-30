#include <stdio.h>

int
main(int argc, char *argv[])
{
    char b;

    scanf("%c", &b);

    if (b == 'A' || b == 'T') {
        printf("%c\n", b == 'A' ? 'T' : 'A');
    } else {
        printf("%c\n", b == 'C' ? 'G' : 'C');
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c", &b);
     ^
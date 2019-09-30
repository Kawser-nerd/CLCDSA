#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    char a[11], b[11], c[11];
    scanf("%s %s %s", a, b, c);
    printf("%c%c%c\n", a[0] - 32, b[0] - 32, c[0] - 32);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s %s %s", a, b, c);
     ^
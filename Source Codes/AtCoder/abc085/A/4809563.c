#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char s[11] = {0};
    scanf("%s", s);
    s[3] = '8';
    printf("%s\n", s);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^
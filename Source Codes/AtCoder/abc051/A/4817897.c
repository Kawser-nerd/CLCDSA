#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[20];
    scanf("%s", s);
    s[5] = s[13] = ' ';
    printf("%s\n", s);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[10 + 1];
    scanf("%10s\n", s);

    if (strlen(s) == 1 && s[0] == 'a')
    {
        printf("-1\n");
    }
    else
    {
        printf("a\n");
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%10s\n", s);
     ^
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char s[4];
    scanf("%s", s);
    if (s[1] == s[2])
    {
        if (s[0] == s[1] || s[2] == s[3])
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    else
    {
        printf("No\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^
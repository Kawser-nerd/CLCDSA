#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char c1[4] = {0}, c2[4] = {0};
    scanf("%s%s", c1, c2);
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        if (c1[i] == c2[2 - i])
        {
            k++;
        }
    }
    if (k == 3)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s", c1, c2);
     ^
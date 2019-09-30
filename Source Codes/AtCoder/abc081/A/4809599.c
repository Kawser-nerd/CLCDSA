#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char s[3];
    scanf("%s", s);
    int k = 0;
    for (int i = 0; i < 3 ; i++)
    {
        if (s[i] == '1')
        {
            k++;
        }
    }
    printf("%d\n", k);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^
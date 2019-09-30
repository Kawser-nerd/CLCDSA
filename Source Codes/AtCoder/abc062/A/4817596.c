#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a[2];
    scanf("%d%d", &a[0], &a[1]);
    for (int i = 0; i < 2; i++)
    {
        if (a[i] == 4 || a[i] == 6 || a[i] == 9 || a[i] == 11)
        {
            a[i] = 1;
        }
        else if (a[i] != 2)
        {
            a[i] = 0;
        }
    }
    if (a[0] == a[1])
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &a[0], &a[1]);
     ^
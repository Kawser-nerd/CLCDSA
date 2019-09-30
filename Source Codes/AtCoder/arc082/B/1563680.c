#include <stdio.h>

int main(void)
{
    int n, p[100000] = {}, count = 0;
    int i, j;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (p[i] == i + 1)
        {
            count++;
            i++;
        }
    }

    printf("%d", count);
    return (0);
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &p[i]);
         ^
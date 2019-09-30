#include <stdio.h>

int main(void)
{
    int n, a[100000], max = 0, count[100003] = {};
    int i, j;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        count[a[i]]++;
        count[a[i] + 1]++;
        count[a[i] + 2]++;
    }

    for (i = 1; i <= 100001; i++)
    {
        if (count[i] > max)
            max = count[i];
    }

    printf("%d", max);
    return (0);
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^
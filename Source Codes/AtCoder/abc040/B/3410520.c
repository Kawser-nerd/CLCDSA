#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int i = 0;
    while (i*i <= n)
        i++;
    i--;
    int ans = n - (i*i);
    int k = i * i;
    int min, max;
    int j;
    for (i = k + 1; i <= n; i++)
    {
        min = 1;
        max = i;
        for(j=1;j<max;j++)
            if (i%j == 0)
            {
                min = j;
                max = i / j;
            }
        if (ans > max - min + n - i)
            ans = max - min + n - i;
    }
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
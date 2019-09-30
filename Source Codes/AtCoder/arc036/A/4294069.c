#include<stdio.h>
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int i;
    int t[100005];
    for (i = 0; i < n; i++)
        scanf("%d", &t[i]);
    for (i = 2; i < n; i++)
    {
        if (t[i] + t[i - 1] + t[i - 2] < k)
        {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &k);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &t[i]);
         ^
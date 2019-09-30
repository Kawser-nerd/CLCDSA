#include<stdio.h>
int main()
{
    int i;
    int d[7], j[7];
    for (i = 0; i < 7; i++)
        scanf("%d", &d[i]);
    for (i = 0; i < 7; i++)
        scanf("%d", &j[i]);
    int ans = 0;
    for (i = 0; i < 7; i++)
    {
        if (d[i] > j[i])
            ans += d[i];
        else
            ans += j[i];
    }
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &d[i]);
         ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &j[i]);
         ^
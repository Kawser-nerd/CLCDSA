#include<stdio.h>
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int p[100005];
    int count[100005];
    int x, y;
    int i;
    for (i = 0; i < n; i++)
    {
        count[i] = 1;
        p[i] = 0;
    }
    p[0] = 1;
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        x--;
        y--;
        if (p[x] == 1)
            p[y] = 1;
        count[x]--;
        count[y]++;
        if (count[x] == 0)
            p[x] = 0;
    }
    int ans = 0;
    for (i = 0; i < n; i++)
        if (p[i] == 1)
            ans++;
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^
./Main.c:18:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &x, &y);
         ^
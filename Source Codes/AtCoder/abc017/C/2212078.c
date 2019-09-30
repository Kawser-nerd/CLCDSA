#include<stdio.h>
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int p[100000];
    int i;
    int l, r, s, j;
    for (i = 0; i < m; i++)
        p[i] = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &l, &r, &s);
        l--;
        for (j = 0; j < l; j++)
            p[j] += s;
        for (j = r; j < m; j++)
            p[j] += s;
    }
    int ans = 0;
    for (i = 0; i < m; i++)
        if (ans < p[i])
            ans = p[i];
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d", &l, &r, &s);
         ^
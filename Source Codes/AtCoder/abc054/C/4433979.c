#include<stdio.h>
#include<math.h>
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int i;
    int a[30], b[30];
    for (i = 0; i < m; i++)
        scanf("%d %d", &a[i], &b[i]);
    int p[10][10] = {};
    for (i = 0; i < m; i++)
        p[a[i] - 1][b[i] - 1] = p[b[i] - 1][a[i] - 1] = 1;
    int x, now, y;
    int j, k;
    int q[10];
    int ans = 0;
    for (j = 0; j < pow(n, n - 1); j++)
    {
        for (i = 0; i < n; i++)
            q[i] = 0;
        x = j;
        now = x % n;
        x /= n;
        k = 0;
        q[now] = 1;
        for (i = 1; i < n; i++)
        {
            y = x % n;
            x /= n;
            if (q[y] == 1)
            {
                k++;
                break;
            }
            if (p[now][y] == 0)
            {
                k++;
                break;
            }
            now = y;
            q[now] = 1;
        }
        if (k == 0)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &a[i], &b[i]);
         ^
#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    int m;
    scanf("%d", &m);
    int x[200], y[200];
    int i;
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
        x[i]--;
        y[i]--;
    }
    int v[100];
    for (i = 0; i < n; i++)
        v[i] = 999;
    int ans[100];
    for (i = 0; i < n; i++)
        ans[i] = 2000000000;
    v[a] = 0;
    ans[a] = 1;
    int j, k;
    k = 0;
    while (ans[b] == 2000000000)
    {
        for (i = 0; i < n; i++)
        {
            if (v[i] == k)
            {
                for (j = 0; j < m; j++)
                {
                    if (x[j] == i)
                    {
                        if (v[y[j]] == 999)
                        {
                            v[y[j]] = k + 1;
                            ans[y[j]] = ans[i];
                        }
                        else if (v[y[j]] == k + 1)
                        {
                            ans[y[j]] += ans[i];
                        }
                        ans[y[j]] %= 1000000007;
                    }
                    if (y[j] == i)
                    {
                        if (v[x[j]] == 999)
                        {
                            v[x[j]] = k + 1;
                            ans[x[j]] = ans[i];
                        }
                        else if (v[x[j]] == k + 1)
                        {
                            ans[x[j]] += ans[i];
                        }
                        ans[x[j]] %= 1000000007;
                    }
                }
            }
        }
        k++;
    }
    printf("%d\n", ans[b]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &a, &b);
     ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &m);
     ^
./Main.c:16:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &x[i], &y[i]);
         ^
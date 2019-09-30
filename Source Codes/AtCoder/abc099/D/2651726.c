#include<stdio.h>
int main()
{
    int n, C;
    scanf("%d %d", &n, &C);
    int i, j, k;
    int d[33][33];
    for (i = 0; i < C; i++)
        for (j = 0; j < C; j++)
            scanf("%d", &d[i][j]);
    int c[505][505];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &c[i][j]);
            c[i][j]--;
        }
    }
    int ans = 2000000000;
    int x, y;
    int a;
    int v[3][33];
    for (i = 0; i < 3; i++)
        for (j = 0; j < C; j++)
            v[i][j] = 0;
    for (i = 0; i < C; i++)
        for (x = 0; x < n; x++)
            for (y = 0; y < n; y++)
                v[(x + y) % 3][i] += d[c[x][y]][i];
    for (i = 0; i < C; i++)
    {
        for (j = 0; j < C; j++)
        {
            if (i != j)
            {
                for (k = 0; k < C; k++)
                {
                    if (i != k && j != k)
                    {
                        a = v[0][i] + v[1][j] + v[2][k];
                        if (ans > a)
                            ans = a;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &C);
     ^
./Main.c:10:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &d[i][j]);
             ^
./Main.c:16:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &c[i][j]);
             ^
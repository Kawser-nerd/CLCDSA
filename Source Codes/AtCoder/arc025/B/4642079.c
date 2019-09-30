#include<stdio.h>
int main()
{
    int h, w;
    scanf("%d %d", &h, &w);
    int i, j;
    int c[102][102];
    for (i = 0; i < h; i++)
        for (j = 0; j < w; j++)
            scanf("%d", &c[i][j]);
    for (i = 0; i < h; i++)
        for (j = 0; j < w; j++)
            if ((i + j) % 2 == 1)
                c[i][j] *= -1;
    int p[102][102];
    for (i = 0; i < w; i++)
        p[0][i] = 0;
    for (i = 0; i < h; i++)
        p[i][0] = 0;
    for (i = 1; i <= h; i++)
        for (j = 1; j <= w; j++)
            p[i][j] = p[i][j - 1] + p[i - 1][j] - p[i - 1][j - 1] + c[i - 1][j - 1];
    int max = 0;
    int x, y;
    for (i = 0; i < h; i++)
        for (j = 0; j < w; j++)
            for (x = i; x < h; x++)
                for (y = j; y < w; y++)
                    if (p[x + 1][y + 1] - p[i][y + 1] - p[x + 1][j] + p[i][j] == 0)
                        if (max < (x - i + 1)*(y - j + 1))
                            max = (x - i + 1)*(y - j + 1);
    printf("%d\n", max);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &h, &w);
     ^
./Main.c:10:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &c[i][j]);
             ^
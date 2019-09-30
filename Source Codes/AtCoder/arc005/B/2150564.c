#include<stdio.h>
int main()
{
    int x, y;
    char w[3];
    char c[9][9];
    int a, b;
    char ans[5];
    scanf("%d %d %s", &x, &y, w);
    int i, j;
    for (i = 0; i < 9; i++)
        scanf("%s", c[i]);
    if ((w[0] == 'R') && (w[1] == '\0'))
    {
        a = 1;
        b = 0;
    }
    if ((w[0] == 'L') && (w[1] == '\0'))
    {
        a = -1;
        b = 0;
    }
    if ((w[0] == 'U') && (w[1] == '\0'))
    {
        a = 0;
        b = -1;
    }
    if ((w[0] == 'D') && (w[1] == '\0'))
    {
        a = 0;
        b = 1;
    }
    if ((w[0] == 'R') && (w[1] == 'U'))
    {
        a = 1;
        b = -1;
    }
    if ((w[0] == 'R') && (w[1] == 'D'))
    {
        a = 1;
        b = 1;
    }
    if ((w[0] == 'L') && (w[1] == 'U'))
    {
        a = -1;
        b = -1;
    }
    if ((w[0] == 'L') && (w[1] == 'D'))
    {
        a = -1;
        b = 1;
    }
    x--;
    y--;
    for (i = 0; i < 4; i++)
    {
        ans[i] = c[y][x];
        x += a;
        y += b;
        if (x < 0)
        {
            a = 1;
            x = 1;
        }
        if (x > 8)
        {
            a = -1;
            x = 7;
        }
        if (y < 0)
        {
            b = 1;
            y = 1;
        }
        if (y > 8)
        {
            b = -1;
            y = 7;
        }
    }
    ans[4] = '\0';
    printf("%s\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %s", &x, &y, w);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", c[i]);
         ^
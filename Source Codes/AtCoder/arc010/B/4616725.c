#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int m[400], d[400];
    for (i = 0; i < n; i++)
        scanf("%d/%d", &m[i], &d[i]);
    int p[400];
    for (i = 0; i < 400; i++)
        p[i] = 0;
    for (i = 0; i < 400; i++)
        if (i % 7 == 0 || i % 7 == 1)
            p[i]++;
    int x;
    for (i = 0; i < n; i++)
    {
        if (m[i] == 1)x = d[i];
        if (m[i] == 2)x = 31 + d[i];
        if (m[i] == 3)x = 60 + d[i];
        if (m[i] == 4)x = 91 + d[i];
        if (m[i] == 5)x = 121 + d[i];
        if (m[i] == 6)x = 152 + d[i];
        if (m[i] == 7)x = 182 + d[i];
        if (m[i] == 8)x = 213 + d[i];
        if (m[i] == 9)x = 244 + d[i];
        if (m[i] == 10)x = 274 + d[i];
        if (m[i] == 11)x = 305 + d[i];
        if (m[i] == 12)x = 335 + d[i];
        p[x]++;
    }
    for (i = 1; i <= 366; i++)
    {
        if (p[i] > 1)
        {
            p[i + 1] += p[i] - 1;
            p[i] = 1;
        }

    }
    int ans = 0;
    p[0] = 0;
    for (i = 0; i < 367; i++)
    {
        if (p[i] == 1)
            x++;
        else
            x = 0;
        if (ans < x)
            ans = x;
    }
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d/%d", &m[i], &d[i]);
         ^
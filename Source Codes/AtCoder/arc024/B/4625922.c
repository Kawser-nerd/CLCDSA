#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int color[100005];
    for (i = 0; i < n; i++)
        scanf("%d", &color[i]);
    int count[2] = { 0,0 };
    for (i = 0; i < n; i++)
        count[color[i]]++;
    if (count[0] == 0 || count[1] == 0)
    {
        printf("-1\n");
        return 0;
    }
    int p[200005];
    for (i = 0; i < n; i++)
        p[i] = color[i];
    for (i = 0; i < n; i++)
        p[i + n] = color[i];
    int max = 0, x;
    x = 1;
    for (i = 0; i < 2 * n; i++)
    {
        if (p[i] == p[i - 1])
            x++;
        else
            x = 1;
        if (max < x)
            max = x;
    }
    max++;
    printf("%d\n", max / 2);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &color[i]);
         ^
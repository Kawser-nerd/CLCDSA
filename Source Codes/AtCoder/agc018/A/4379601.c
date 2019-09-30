#include<stdio.h>
int gcd(int a, int b)
{
    int r = a % b;
    while (r > 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int i;
    int a[100005];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int max = 0;
    for (i = 0; i < n; i++)
        if (max < a[i])
            max = a[i];
    if (k > max)
    {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    int g = a[0];
    for (i = 0; i < n; i++)
        g = gcd(g, a[i]);
    if (k%g == 0)
        printf("POSSIBLE\n");
    else
        printf("IMPOSSIBLE\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &k);
     ^
./Main.c:20:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^
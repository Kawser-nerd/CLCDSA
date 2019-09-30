#include<stdio.h>
long long int abs(long long int n)
{
    if (n < 0)
        n *= -1;
    return n;
}
int main()
{
    int n;
    scanf("%d", &n);
    int i, j, k;
    long long int x[102], y[102];
    for (i = 0; i < n; i++)
        scanf("%lld %lld", &x[i], &y[i]);
    long long int a, b, c, d;
    int ans = 0;
    for (i = 0; i < n - 2; i++)
    {
        for (j = i + 1; j < n - 1; j++)
        {
            for (k = j + 1; k < n; k++)
            {
                a = x[j] - x[i];
                b = x[k] - x[i];
                c = y[j] - y[i];
                d = y[k] - y[i];
                if (abs(a*d - b * c) % 2 == 0 && abs(a*d - b * c) != 0)
                    ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
} ./Main.c:2:15: warning: conflicting types for built-in function ‘abs’
 long long int abs(long long int n)
               ^
./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld %lld", &x[i], &y[i]);
         ^
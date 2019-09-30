#include<stdio.h>
int main()
{
    int n, m, l;
    scanf("%d %d %d", &n, &m, &l);
    int p, q, r;
    scanf("%d %d %d", &p, &q, &r);
    int ans = 0;
    int x;
    x = (n / p)*(m / q)*(l / r);
    if (ans < x)ans = x;
    x = (n / p)*(m / r)*(l / q);
    if (ans < x)ans = x;
    x = (n / q)*(m / p)*(l / r);
    if (ans < x)ans = x;
    x = (n / q)*(m / r)*(l / p);
    if (ans < x)ans = x;
    x = (n / r)*(m / p)*(l / q);
    if (ans < x)ans = x;
    x = (n / r)*(m / q)*(l / p);
    if (ans < x)ans = x;
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &n, &m, &l);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &p, &q, &r);
     ^
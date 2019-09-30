#include<stdio.h>
#include<math.h>
int prime(int n)
{
    if (n < 2)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    int i;
    for (i = 3; i <= sqrt(n); i += 2)
        if (n%i == 0)
            return 0;
    return 1;
}
int main()
{
    int q;
    scanf("%d", &q);
    int i;
    int l[100005], r[100005];
    for (i = 0; i < q; i++)
        scanf("%d %d", &l[i], &r[i]);
    int p[100005];
    for (i = 0; i < 100005; i++)
        p[i] = 0;
    for (i = 0; i < 100005; i++)
        if (i % 2 == 1)
            if (prime(i) == 1 && prime((i + 1) / 2) == 1)
                p[i]++;
    for (i = 1; i < 100005; i++)
        p[i] += p[i - 1];
    for (i = 0; i < q; i++)
        printf("%d\n", p[r[i]] - p[l[i] - 1]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &q);
     ^
./Main.c:24:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &l[i], &r[i]);
         ^
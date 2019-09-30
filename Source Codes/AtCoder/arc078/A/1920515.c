#include<stdio.h>
int num[200001];
long long ZZ(long long a, long long b)
{
    return a > b ? a - b : b - a;
}
int main()
{
    long long sum = 0;
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
        sum += num[i];
    }
    if(n == 2)printf("%lld", ZZ(num[0], num[1]));
    else
    {
        long long ans = 1e+16;

        long long summ = 0;
        for (i = 0; i < n - 1; i++)
        {
            summ += num[i];
            ans = ans < ZZ(sum - summ, summ) ? ans : ZZ(sum - summ, summ);
        }
        printf("%lld",ans);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &num[i]);
         ^
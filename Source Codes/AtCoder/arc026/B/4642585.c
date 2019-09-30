#include<stdio.h>
#include<math.h>
int main()
{
    unsigned long long int n;
    scanf("%lld", &n);
    unsigned long long int sum = 0, i;
    for (i = 1; i <= sqrt(n); i++)
    {
        if (n%i == 0)
        {
            sum += i + (n / i);
            if (i*i == n)
                sum -= i;
        }
    }
    sum -= n;
    if (sum < n)
        printf("Deficient\n");
    else if (sum == n)
        printf("Perfect\n");
    else
        printf("Abundant\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &n);
     ^
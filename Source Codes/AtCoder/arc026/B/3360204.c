#include<stdio.h>
long long n,i,sqn,sum;
int main()
{
    scanf("%lld",&n);
    if(n==1)
    {printf("Deficient\n");
    return 0;}
    for(i=1;i*i<=n;i++)
    if(n%i==0)
    {sum+=i;
    sum+=n/i;}
    sum-=n;
    sqn=sqrt(n);
    if(sqn*sqn==n)
    sum-=sqn;
    if(sum==n)
    printf("Perfect\n");
    if(sum<n)
    printf("Deficient\n");
    if(sum>n)
    printf("Abundant\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:9: warning: implicit declaration of function ‘sqrt’ [-Wimplicit-function-declaration]
     sqn=sqrt(n);
         ^
./Main.c:14:9: warning: incompatible implicit declaration of built-in function ‘sqrt’
./Main.c:14:9: note: include ‘<math.h>’ or provide a declaration of ‘sqrt’
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^
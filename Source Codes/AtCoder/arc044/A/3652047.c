#include<stdio.h>
int main()
{
    long long n,i,j;
    scanf("%lld",&n);
    if(n%2==0&&n!=2)
    {printf("Not Prime\n");
    return 0;}
    if(n%3==0&&n!=3)
    {printf("Not Prime\n");
    return 0;}
    if(n%5==0&&n!=5)
    {printf("Not Prime\n");
    return 0;}
    if(n==1)
    {printf("Not Prime\n");
    return 0;}
    printf("Prime\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^
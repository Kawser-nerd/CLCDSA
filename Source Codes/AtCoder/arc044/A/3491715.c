#include<stdio.h>
//bool a[100000001];
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
    /*for(i=2;i*i<=10000000;i++)
    {if(a[i]==0)
    for(j=i*2;j<=10000000;j+=i)
    if(a[j]==0)
    a[j]=1;}
    if(a[n]==0)*/
    printf("Prime\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^
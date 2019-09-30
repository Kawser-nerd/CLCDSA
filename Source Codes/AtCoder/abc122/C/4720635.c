#include<stdio.h>
char a[100100];
long long b[100100];
int main()
{
    long long n,q,i,j;
    scanf("%lld %lld",&n,&q);
    scanf("%s",a);
    for(i=0,j=0;a[i+1]!='\0';i++)
    {
        b[i]=j;
        if(a[i]=='A'&&a[i+1]=='C')
            j++;
    }
    b[i]=j;
    while(q--)
    {
        scanf("%lld%lld",&i,&j);
        printf("%lld\n",b[j-1]-b[i-1]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld",&n,&q);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",a);
     ^
./Main.c:18:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld%lld",&i,&j);
         ^
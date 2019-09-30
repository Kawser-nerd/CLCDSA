#include<stdio.h>
int main()
{  long long a,b,c,k;
   scanf("%lld %lld %lld %lld",&a,&b,&c,&k);
     if(k%2==0)
        printf("%lld\n",a-b);
     else
       printf("%lld\n",b-a);

} ./Main.c: In function ‘main’:
./Main.c:4:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%lld %lld %lld %lld",&a,&b,&c,&k);
    ^
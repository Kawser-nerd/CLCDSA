#include <stdio.h>
#include <string.h>
#include<math.h>
int main()
{
    long long n,k,a,b,i,ans=0;
    scanf("%lld%lld",&n,&k);
    if(k==0) printf("%lld\n",n*n);
    else{
    for(b=k+1;b<=n;b++)
    {
        ans+=(n/b)*(b-k);
        if(n%b>=k)
            ans+=n%b-k+1;
    }
    printf("%lld\n",ans);}
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&n,&k);
     ^
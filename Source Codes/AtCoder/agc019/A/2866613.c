#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

long long  smallnumber(long long a, long long b){
    if(a<b){
        return(a);
    } else {
        return(b);
    }
}

int main(void){
    long long q,h,s,d,n;
    scanf("%lld%lld%lld%lld%lld",&q,&h,&s,&d,&n);
    long long ans;
    if (q*4<s){
        s=q*4;
    }
    if (h*2<s){
        s=h*2;
    }
    ans=smallnumber(n*s,(n/2)*d+(n%2)*s);
        
    printf("%lld\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld%lld%lld%lld",&q,&h,&s,&d,&n);
     ^
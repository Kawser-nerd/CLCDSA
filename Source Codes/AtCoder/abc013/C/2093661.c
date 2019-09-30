#include <stdio.h>
#include <stdlib.h>
#define INF 1e18
int main(){
    long long n,h;
    long long a,b,c,d,e;
    scanf("%lld %lld",&n,&h);
    scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&e);
    long long min = INF;
    int i;
    for(i=0;i<=n;i++){
        long long x=i;
        long long y=(n-x)*e-b*x-h;
        //printf("%lld\n",h);
        //printf("%lld %lld %lld %lld %lld / %lld %lld\n",n-x,(n-x)*e,-b*x,(n-x)*e-b*x,(n-x)*e-b*x-h,d+e,((n-x)*e-b*x-h)/(d+e));
        if(y<0){
            y=0;
        }else{
            y=y/(d+e)+1;
        }
        long long m=a*x+c*y;
        if(min>m)min=m;
        if(x*b+h-(e*(n-x))>0)break;
    }
    printf("%lld\n",min);
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld",&n,&h);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&e);
     ^
#include <stdio.h>

long long int min(long long int a,long long int b){
    if(a<b)return a;
    return b;
}

int main(void){
    long long int N,H,A,B,C,D,E;
    scanf("%lld %lld %lld %lld %lld %lld %lld",&N,&H,&A,&B,&C,&D,&E);
    long long int ans=1145148931919810;
    for(long long int i=0;i<=N;i++){//i???????
        long long int kariH=H;
        kariH-=i*E;
        if(kariH+(N-i)*B>0){
            if(kariH+(N-i)*D>0)ans=min((N-i)*C,ans);
            else{
                kariH+=(N-i)*D;
                kariH*=(-1);
                long long int po=1+kariH/(B-D);
                ans=min((po*A+(N-i-po)*C),ans);
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld %lld %lld %lld %lld %lld",&N,&H,&A,&B,&C,&D,&E);
     ^
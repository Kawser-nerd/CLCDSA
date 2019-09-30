#include <stdio.h>

long long sk(long long x){return ((x+1)*x)/2;}

int main(){
    long long n,a[131072],res=0,l=1,i;
    scanf("%lld%lld",&n,&a[1]);
    for(i = 2;i <= n;i++){
        scanf("%lld\n",&a[i]);
        if(a[i-1] < a[i]){l++;}
        else{res+=sk(l);l = 1;}
    }
    res+=sk(l);
    printf("%lld\n",res);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&n,&a[1]);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld\n",&a[i]);
         ^
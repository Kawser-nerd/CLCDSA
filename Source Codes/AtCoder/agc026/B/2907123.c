#include <stdio.h>
long long gcd(long long a,long long b){
    return b ? gcd(b,a % b) : a;
}
int check(long long a,long long b,long long c,long long d){
    if(a < b || d < b)return 0;
    if(c + 1 >= b)return 1;
    long long g = gcd(b,d);
    return (a - c - 1) / g - (a - b) / g <= 0;
}
int main() {
    int t;
    long long a,b,c,d;
    scanf("%d",&t);
    while(t --){
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        if(check(a,b,c,d)){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
} ./Main.c: In function ‘main’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&t);
     ^
./Main.c:16:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
         ^
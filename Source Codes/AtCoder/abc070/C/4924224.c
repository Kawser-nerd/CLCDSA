#include <stdio.h>

long long gcd(long long a, long long b)
{
    long long r=0, t=0;

    if(a<b){
        t=a;
        a=b;
        b=t;
    }
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }

    return a;
}        
long long lcm(long long a, long long b)
{
    return (a*b)/gcd(a, b);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    long long t[n], ans=1, i;
    for(i=0;i<n;i++){
        scanf("%lld", &t[i]);
    }

    for(i=0;i<n;i++){
        ans=t[i]/gcd(t[i], ans)*ans;
    }
    
    printf("%lld\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:31:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld", &t[i]);
         ^
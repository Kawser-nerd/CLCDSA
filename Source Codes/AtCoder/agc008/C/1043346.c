#include<stdio.h>
int count=0;
void check(long long int x){
    if(x%2==1)count++;
}

int main(){
    long long int a,b,c,d,e,f,g;
    scanf("%lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&e,&f,&g);
    long long int ans=0;
    ans+=b;
    check(a);
    check(d);
    check(e);
    if(count<=1){
        ans+=(a/2)*2+(d/2)*2+(e/2)*2;
    }else if(count==2 &&a>0 &&d>0&&e>0){
        ans+=a+d+e-1;
    }else if(count==2){
        ans+=(a/2)*2+(d/2)*2+(e/2)*2;
    }else{
        ans+=a+d+e;
    }
    printf("%lld",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&e,&f,&g);
     ^
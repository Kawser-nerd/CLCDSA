#include <stdio.h>
#include<math.h>
#define ll long long
int main(void){
    ll r,b,x,y;
    ll mid,high,low;
    ll mb,mr;
    scanf("%lld %lld",&r,&b);
    scanf("%lld %lld",&x,&y);
    high=pow(10,18);
    low=0;
    mid=(high+low)/2;
    while(high-low>1){
        mid=(high+low)/2;
        mr=(r-mid)/(x-1);
        mb=(b-mid)/(y-1);
        if(mr+mb>=mid && r>=mid && b>=mid){
            low=mid;
        }else{
            high=mid;
        }
    }
    printf("%lld\n",low);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld",&r,&b);
     ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld",&x,&y);
     ^
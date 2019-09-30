#include <stdio.h>
typedef long long ll;

ll DigitSum(ll b,ll x){
    return x<b?x:DigitSum(b,x/b)+x%b;
}

int main(void){
    ll n,s,ans=-1;
    scanf("%lld%lld",&n,&s);
    if (n<s){
        ans=-1;
    } else if (n==s){
        ans=n+1;
    } else {
        for (ll i=2; i*i<=n; i++){
            if (DigitSum(i,n)==s){
                ans=i;
                break;
            }
        }
        if (ans==-1){
            for (ll i=1; i*i<=n; i++){
                ll b=(n-s)/i+1;
                if ((n-s)%i==0 && DigitSum(b,n)==s){
                    ans=b;
                }
            }
        }
    }
    printf("%lld\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&n,&s);
     ^
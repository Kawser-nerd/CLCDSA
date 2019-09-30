#include<cstdio>
#include<algorithm>
typedef long long ll;
using namespace std;
int main(){
    ll n,h,a,b,c,d,e,ans=5000000000000,x;
    scanf("%lld %lld %lld %lld %lld %lld %lld",&n,&h,&a,&b,&c,&d,&e);
    for(int i=0;i<=n;i++){
        if(h+(n-i)*b-e*i>=0){
            x=e*i-h-(n-i)*d+1;
            if(x<=0){
                ans=min(ans,(n-i)*c);
            }
            else if(x%(b-d)==0){
                ans=min(ans,c*(n-i)+(x/(b-d))*(a-c));
            }
            else{
                ans=min(ans,c*(n-i)+(x/(b-d)+1)*(a-c));
            }
        }
    }
    printf("%lld\n",ans);
}
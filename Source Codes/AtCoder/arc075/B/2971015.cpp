#include <iostream>
using namespace std;
typedef long long ll;
#define MS(a) memset(a,0,sizeof(a))
#define MP make_pair
#define PB push_back
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;
inline ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//////////////////////////////////////////////////////////////////////////
const int maxn = 1e5+10;

ll x[maxn],k[maxn];
ll n,a,b;

bool check(ll t){
    memcpy(k,x,sizeof(x));
    for(ll i=1; i<=n; i++){
        k[i] -= t*b;
    }
    ll more = (a-b),cnt=0;
    for(ll i=1; i<=n; i++){
        if(k[i]>0) cnt += (k[i]%more==0) ? (k[i]/more) : (k[i]/more+1);
    }
    return cnt <= t;
}

int main(){
    cin >> n >> a >> b;
    for(int i=1; i<=n; i++){
        x[i] = read();
    }

    ll ans,L=1,R=1e9;
    while(L<=R){
        ll mid = (L+R)/2;
        if(check(mid)) ans=mid,R=mid-1;
        else L=mid+1;
    }

    cout << ans << endl;


    return 0;
}
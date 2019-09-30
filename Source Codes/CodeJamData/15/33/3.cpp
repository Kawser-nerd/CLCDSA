#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int _,c,d,v,__;
ll a[110];
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d%d",&c,&d,&v);
		rep(i,0,d) scanf("%I64d",a+i);
		a[d]=1ll<<60;
		ll p=0; int r=0,ans=0;
		while (1) {
			if (p+1>=a[r]) {
				p+=a[r]*c;
				r++;
			} else {
				ans++;
				p+=(p+1)*c;
			}
			if (p>=v) break;
		}
		printf("Case #%d: %d\n",++__,ans);
	}
}

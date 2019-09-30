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

int _,r,c,w,__;
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d%d",&r,&c,&w);
		int ans=(c/w)*(r-1);
//		if (c==w||w==1) ans+=c;
		if (c%w==0) ans+=c/w+w-1; else ans+=c/w+w;
		printf("Case #%d: %d\n",++__,ans);
	}
}

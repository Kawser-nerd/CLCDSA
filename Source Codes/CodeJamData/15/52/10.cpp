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

const int N=1100;
int _,n,k,s[N],mx[N],mn[N],__;
ll x[N],y[N];
int main() {
//	freopen("in.txt","r",stdin);
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&n,&k);
		rep(i,1,n-k+2) scanf("%d",s+i);
		rep(i,1,k+1) {
			mx[i]=mn[i]=0;
			int c=0;
			for (int j=i+k;j<=n;j+=k) {
				c+=s[j-k+1]-s[j-k];
				mx[i]=max(mx[i],c);
				mn[i]=min(mn[i],c);
			}
		}
		ll l=-1,r=1ll<<40;
		bool sol=0;
		while (l+1<r) {
			ll md=(l+r)>>1;
			x[1]=0;
			rep(j,2,k+1) x[j]=1ll<<60;
			sol=0;
			rep(R,0,k+2) {
				sol=0;
				rep(i,1,k+1) rep(j,1,k+1) if (x[i]+mx[i]-x[j]-mn[j]>md) {
					x[i]=x[j]+mn[j]+md-mx[i];
					sol=1;
				}
			}
			if (sol==1) { l=md;continue; }
			y[1]=0;
			rep(j,2,k+1) y[j]=-(1ll<<60);
			sol=0;
			rep(R,0,k+2) {
				sol=0;
				rep(i,1,k+1) rep(j,1,k+1) if (y[i]+mx[i]-y[j]-mn[j]>md) {
					y[j]=y[i]+mx[i]-mn[j]-md;
					sol=1;
				}
			}
			if (sol==1) { l=md;continue; }
			rep(j,1,k+1) assert(x[j]>=y[j]);
			assert(x[1]==0&&y[1]==0);
			ll s1=0,s2=0;
			rep(j,1,k+1) s2+=y[j],s1+=x[j];
			s1=s[1]-s1; s2=s[1]-s2; 
			s1+=(1ll<<50)*k,s2+=(1ll<<50)*k;
			assert(0<=s1);
			assert(s1<=s2);
			if ((s1-1)/k!=s2/k) { r=md; continue;}
			else l=md;
		}
		printf("Case #%d: %I64d\n",++__,r);
		fprintf(stderr,"Case #%d: %I64d\n",__,r);
	}
}

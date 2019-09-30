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

const int N=30;
int _,y,n,p[N],s[N],__;
double ans;
void dfs(double t,double pos,int S) {
	if (S==(1<<n)-1) {
		ans=min(ans,t);
	} else {
		int lp=-1,rp=-1; double lt=1e30,rt=1e30; 
		rep(i,0,n) if ((S&(1<<i))==0) {
			if (p[i]>0) {
				double ct=max(0.,(p[i]+t*s[i]-pos)/(y-s[i]));
				if (ct<rt) rt=ct,rp=i;
			} else if (p[i]<0) {
				double ct=max(0.,(pos-(p[i]+t*s[i]))/(y+s[i]));
				if (ct<lt) lt=ct,lp=i;
			}
		}
		if (lp!=-1) dfs(t+lt,pos-lt*y,S|(1<<lp));
		if (rp!=-1) dfs(t+rt,pos+rt*y,S|(1<<rp));
	}
}
int main() {
//	freopen("in.txt","r",stdin);
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&y,&n);
		rep(i,0,n) scanf("%d",p+i);
		rep(i,0,n) {
			scanf("%d",s+i);
			if (p[i]<0) s[i]*=-1;
		}
		ans=1e20;
		dfs(0,0,0);
		printf("Case #%d: %.10f\n",++__,ans);
		fprintf(stderr,"Case #%d: %.10f\n",__,ans);
	}
}

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int _,n,k,__;
double ret,p[210];
long double dp[210][210];
double solve(vector<double> p) {
	dp[0][0]=1;
	rep(i,0,SZ(p)) {
		rep(j,0,i+2) dp[i+1][j]=0;
		rep(j,0,i+1) dp[i+1][j+1]+=dp[i][j]*p[i],dp[i+1][j]+=dp[i][j]*(1-p[i]);
	}
	return dp[k][k/2];
}
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&n,&k);
		rep(i,0,n) scanf("%lf",p+i);
		sort(p,p+n);
		ret=0;
		rep(q,0,k+1) {
			vector<double> vec;
			rep(i,0,q) vec.pb(p[i]);
			rep(i,0,k-q) vec.pb(p[n-i-1]);
			ret=max(ret,solve(vec));
		}
		printf("Case #%d: %.10f\n",++__,ret);
	}
}

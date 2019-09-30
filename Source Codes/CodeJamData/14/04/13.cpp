#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
#include <complex>
using namespace std;
#define rep(i,a,n) for (int i=a;i<(int)n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define ACCU accumulate
#define TWO(x) (1<<(x))
#define TWOL(x) (1ll<<(x))
#define clr(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (0<=(x)&&(x)<n&&0<=(y)&&(y)<m)
#define PRINTC(x) printf("Case #%d: %d\n",++__,x)
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef complex<double> CD;
const int inf=0x20202020;
const ll mod=1000000007;
const double eps=1e-9;
const double pi=3.1415926535897932384626;
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1010;
int _,__;
int n,a[N],b[N],ans,ans2,cp;
VPII vec;
double x;
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		rep(i,0,n) { scanf("%lf",&x);a[i]=x*100000+0.1; }
		rep(i,0,n) { scanf("%lf",&x);b[i]=x*100000+0.1; }
		vec.clear();
		rep(i,0,n) vec.pb(mp(a[i],1));
		rep(i,0,n) vec.pb(mp(b[i],-1));
		sort(all(vec));
		reverse(all(vec));
		ans=0;ans2=0;cp=0;
		rep(i,0,SZ(vec)) {
			cp+=vec[i].se;
			if (cp>0) ans+=cp,cp=0;
		}
		sort(a,a+n);
		sort(b,b+n);
		reverse(b,b+n);
		reverse(all(vec));
		rep(i,0,n) {	
			cp=0;
			bool fg=1;
			rep(j,0,SZ(vec)) {
				cp+=vec[j].se;
				if (cp>0) fg=0;
			}
			if (fg==1) { ans2=n-i; break;}
			for (VPII::iterator it=vec.begin();it!=vec.end();it++) {
				if (*it==mp(a[i],1)) { vec.erase(it); break;}
			}
			for (VPII::iterator it=vec.begin();it!=vec.end();it++) {
				if (*it==mp(b[i],-1)) { vec.erase(it); break;}
			}
		}
		printf("Case #%d: ",++__);
		printf("%d %d\n",ans2,ans);
	}
	
}

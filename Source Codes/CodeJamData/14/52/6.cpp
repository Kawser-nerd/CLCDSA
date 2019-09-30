#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
typedef long long lng;
typedef unsigned long long ulng;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<short, short> PSS;
typedef pair<PII, int> PIII;
typedef pair<lng, lng> PLL;
typedef pair<ulng, ulng> PUU;
typedef pair<lng, int> PLI;
typedef pair<int, lng> PIL;
typedef pair<ld, ld> PDD;
template<class T> inline T sqr(T x) { return x * x; }
template<class T> inline string tostr(const T & x) { stringstream ss; ss << x; return ss.str(); }
inline lng parse(const string & s) { stringstream ss(s); lng x; ss >> x; return x; }
#define left asdleft
#define right asdright
#define link asdlink
//#define unlink asdunlink
#define next asdnext
#define prev asdprev
#define y0 asdy0
#define y1 asdy1
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define X first
#define Y second
#define hash asdhash
#define move asdmove
const ld EPS = 1e-12;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
lng powmod(lng a,lng p,lng m){lng r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
#define TASKA "iota"

int P,Q,N;
vector<int> H,G;
int ans;
int dp[110][1100][2];

void mx(int &a,int b){
	if(b>a)
		a=b;
}

void solve(){
	const int K=accumulate(all(H),0)/20+2;
	forn(k,K+1){
		forn(q,2){
			dp[N][k][q]=0;
		}
	}
	for(int a=N-1;a>=0;--a){
		forn(k,K+1){
			forn(f,2){
				int h=H[a];
				dp[a][k][f]=dp[a+1][min(K,k+(h+Q-1)/Q-f)][0];
				for(int q=0;q*Q<h;++q){
					int p=(h-q*Q+P-1)/P;
					int kk=k + (q+1-f) - p;
					int ff=1;
					if(kk<0)
						continue;
					mx(dp[a][k][f],dp[a+1][kk][ff]+G[a]);
				}
				
				//cout<<a<<' '<<k<<' '<<f<<": "<<dp[a][k][f]<<endl;
			}
		}
	}
	
	ans=dp[0][0][0];
}

void input(){
	cin>>P>>Q>>N;
	H.resize(N);G.resize(N);
	forn(i,N){
		cin>>H[i]>>G[i];
	}
}

void output(){
	cout<<ans<<endl;
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASKA".in", "r", stdin); freopen(TASKA".out", "w", stdout);
#endif
	
	int tc;
	cin>>tc;
	forn(qqq,tc){
		cerr<<qqq<<endl;
		input();
		solve();
		cout<<"Case #"<<qqq+1<<": ";
		output();
	}
	
	return 0;
}

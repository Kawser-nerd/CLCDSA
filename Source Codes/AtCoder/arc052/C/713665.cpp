#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iterator>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <iomanip>
#include <cassert>
//#include <utility>
//#include <memory>
//#include <functional>
//#include <deque>
//#include <cctype>
//#include <ctime>
//#include <numeric>
//#include <list>
//#include <iomanip>

//#if __cplusplus >= 201103L
//#include <array>
//#include <tuple>
//#include <initializer_list>
//#include <forward_list>
//
//#define cauto const auto&
//#else

//#endif

using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >> t;
}

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define F first
#define S second
#define mkp make_pair
#define RALL(v) (v).rbegin(),(v).rend()
#define DEBUG
#ifdef DEBUG
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#else
#define dump(x) 
#define debug(x) 
#endif

#define MOD 1000000007LL
#define EPS 1e-8
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define maxs(x,y) x=max(x,y)
#define mins(x,y) x=min(x,y)

typedef pair<pii,int> P;
int n,m;
vvint vv1;
vvint vv2;
int cnt[10010];
int dp[10010][150];
bool used[10010];
bool used2[10010][150];

void func1(){
	priority_queue<pii> pq;
	rep(i,n) cnt[i] = INF;
	cnt[0] = 0;
	pq.push(pii(0,0));

	while(pq.size()){
		int pos = pq.top().S;
		pq.pop();
		if(used[pos]) continue;
		used[pos] = true;
		for(int x:vv1[pos]){
			if(cnt[x]<=cnt[pos]) continue;
			cnt[x] = cnt[pos];
			pq.push(pii(-cnt[x],x));
		}
		for(int x:vv2[pos]){
			if(cnt[x]<=cnt[pos]+1) continue;
			cnt[x] = cnt[pos]+1;
			pq.push(pii(-cnt[x],x));
		}
	}
}

void func2(){
	priority_queue<P> pq;
	rep(i,n){
		rep(j,150){
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	pq.push(mkp(pii(0,0),0));

	while(pq.size()){
		int x = pq.top().S;
		int r = pq.top().F.S;
		pq.pop();
		if(used2[x][r]) continue;
		used2[x][r] = true;
		for(int y:vv1[x]){
			int r2 = r+cnt[x]-cnt[y];
			if(r2>=150) continue;
			int d = dp[x][r] + 1;
			if(dp[y][r2] <= d) continue;
			dp[y][r2] = d;
			pq.push(mkp(pii(-d,r2),y));
		}
		for(int y:vv2[x]){
			int r2 = r+cnt[x]+1-cnt[y];
			if(r2>=150) continue;
			int d = dp[x][r] + cnt[x]+r+1;
			if(dp[y][r2] <= d) continue;
			dp[y][r2] = d;
			pq.push(mkp(pii(-d,r2),y));
		}
	}
}

void mainmain(){
	cin>>n>>m;
	vv1=vvint(n);
	vv2=vvint(n);
	rep(i,m){
		int c,a,b;
		cin>>c>>a>>b;
		if(!c){
			vv1[a].PB(b);
			vv1[b].PB(a);
		}
		else{
			vv2[a].PB(b);
			vv2[b].PB(a);
		}
	}
	func1();
	func2();
	rep(i,n){
		int ans = INF;
		rep(j,150){
			mins(ans,dp[i][j]);
		}
		cout << ans << endl;
	}
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(20);
    mainmain();
}
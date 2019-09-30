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

void mainmain(){
	int n,m;
	cin>>n>>m;
	vvint vv1(n);
	vvint vv2(n);
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
	vint dp(n,INF);
	queue<int> q;
	q.push(0);
	dp[0] = 0;
	rep(i,n){
		int qs=q.size();
		if(!qs) break;
		rep(j,qs){
			int x = q.front();
			q.pop();
			for(int y:vv1[x]){
				if(dp[y]!=INF) continue;
				dp[y] = i+1;
				q.push(y);
			}
		}
	}
	while(q.size()) q.pop();
	vector<pii> v;
	rep(i,n){
		if(dp[i]==INF) continue;
		v.PB(pii(i,dp[i]));
	}
	reep(i,1,n+1){
		for(auto x:v){
			for(int y:vv2[x.F]){
				if(dp[y]<=x.S+i) continue;
				q.push(y);
				dp[y]=x.S+i;
			}
		}
		v.clear();
		while(q.size()){
			int top = q.front();
			q.pop();
			v.PB(pii(top,dp[top]));
			for(int y:vv1[top]){
				if(dp[y]<=dp[top]+1) continue;
				q.push(y);
				dp[y]=dp[top]+1;
			}
		}
	}
	rep(i,n) cout<<dp[i]<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(20);
    mainmain();
}
#include <iostream>
#include <vector>
#include <algorithm>
// statics
using namespace std;
using int64 = int_fast64_t;
using PAIR = pair<int64, int64>;
constexpr int INF = 1 << 30;
constexpr int64 LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 3e5 + 1;

// init/input
#define int int64
#define INIT ios::sync_with_stdio(false);cin.tie(0);
#define VAR(type, ...) type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T &t) {cin>>t;}
template<typename First, typename...Rest> void MACRO_VAR_Scan(First &first, Rest&...rest) {cin>>first;MACRO_VAR_Scan(rest...);}
#define VEC(type, c, n) vector<type> c(n);for(auto &&i:c)cin>>i;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

// out
#define OUT(dist) cout<<(dist);
#define FOUT(n, dist) cout<<fixed<<setprecision(n)<<(dist);
#define SP cout<<" ";
#define BR cout<<endl;
#define zero(n) cout<<setfill('0')<<right<<setw(n)
#define debug(x) cerr<<#x<<":"<< (x);BR;

// utility
#define ALL(a) (a).begin(), (a).end()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=0;--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

signed main() {
  INIT;
	VAR(int,n,k);
	VEC(int,a,n);

	vector<int> sm(n+1,0);
	vector<int> po_sm(n+1,0);
	REP(i,n){
		sm[i+1] = sm[i] + a[i];
		po_sm[i+1] = po_sm[i] + std::max(0L, a[i]);
	}

	int ans = 0;
	REP(i,n){
		int tmp = 0;
		if (i+k>n) break;
		tmp += std::max((sm[i+k] - sm[i]), 0L);
		debug(tmp);
		tmp += po_sm[i];
		tmp += po_sm[n] - po_sm[i+k];
		debug(i);
		debug(tmp);
	  ans = std::max(ans,tmp);
	}
	OUT(ans)BR;

	
  
  return 0;
}
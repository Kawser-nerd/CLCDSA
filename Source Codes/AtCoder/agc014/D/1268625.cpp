#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ull unsigned long long
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

#define MOD 1000000007LL
#define INF (1LL<<60)


/*
????????????????????
*/

ll N;

string solve1(VVI& g) {
	string ans = "Second";
	while(1) {
		REP(i, N) {
			int cnt=0;
			for(int j : g[i]) {
				if(g[j].size()==1) cnt++;
			}
			if(cnt>=2) {
				return "First";
			}
		}

		// i - adj - X =... -> X =...
		bool ch=false;
		REP(i, N) {
			if(g[i].size()==1) {
				int adj = g[i][0];
				if(g[adj].size()==2) {
					int X = g[adj][0]==i ? g[adj][1] : g[adj][0];
					{
						auto en = remove_if(ALL(g[X]), [=](int a) { return adj==a; });
						g[X].erase(en, g[X].end());
					}
					g[adj].clear();
					g[i].clear();
					ch=true;
				}
			}
		}
		if(!ch) break;
	}
	return ans;
}

// ????????????????????????
int dfs(int u, int p, VVI& G) {
	int x = 0;
	int ch=0;
	for (int v: G[u]) if (v != p) {
		ch++;
		x += dfs(v, u, G);
	}
	if(ch==0) return 1; // need to match ... ?
	if(x==0) return 1; // need to match ... ????????????
	if(x<=1) return 0; // matched
	return x;
}

string solve2(VVI& g) {
	int rest = dfs(0, -1, g);
	string ans = rest ? "First" : "Second";
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	string s;
	while(cin>>N) {
		VVI g(N);
		REP(i, N-1) {
			ll A, B;
			cin>>A>>B;
			A--;B--;
//			bm.add_edge(A, B);
//			DD(A);DD(N+B);
//			DD(A);DD(B);
			g[A].PB(B);
			g[B].PB(A);
		}
//		DD(g);
//		DD(N);

		string ans = solve1(g);
//		string ans = solve2(g);


		cout<<ans<<endl;
	}
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;
using LL = long long;
using VL = vector<LL>;
using VVL = vector<VL>;
using PLL = pair<LL, LL>;
using VS = vector<string>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}
template<class S, class T>
ostream& operator<<(ostream& os, const pair<S,T>& p){
  return os << p.FF << " " << p.SS;
}
template<class T>
void maxi(T& x, T y){
  if(x < y) x = y;
}
template<class T>
void mini(T& x, T y){
  if(x > y) x = y;
}


const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;
const int MAX = 24*60;
const int INF = 1e9;

int dp[MAX][MAX][2];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  FOR(t,1,T+1){
	int C, J; cin >> C >> J;
	VI cont(MAX);
	REP(i,C){
	  int a, b;
	  cin >> a >> b;
	  FOR(j,a,b) cont[j] = 1; // -> must be 0
	}
	REP(i,J){
	  int a, b;
	  cin >> a >> b;
	  FOR(j,a,b) cont[j] = 2; // -> must be 1
	}

	int ans = INF;
	if(cont[0] != 2){
	  fill((int*)dp, (int*)dp+MAX*MAX*2, INF);
	  dp[0][MAX/2-1][0] = 0;
	  for(int i=1;i<MAX;++i){
		for(int j=0;j<MAX/2;++j){
		  if(cont[i] != 2 && j)
			dp[i][j-1][0] = min(dp[i-1][j][0], dp[i-1][j][1] + 1);
		  if(cont[i] != 1)
			dp[i][j][1] = min(dp[i-1][j][1], dp[i-1][j][0] + 1);
		}
	  }
	  ans = min(dp[MAX-1][0][0], dp[MAX-1][0][1] + 1);
	}
	
	if(cont[0] != 1){
	  fill((int*)dp, (int*)dp+MAX*MAX*2, INF);
	  dp[0][MAX/2-1][1] = 0;
	  for(int i=1;i<MAX;++i){
		for(int j=0;j<MAX/2;++j){
		  if(cont[i] != 2)
			dp[i][j][0] = min(dp[i-1][j][0], dp[i-1][j][1] + 1);
		  if(cont[i] != 1 && j)
			dp[i][j-1][1] = min(dp[i-1][j][1], dp[i-1][j][0] + 1);
		}
	  }
	  mini(ans, min(dp[MAX-1][0][1], dp[MAX-1][0][0] + 1));
	}

	cout << "Case #" << t << ": " << ans << endl;
  }
  
  return 0;
}

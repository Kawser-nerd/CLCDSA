#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C& _a4, C _b4) { _a4 = min(_a4, _b4); }
template<class C> void maxi(C& _a4, C _b4) { _a4 = max(_a4, _b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto& vv : V) os << vv << ","; os << "]";
  return os;
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

#define MAX 10010
int32_t dp[MAX][MAX],dp2[MAX][MAX],dp3[MAX][MAX];
const int P = 1e9 + 7;
struct Sol{


void run(int cas){
  cout << "Case #" << cas << ": ";
  int n,k;
  cin >> n >> k;
  cout << dp[n-1][k-1] << "\n";
}

};
int pot(int a,int w){
  int r = 1;
  while(w){
    if(w&1)r = r * a % P;
    w/=2;
    a = a * a % P;
  }
  return r;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
  for(int i = 1; i < MAX;i++){
    int odw = pot(i, P - 2);
    R(j,i+1){
      dp[i][j] = dp2[i-2][j];
      if(j >= 2) dp[i][j] += dp3[i-2][j-2];
      if(j)dp[i][j]++;
      if(j!=i)dp[i][j]++;
      dp[i][j] %= P;
      dp[i][j] = dp[i][j] * odw % P;
      dp[i][j] %= P;
      dp2[i][j] = (dp[i][j] + dp2[i-1][j]) % P;
      if(j)
        dp3[i][j] = (dp[i][j] + dp3[i-1][j-1]) % P;
      else
        dp3[i][j] = dp[i][j];
 //     debug(i,j,dp[i][j]);
    }
  }
  
  int t;cin >> t;
  for(int i=1;i<=t;i++){
    Sol sol;
    sol.run(i);
  }
}

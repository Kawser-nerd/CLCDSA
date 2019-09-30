#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
#define R(i,n) REP(i,n)
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>
#define LD long double

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream &os, vector<T> V){
  os<<"[";for(auto vv:V)os<<vv<<",";return os<<"]";
} 

template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}


#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int DayHours = 24 * 60;

struct Testcase {
  vector<bool> availA, availB;
  vector<vector<PII>> dp;

  void readAvail(int sz, vector<bool> &avail) {
    fill(ALL(avail), true);
    for (int i = 0; i < sz; i++) {
      int from, to;
      cin >> from >> to;
      for (int t = from; t < to; t++) { avail[t] = false; }
    }
  }
  
  void run(int tid) {
    availA.resize(DayHours);
    availB = availA;
    int K, L;
    cin >> K >> L;
    readAvail(K, availA);
    readAvail(L, availB);

    dp.resize(DayHours + 1, vector<PII>(DayHours + 1, PII(1e9, 1e9)));
    dp[0][0] = PII(0, 0);
    
    for (int tm = 1; tm <= DayHours; tm++) {
      bool canA = availA[tm - 1],
           canB = availB[tm - 1];

      for (int prevA = 0; prevA < tm; prevA++) {
        if (canA) {
          mini(dp[tm][prevA + 1].st, dp[tm - 1][prevA].st);
          mini(dp[tm][prevA + 1].st, dp[tm - 1][prevA].nd + 1);
        }
        if (canB) {
          mini(dp[tm][prevA].nd, dp[tm - 1][prevA].st + 1);
          mini(dp[tm][prevA].nd, dp[tm - 1][prevA].nd);
        }
      }
    }

    int result = min(dp[DayHours][DayHours / 2].st,
                     dp[DayHours][DayHours / 2].nd);
    if (result % 2 == 1) { result++; }

    cout << "Case #" << tid << ": " << result << "\n";
  }
};



int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    Testcase tc;
    tc.run(i);
  }
}

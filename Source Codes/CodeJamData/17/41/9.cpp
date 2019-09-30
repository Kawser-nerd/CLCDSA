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


const int MaxN = 101;


int dp[MaxN][MaxN][MaxN][MaxN][4];

struct Testcase {
  int N, P;
  vector<int> cnt;



  void run(int tid) {
    cout << "Case #" << tid << ": ";
    cin >> N >> P;
    cnt.resize(P);
    int tot = 0;
    for (int i = 0; i < N; i++) {
      int v; cin >> v;
      cnt[v % P]++;
      tot += v;
    }
    tot %= P;

    REP (a, cnt[0] + 1) REP (b, cnt[1] + 1) REP (c, cnt[2] + 1) REP (d, cnt[3] + 1) {
      REP (p, P) {
        dp[a][b][c][d][p] = -1e9;
      }
    }
    dp[0][0][0][0][0] = 0;

    cnt.resize(4);

    int cur[4], nxt[4];

    for (cur[0] = 0; cur[0] <= cnt[0]; cur[0]++) {
      for (cur[1] = 0; cur[1] <= cnt[1]; cur[1]++) {
        for (cur[2] = 0; cur[2] <= cnt[2]; cur[2]++) {
          for (cur[3] = 0; cur[3] <= cnt[3]; cur[3]++) {
            for (int r = 0; r < P; r++) {
              for (int i = 0; i < P; i++) {
                if (cur[i] == 0) { continue; }
                REP (i, 4) nxt[i] = cur[i];
                nxt[i]--;
                int nxtres = dp[nxt[0]][nxt[1]][nxt[2]][nxt[3]][(r + P - i) % P] + (r == i);
                maxi(dp[cur[0]][cur[1]][cur[2]][cur[3]][r], nxtres);
              }
            }
          }
        }
      }
    }
    cout << dp[cnt[0]][cnt[1]][cnt[2]][cnt[3]][tot] << "\n";
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

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


const LD kPi = 2 * acos(0);

struct Testcase {
  int N, K;
  vector<PII> pancakes;

  void run(int tid) {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
      int r, h;
      cin >> r >> h;
      pancakes.emplace_back(r, h);
    }

    sort(ALL(pancakes), greater<PII>());

    LD result = 0;

    for (int minPan = 0; minPan + K <= N; minPan++) {
      auto &MP = pancakes[minPan];
      debug(MP);
      LD base = kPi * MP.first * MP.first;

      vector<LD> side;
      for (int i = minPan; i < N; i++) {
        side.push_back(2 * kPi * pancakes[i].first * pancakes[i].second);
      }

      base += side[0];
      sort(side.begin() + 1, side.end());
      for (int i = 0; i < K - 1; i++) {
        base += *(side.rbegin() + i);
      }

      maxi(result, base);
    }

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

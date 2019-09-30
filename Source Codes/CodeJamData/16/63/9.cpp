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

LD res[301][301];
LD eps = 1e-9;
struct Sol{

void run(int cas){
  cout << "Case #" << cas << ": ";
  int n,r;
  cin >> n >> r;
  int out = 0;
  debug(r / 5e5);
  R(i,n)R(j,n){
    if(res[i][j] > r / 1e6 + eps)out ++;
  }
  cout << out << "\n";
}

};

LD kw(LD a){
  return a * a;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  R(i,301)R(j,301){
    if(i + j == 0)continue;
    res[i][j] = 2;
   // debug(i,j);
    LD pom = 1/ sqrt(kw(i) + kw(j));
    R(ii,i+1)R(jj,j+1){
      if(ii + jj == 0 || (ii == i && jj == j)) continue;
      mini(res[i][j], (LD)abs(ii * j - jj * i) * pom );
    }
  }
  R(i,5){
    R(j,5)
      cerr << res[i][j] << " ";
    cerr << "\n";
  }
  int t;cin >> t;
  for(int i=1;i<=t;i++){
    Sol sol;
    sol.run(i);
  }
}

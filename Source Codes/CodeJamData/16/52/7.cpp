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

struct Sol{
  int n,m;
  vector<vector<int>> d;
  string z,zap[6];
  vector<int> il;
  vector<int> oj;
  vector<int> res;
  void dodaj(int a){
    debug(a);
    int pocz = 0;
    if(oj[a] != -1){
      R(i,SZ(res)){
        if(res[i] == oj[a]){
          pocz = i+1;
          break;
        }
      }
    }
    debug(pocz);
    int gd = pocz + rand() % (SZ(res) + 1 - pocz);
    res.PB(0);
    for(int i = SZ(res)-1; i != gd; i--){
      res[i] = res[i-1];
    }
    res[gd] = a;
  }
  string wyn;
  vector<int> splec(vector<int> &a, vector<int> b){
    int i = 0;
    int j = 0;
    vector<int> res;
    while(i < SZ(a) || j < SZ(b)){
      int pom = rand() % (SZ(a) - i + SZ(b) - j);
      if(pom < SZ(a) - i){
        res.PB(a[i]);
        i++;
      }else{
        res.PB(b[j]);
        j++;
      }
    }
    return res;
  }
  vector<int> dfs(int v){
    vector<int> res;
    for(int ak:d[v]){
      res = splec(res, dfs(ak));
    }
    if(v!=n){
      res.PB(v);
    }
    return res;
  }
  string generuj(){
    res = dfs(n);
    reverse(ALL(res));
    wyn.resize(n);
    R(i,n){
      wyn[i] = z[res[i]];
    }
    return wyn;
  }
  
  bool spr(string& k){
    R(i,n-SZ(k)+1){
      R(j,SZ(k)){
        if(wyn[i + j] != k[j])goto nie;
      }
      return 1;
      nie:;
    }
    return 0;
  }
  void go(int cas){
    debug(cas);
    cout << "Case #" << cas << ": ";
    cin >> n;
    d.resize(n+1);
    oj.resize(n);
    R(i,n){
      cin >> oj[i];
      oj[i]--;
      if(oj[i] != -1)
        d[oj[i]].PB(i);
      else
        d[n].PB(i);
    }
    cin >> z >> m;
    R(i,m)cin >> zap[i];
    il.resize(m,0);
    R(i,5000){
      generuj();
    //  debug(wyn);
      R(i,m){
        if(spr(zap[i])){
          il[i]++;
        }
      }
    }
    R(i,m){
      cout << il[i] / 5000. << " ";
    }
    cout << "\n";
  }
};

int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(11);
  int t;  
  cin >> t;
  R(i,t){
    Sol sol;
    sol.go(i+1);
  }
}


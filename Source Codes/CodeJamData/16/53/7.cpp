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

struct pkt{
  int x,y,z;
};
LD kw(LD a){
  return a * a;
}
LD odl(pkt a, pkt b){
  return sqrt(kw(a.x - b.x) + kw(a.y - b.y) + kw(a.z - b.z));
}

struct Sol{
  int n,s;
  vector<pkt> t;
  vector<int> f;
  int find(int nr){
    return f[nr] == nr ? nr : f[nr] = find(f[nr]);
  }
  void uni(int a,int b){
    debug(a,b);
    f[find(a)] = find(b);
  }
  void go(int cas){
    cout << "Case #" << cas << ": ";
    cin >> n >> s;
    t.resize(n);
    f.resize(n);
    R(i,n){
      f[i] = i;
      cin >> t[i].x >> t[i].y >> t[i].z;
      int smiec;
      cin >> smiec >> smiec >> smiec;
    }
    vector<pair<LD, PII>> x;
    R(i,n)R(j,i){
      x.PB({odl(t[i],t[j]),{i,j}});
    }
    sort(ALL(x));
    for(auto el:x){
      uni(el.SE.FI, el.SE.SE);
      if(find(0) == find(1)){
        cout << el.FI << endl;
        return;
      }
    }
    
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


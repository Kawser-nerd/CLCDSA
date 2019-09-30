#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define st first
#define nd second
#define rd third
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define cerr if(0)cout
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
#define next ____next
#define prev ____prev
#define left ____left
#define hash ____hash
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
template<class A, class B, class C> struct Triple { A first; B second; C third;
  bool operator<(const Triple& t) const { if (st != t.st) return st < t.st; if (nd != t.nd) return nd < t.nd; return rd < t.rd; } };
template<class T> void ResizeVec(T&, vector<int>) {}
template<class T> void ResizeVec(vector<T>& vec, vector<int> sz) {
  vec.resize(sz[0]); sz.erase(sz.begin()); if (sz.empty()) { return; }
  for (T& v : vec) { ResizeVec(v, sz); }
}
typedef Triple<int, int, int> TIII;
template<class A, class B, class C>
ostream& operator<< (ostream &out, Triple<A, B, C> t) { return out << "(" << t.st << ", " << t.nd << ", " << t.rd << ")"; }
template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

struct Sol {
  VI vis;
  VVI slo;
  int n;
  PII Dfs(int v) {
    PII cnt;
    if (v <= n) {
      cnt.st++;
    } else {
      cnt.nd++;
    }
    vis[v] = 1;
    for (auto nei : slo[v]) {
      if (vis[nei]) { continue; }
      PII a = Dfs(nei);
      cnt.st += a.st;
      cnt.nd += a.nd;
    }
    return cnt;
  }
  void Test(int t) {
    cout<<"Case #"<<t<<": ";
    cin>>n;
    slo.resize(2 * n + 2);
    vis.resize(2 * n + 2);
    int cnt_e = 0;
    RE (i, n) {
      RE (j, n) {
        char c;
        cin>>c;
        if (c == '1') {
          slo[i].PB(n + j);
          slo[n + j].PB(i);
          cnt_e++;
        }
      }
    }
    VPII ps;
    int alone_left = 0, alone_right = 0;
    int good_pairs = 0;
    RE (i, 2 * n) {
      if (!vis[i]) {
        auto p = Dfs(i);
        debug(p);
        if (p == PII{1, 0}) {
          alone_left++;
        } else if (p == PII{0, 1}) {
          alone_right++;
        } else if (p == PII{1, 1}) {
          good_pairs++;
        } else {
          ps.PB(p);
        }
      }
    }
    debug(ps);
    int k = SZ(ps);
    vector<vector<vector<int>>> best(1 << k, VVI(n + 1, VI(n + 1, n * n)));
    best[0][alone_left][alone_right] = 0;
    REP (sup, 1 << k) {
      if (sup == 0) { continue; }
      FOR (al_l, 0, alone_left) {
        FOR (al_r, 0, alone_right) {
          for (int sub = sup; sub; sub = ((sub - 1) & sup)) {
            int l = 0, r = 0;
            REP (bit, k) {
              if ((1 << bit) & sub) {
                l += ps[bit].st;
                r += ps[bit].nd;
              }
            }
            int need_left = max(0, r - l);
            int need_right = max(0, l - r);
            if (al_l >= need_left && al_r >= need_right) {
              mini(best[sup][al_l - need_left][al_r - need_right], max(l, r) * max(l, r) + best[sup - sub][al_l][al_r]);
            }
          }
        }
      }
    }
    int b = n * n;
    FOR (al_l, 0, alone_left) {
      mini(b, best[(1 << k) - 1][al_l][al_l] + al_l);
    }
    cout<<b + good_pairs - cnt_e<<endl;
  }     
};

    
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int T;
  cin>>T;
  RE (t, T) {
    Sol sol;
    sol.Test(t);
  }
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}

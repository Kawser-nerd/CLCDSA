#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define int long long
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

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
const int kInf = 1e9;
typedef pair<int8_t, int8_t> P8;
struct Sol {
  void Test(int t) {
    cout<<"Case #"<<t<<": ";
    int R, C, m;
    cin>>C>>R>>m;
    vector<PII> wh_sol;
    vector<PII> wh_tur;
    vector<vector<char>> board;
    ResizeVec(board, {R + 5, C + 5});
    RE (i, R) {
      RE (j, C) {
        cin>>board[i][j];
        if (board[i][j] == 'S') {
          wh_sol.PB({i, j});
        }
        if (board[i][j] == 'T') {
          wh_tur.PB({i, j});
        }
      }
    }
    int S = SZ(wh_sol), T = SZ(wh_tur);
    vector<pair<int8_t, int8_t>> can(1 << (S + T), {-1, -1});
    can[0] = {0, 0};
    auto InBoard = [&](int r, int c) {
      return r > 0 && c > 0 && r <= R && c <= C;
    };
    vector<VI> dis;
    ResizeVec(dis, {R + 5, C + 5});
    vector<VVI> seen_by;
    ResizeVec(seen_by, {R + 5, C + 5});
    REP (mask, (1 << (S + T))) {
      if (can[mask] == pair<int8_t, int8_t>{-1, -1}) { continue; }
      RE (r, R) {
        RE (c, C) {
          seen_by[r][c].clear();
        }
      }
      FOR (bit, S, S + T - 1) {
        if (mask & (1 << bit)) { continue; }
        int tur = bit - S;
        REP (dir, 4) {
          int r = wh_tur[tur].st, c = wh_tur[tur].nd;
          while (1) {
            r += dr[dir];
            c += dc[dir];
            if (!InBoard(r, c) || board[r][c] == '#') { break; }
            seen_by[r][c].PB(tur);
          }
        }
      }
      REP (bit, S) {
        if (mask & (1 << bit)) { continue; }
        RE (r, R) {
          RE (c, C) {
            dis[r][c] = kInf;
          }
        }
        int sr = wh_sol[bit].st, sc = wh_sol[bit].nd;
        VPII que{{sr, sc}};
        dis[sr][sc] = 0;
        set<int> can_kill;
        for (int ii = 0; ii < SZ(que); ii++) {
          int r = que[ii].st, c = que[ii].nd;
          if (!seen_by[r][c].empty()) {
            for (auto tur : seen_by[r][c]) {
              can_kill.insert(tur);
            }
            continue;
          }
          if (dis[r][c] == m) { continue; }
          REP (dir, 4) {
            int nr = r + dr[dir], nc = c + dc[dir];
            if (!InBoard(nr, nc)) { continue; }
            if (board[nr][nc] == '#') { continue; }
            if (dis[nr][nc] == kInf) {
              dis[nr][nc] = dis[r][c] + 1;
              que.PB({nr, nc});
            }
          }
        }
        for (auto tur : can_kill) {
          if (mask == 0) { debug(bit, tur); }
          can[mask | (1 << bit) | (1 << (S + tur))] = {bit, tur};
        }
      }
    }
    int best_mask = 0;
    REP (mask, 1 << (S + T)) {
      if (can[mask] != P8{-1, -1} && __builtin_popcount(mask) > __builtin_popcount(best_mask)) {
        best_mask = mask;
      }
    }
    debug(best_mask);
    cout<<__builtin_popcount(best_mask) / 2<<"\n";
    VPII res;
    while (best_mask) {
      if (best_mask != 1) { debug(best_mask); }
      res.PB(can[best_mask]);
      best_mask -= (1 << can[best_mask].st) + (1 << (S + can[best_mask].nd));
    }
    reverse(ALL(res));
    for (auto x : res) {
      cout<<x.st + 1<<" "<<x.nd + 1<<"\n";
    }
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

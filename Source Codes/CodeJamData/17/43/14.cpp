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
#define R(i, n) for(int i = 0;i <(n); ++i)
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

struct SAT{
  int n,io;
  vector<int> o, cz, co;
  vector<vector<int>> d;
  SAT(int _n):n(_n), io(0){
    o.resize(2*n); d.resize(2*n);
    cz.resize(2*n); co.resize(2*n);
  }
  void dfs(int nr){
    if(cz[nr])return;
    cz[nr]=1;
    for(int ak:d[nr]) dfs(ak);
    o[io++]=nr;
  }
  bool dfs2(int nr){
    if(!cz[nr])
      return !co[nr];
    cz[nr]=0; co[nr]=1;
    for(int ak:d[nr])
      if(dfs2(ak))
        return 1;
    return 0;
  }
  vector<bool> licz(){
    R(i,2*n) if(!cz[i]) dfs(i);
    while(io--){
      if(cz[o[io]]){
        cz[o[io]] = co[o[io]] = 0;
        if(dfs2(o[io]^1)) return {};
      }
    }
    R(i,n) if(co[i*2] == co[i*2+1]) return {};
    vector<bool> res; R(i,n) res.PB(co[i*2]);
    return res;
  }
  void add(int a,bool nega,int b,bool negb){
    a *= 2; a += nega; b *= 2; b += negb;
    d[a^1].PB(b); d[b^1].PB(a);
  }
};

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

struct Sol {
  void Test(int t) {
    cout<<"Case #"<<t<<": ";
    int R, C;
    cin>>R>>C;
    SAT sat(R * C + 2);
    vector<vector<char>> board(R + 5, vector<char>(C + 5));
    VVI empty_ind, vars;
    ResizeVec(empty_ind, {R + 5, C + 5});
    vars = empty_ind;
    int nxt_empty = 1;
    RE (i, R) {
      RE (j, C) {
        cin>>board[i][j];
        if (board[i][j] == '.') {
          empty_ind[i][j] = nxt_empty;
          nxt_empty++;
        }
      }
    }
    int cnt_empty = nxt_empty - 1;
    auto InBoard = [&](int r, int c) {
      return r > 0 && c > 0 && r <= R && c <= C;
    };
    int nxt_var = 1;
    vector<VPII> can_help(R * C + 5);
    RE (i, R) {
      RE (j, C) {
        if (board[i][j] == '-' || board[i][j] == '|') {
          REP (tr, 2) {
            VI start_dir;
            if (tr == 0) {
              start_dir = {1, 3};
            } else {
              start_dir = {0, 2};
            }
            bool fail = false;
            for (auto dir : start_dir) {
              int r = i, c = j;
              while (1) {
                r += dr[dir];
                c += dc[dir];
                if (!InBoard(r, c)) {
                  break;
                }
                if (board[r][c] == '-' || board[r][c] == '|') {
                  fail = true;
                  break;
                }
                if (board[r][c] == '#') {
                  break;
                }
                if (board[r][c] == '/') {
                  dir ^= 1;
                  continue;
                }
                if (board[r][c] == '\\') {
                  dir ^= 3;
                  continue;
                }
                //debug(r, c, board[r][c]);
                assert(empty_ind[r][c] != 0);
                can_help[empty_ind[r][c]].PB({nxt_var, tr});
              }
            }
            if (fail) {
              sat.add(nxt_var, tr ^ 1, nxt_var, tr ^ 1);
            }
          }
          nxt_var++;          
        }
      }
    }
    bool fail = false;
    RE (i, cnt_empty) {
      if (SZ(can_help[i]) == 0) {
        fail = true;
      } else {
        if (SZ(can_help[i]) == 1) {
          can_help[i].PB(can_help[i][0]);
        }
        sat.add(can_help[i][0].st, can_help[i][0].nd, can_help[i][1].st, can_help[i][1].nd);
      }
    }
    vector<bool> solution = sat.licz();
    if (fail || solution.empty()) {
      cout<<"IMPOSSIBLE\n";
    } else {
      cout<<"POSSIBLE\n";
      nxt_var = 1;
      RE (i, R) {
        RE (j, C) {
          if (board[i][j] != '-' && board[i][j] != '|') {
            cout<<board[i][j];
          } else {
            if (solution[nxt_var]) {
              cout<<"-";
            } else {
              cout<<"|";
            }
            nxt_var++;
          }
        }
        cout<<"\n";
      }
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

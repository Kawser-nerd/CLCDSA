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

void Del(VI& v, int a) {
  v.erase(find(ALL(v), a));
}

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

struct Sol {
  void Test(int t) {
    cout<<"Case #"<<t<<":"<<endl;
    int n, m;
    cin>>n>>m;
    vector<int> cur;
    RE (i, 2 * (n + m)) {
      cur.PB(i);
    }
    set<PII> ps;
    RE (i, n + m) {
      int a, b;
      cin>>a>>b;
      ps.insert({a, b});
    }
    
    VVI board(n + 2, VI(m + 2));
    VVI val = board;
    VPII wh(2 * (n + m) + 2);
    RE (i, m) {
      int c = i;
      int r = 0;
      wh[i] = {r, c};
      val[r][c] = i;
      c = m + 1 - i;
      r = n + 1;
      wh[i + n + m] = {r, c};
      val[r][c] = i + n + m;
    }
    RE (i, n) {
      int r = i;
      int c = m + 1;
      wh[i + m] = {r, c};
      val[r][c] = i + m;
      c = 0;
      r = n + 1 - i;
      wh[i + 2 * m + n] = {r, c};
      val[r][c] = i + 2 * m + n;
    }
    cerr<<endl;
    FOR (i, 0, n + 1) {
      FOR (j, 0, m + 1) {
        cerr<<val[i][j]<<" ";
        if (val[i][j] < 10) {
          cerr<<" ";
        }
        if (val[i][j]) {
          assert(wh[val[i][j]] == MP(i, j));
        }
      }
      cerr<<endl;
    }
    while (SZ(cur)) {
      bool found = false;
      REP (ii, SZ(cur)) {
        int a = cur[ii];
        int b = cur[(ii + 1) % SZ(cur)];
        if (ps.count({a, b}) || ps.count({b, a})) {
          found = true;
          int r, c, dir;
          r = wh[a].st;
          c = wh[a].nd;
          if (a <= m) {
            dir = 2;
          } else if (a <= n + m) {
            dir = 3;
          } else if (a <= n + 2 * m) {
            dir = 0;
          } else {
            dir = 1;
          }
          debug(a, b);
          //debug(r, c);
          r += dr[dir];
          c += dc[dir];
          auto OnBoard = [&](int i, int j) {
            return i >= 1 && i <= n && j >= 1 && j <= m;
          };
          //debug(r, c);
          assert(OnBoard(r, c));
          while (OnBoard(r, c)) {
            if (board[r][c]) {
              dir ^= board[r][c];
            } else {
              int ndir = (dir + 3) % 4;
              board[r][c] = (ndir ^ dir);
              dir = ndir;
            }
            r += dr[dir];
            c += dc[dir];
          }
          if (val[r][c] != b) {
            cout<<"IMPOSSIBLE"<<endl;
            return;
          }
          Del(cur, a);
          Del(cur, b);
          break;
        }
      }
      if (!found) {
        cout<<"IMPOSSIBLE"<<endl;
        return;
      }
    }
    RE (i, n) {
      RE (j, m) {    
        if (board[i][j] == 3) {
          cout<<'\\';
        } else {
          cout<<'/';
        }
      }
      cout<<endl;
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
  
//   VI v {5, 11, 9};
//   Del(v, 11);
//   debug(v);
  int T;
  cin>>T;
  RE (t, T) {
    Sol sol;
    sol.Test(t);
  }
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}

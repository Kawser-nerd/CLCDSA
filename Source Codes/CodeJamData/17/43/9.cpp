#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
//#define int LL
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


const int DirsR[] = {0, -1, 0, 1},
          DirsC[] = {1, 0, -1, 0};

struct Testcase {
  vector<string> board;
  int H, W;
  vector<vector<vector<pair<int, bool>>>> covers;
  vector<pair<int, bool>> forbidden;
  vector<VI> beamIds;
  pair<int, bool> curBeam;
  
  bool inBoard(int r, int c) {
    return 0 <= r && r < H && 0 <= c && c < W;
  }
  
  void track(int r, int c, int dir) {
    int nr = r + DirsR[dir],
        nc = c + DirsC[dir];
    if (!inBoard(nr, nc)) { return; }
    
    switch (board[nr][nc]) {
      case '-':
      case '|':
        forbidden.PB(curBeam);
        forbidden.emplace_back(beamIds[nr][nc], dir % 2 == 0);
        return;
        
      case '.':
        covers[nr][nc].PB(curBeam);
        break;
        
      case '#':
        return;
        
      case '/':
        dir ^= 1;
        break;
        
      case '\\':
        dir ^= 3;
        break;
    }
    
    track(nr, nc, dir);
  }
  
  void run(int tid) {
    cin >> H >> W;
    board.resize(H);
    for (int i = 0; i < H; i++) {
      cin >> board[i];
    }
    
    beamIds.resize(H, VI(W));
    covers.resize(H, vector<vector<pair<int, bool>>>(W));
    int idBeam = 0;
    REP (i, H) REP (j, W) {
      if (board[i][j] == '-' || board[i][j] == '|') { beamIds[i][j] = idBeam++; }
    }
    
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (board[i][j] == '-' || board[i][j] == '|') {
          curBeam = make_pair(beamIds[i][j], true);
          track(i, j, 0);
          track(i, j, 2);
          curBeam = make_pair(beamIds[i][j], false);
          track(i, j, 1);
          track(i, j, 3);
          idBeam++;
        }
      }
    }
    
    SAT sat(idBeam);
    
    for (auto P : forbidden) {
      int id = P.first;
      bool dir = P.second;
      sat.add(id, dir, id, dir);
    }
    
    
    cout << "Case #" << tid << ": ";
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (board[i][j] == '.') {
          switch (SZ(covers[i][j])) {
            case 0:
              cout << "IMPOSSIBLE\n";
              return;
              
            case 1: {
              auto A = covers[i][j][0];
              sat.add(A.st, !A.nd, A.st, !A.nd);
              break;
            }
            
            case 2: {
              auto A = covers[i][j][0], B = covers[i][j][1];
              sat.add(A.st, !A.nd, B.st, !B.nd);
              break;
            }
            
            default:
              assert(false);
          }
        }
      }
    }
    
    auto res = sat.licz();
    
    if (SZ(res) == 0) {
      cout << "IMPOSSIBLE\n";
      return;
    }
    
    cout << "POSSIBLE\n";
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (board[i][j] == '|' || board[i][j] == '-') {
          int id = beamIds[i][j];
          if (res[id]) {
            cout << "-";
          } else {
            cout << "|";
          }
        } else {
          cout << board[i][j];
        }
      }
      cout << "\n";
    }
    
    
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

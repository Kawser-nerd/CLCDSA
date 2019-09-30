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


const int DirsR[] = {1, 0, -1, 0},
          DirsC[] = {0, 1, 0, -1};

struct Testcase {
  vector<string> board;
  vector<VI> soldiers, turrets;
  int H, W, X, numS, numT;
  vector<VI> dist;
  vector<vector<PII>> prev;
  vector<vector<VI>> visibleTurrets;
  vector<PII> soldierLocs, turretLocs;
  vector<vector<bool>> needAfter;
  vector<vector<int>> whenNeedsAfter;
  
  vector<vector<int>> soldierTurrets;
  vector<vector<PII>> turretPaths;


  bool inBoard(int r, int c) {
    return 0 <= r && r < H && 0 <= c && c < W;
  }

  void bfs(int sr, int sc) {
    dist = vector<VI>(H, VI(W, 1e9));
    dist[sr][sc] = 0;
    prev = vector<vector<PII>>(H, vector<PII>(W));

    queue<PII> Q;
    Q.push(make_pair(sr, sc));
    while (!Q.empty()) {
      int r, c;
      tie(r, c) = Q.front(); Q.pop();

      for (int d = 0; d < 4; d++) {
        int nr = r + DirsR[d],
            nc = c + DirsC[d];
        if (!inBoard(nr, nc)) { continue; }
        if (board[nr][nc] == '#') { continue; }
        if (dist[nr][nc] < 1e8) { continue; }
        dist[nr][nc] = dist[r][c] + 1;
        prev[nr][nc] = make_pair(r, c);
        Q.push(make_pair(nr, nc));
      }
    }
  }
  
  
  
  vector<int> matchST, matchTS;
  vector<bool> visitedS;
  
  bool dfsMatch(int v) {
    if (visitedS[v]) { return false; }
    visitedS[v] = true;
    for (int s : soldierTurrets[v]) {
      if (matchTS[s] == -1 || dfsMatch(matchTS[s])) {
        matchST[v] = s;
        matchTS[s] = v;
        return true;
      }
    }
    return false;
  }
  
  int match() {
    matchST.resize(numS, -1);
    matchTS.resize(numT, -1);
    visitedS.resize(numS);
    
    int result = 0;
    bool change;
    do {
      change = false;
      fill(ALL(visitedS), false);
      for (int v = 0; v < numS; v++) {
        if (!visitedS[v] && matchST[v] == -1 && dfsMatch(v)) {
          change = true;
          result++;
        }
      }
    } while (change);
    
    return result;
  }
  
  
  
  vector<int> visDfs;
  vector<int> foundPath;
  vector<int> dfsOrder;
  
  bool findCycleDfs(int v) {
    visDfs[v] = 1;
    for (int s = 0; s < numT; s++) {
      if (!needAfter[v][s]) { continue; }
      if (visDfs[s] == 1) {
        foundPath.push_back(s);
        foundPath.push_back(v);
        return true;
      }
      if (visDfs[s] == 0 && findCycleDfs(s)) {
        foundPath.push_back(v);
        return true;
      }
    }
    visDfs[v] = 2;
    return false;
  }
  
  vector<int> findCycle() {
    vector<int> cyc;
    visDfs = vector<int>(numT, 0);
    
    for (int i = 0; i < numT; i++) {
      if (visDfs[i] == 0) {
        foundPath.clear();
        if (findCycleDfs(i)) {
          for (int j = 0; j < SZ(foundPath) && (j == 0 || foundPath[j] != foundPath[0]); j++) {
            cyc.PB(foundPath[j]);
          }
          reverse(ALL(cyc));
          return cyc;
        }
      }
    }
    return {};
  }
  
  
  void topoSortDfs(int v) {
    visDfs[v] = true;
    for (int s = 0; s < numT; s++) {
      if (!visDfs[s] && needAfter[v][s]) { topoSortDfs(s); }
    }
    dfsOrder.push_back(v);
  }
  
  vector<int> topoSort() {
    visDfs = vector<int>(numT, 0);
    
    for (int i = 0; i < numT; i++) {
      if (visDfs[i] == 0) {
        topoSortDfs(i);
      }
    }
    reverse(ALL(dfsOrder));
    return dfsOrder;
  }


  void run(int tid) {
    cin >> W >> H >> X;
    debug(H, W, X);
    for (int i = 0; i < H; i++) {
      string s; cin >> s;
      board.PB(s);
    }
    soldiers.resize(H, VI(W));
    turrets = soldiers;
    numS = numT = 0;

    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (board[i][j] == 'S') {
          soldiers[i][j] = numS++;
        } else if (board[i][j] == 'T') {
          turrets[i][j] = numT++;
        }
      }
    }
    
    visibleTurrets.resize(H, vector<VI>(W));

    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (board[i][j] != '#') {
          if (board[i][j] == 'T') { visibleTurrets[i][j].emplace_back(turrets[i][j]); }
          for (int d = 0; d < 4; d++) {
            int ci = i + DirsR[d],
                cj = j + DirsC[d];
            while (inBoard(ci, cj) && board[ci][cj] != '#') {
              if (board[ci][cj] == 'T') { visibleTurrets[i][j].emplace_back(turrets[ci][cj]); }
              ci += DirsR[d];
              cj += DirsC[d];
            }
          }
        }
      }
    }

    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (board[i][j] != 'S') { continue; }
        bfs(i, j);
        soldierLocs.emplace_back(i, j);
        
        set<int> seenTurrets;
        for (int r = 0; r < H; r++) {
          for (int c = 0; c < W; c++) {
            if (dist[r][c] > X) { continue; }
            for (int v : visibleTurrets[r][c]) { seenTurrets.insert(v); }
          }
        }
        
        soldierTurrets.emplace_back(ALL(seenTurrets));
      }
    }
    
    debug(soldierTurrets);
    
    int result = match();
    debug(matchST);
    
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (board[i][j] == 'T') { turretLocs.emplace_back(i, j); }
      }
    }
    
    turretPaths.resize(numT);
    
    for (int s = 0; s < numS; s++) {
      if (matchST[s] == -1) { continue; }
      int t = matchST[s];
      debug(s, t);
      
      PII startLoc = soldierLocs[s];
      bfs(startLoc.st, startLoc.nd);
      PII curLoc{-1, -1};
      for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
          if (dist[i][j] <= X && count(ALL(visibleTurrets[i][j]), t)) {
            curLoc = PII{i, j};
          }
        }
      }
      
      vector<PII> path;
      while (curLoc != startLoc) {
        path.push_back(curLoc);
        curLoc = prev[curLoc.st][curLoc.nd];
      }
      path.push_back(startLoc);
      reverse(ALL(path));
      debug(path);
      
      turretPaths[t] = path;
    }


    while (true) {
      bool anyFound = false;
      
      for (int t = 0; t < numT; t++) {
        int s = matchTS[t];
        if (s == -1) { continue; }
        int found = -1;
        int nextT = -1;
        
        for (int i = 0; i < SZ(turretPaths[t]) - 1; i++) {
          auto cell = turretPaths[t][i];
          for (int v : visibleTurrets[cell.st][cell.nd]) {
            if (matchTS[v] != -1) { continue; }
            nextT = v;
            matchST[s] = nextT;
            matchTS[nextT] = s;
            matchTS[t] = -1;
            turretPaths[nextT].swap(turretPaths[t]);
            found = i;
            break;
          }
          
          if (found != -1) { break; }
        }
        
        debug(s, found, nextT);
        
        if (nextT != -1) {
          turretPaths[nextT].resize(found + 1);
          debug(turretPaths[nextT]);
          anyFound = true;
        }
      }
      
      if (!anyFound) { break; }
    }
    
    
    
    needAfter.resize(numT, vector<bool>(numT));
    whenNeedsAfter.resize(numT, vector<int>(numT, -1));
    
    auto setupTurret = [&](int t) {
      if (matchTS[t] == -1) { return; }
      for (int i = 0; i < numT; i++) {
        needAfter[i][t] = false;
        whenNeedsAfter[i][t] = -1;
      }
      
      for (int i = 0; i < SZ(turretPaths[t]) - 1; i++) {
        auto cell = turretPaths[t][i];
        for (int v : visibleTurrets[cell.st][cell.nd]) {
          if (v != t) {
            debug(v, t, i, whenNeedsAfter[v][t]);
            needAfter[v][t] = true;
            if (whenNeedsAfter[v][t] == -1) { whenNeedsAfter[v][t] = i; }
            debug(whenNeedsAfter[v][t]);
          }
        }
      }
    };
    
    for (int t = 0; t < numT; t++) {
      setupTurret(t);
    }
    
    while (true) {
      auto cyc = findCycle();
      debug(cyc);
      if (SZ(cyc) == 0) { break; }
      int K = SZ(cyc);
      cyc.PB(cyc[0]);
      
      vector<int> oldTS = matchTS;
      vector<vector<PII>> oldPaths = turretPaths;
      for (int i = 0; i < K; i++) {
        matchTS[cyc[i]] = oldTS[cyc[i + 1]];
        matchST[matchTS[cyc[i]]] = cyc[i];
        turretPaths[cyc[i]] = oldPaths[cyc[i + 1]];
        int a = cyc[i], b = cyc[i + 1];
        debug(whenNeedsAfter[a][b], a, b);
        turretPaths[cyc[i]].resize(whenNeedsAfter[cyc[i]][cyc[i + 1]] + 1);
        
      }
      
      for (int i = 0; i < K; i++) {
        setupTurret(cyc[i]);
      }
      
      debug(turretPaths, oldPaths);
    }
    
    debug(turretLocs);
    
    auto top = topoSort();
    debug(top);
    cout << "Case #" << tid << ": " << result << "\n";
    for (int v : top) {
      if (matchTS[v] == -1) { continue; }
      cout << matchTS[v] + 1 << " " << v + 1 << "\n";
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

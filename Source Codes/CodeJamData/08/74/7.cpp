#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

#define VV vector
#define PB push_back
#define ll long long
#define ld long double
#define REP(i,n) FOR(i,0,(n)-1)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SS(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define VI VV<int>
#define VS VV<string>
int COND = 1;
#define DB(x) { if (COND > 0) { COND--; REP (xxx, 1) cerr << __LINE__<< " " << #x << " " << x << endl; cerr.flush(); } }
int N, M;
map <VS, int> Q;

int solve(VS RET) {
  if (Q.count(RET)) return Q[RET];
  DB("");
  REP (i, N) DB(RET[i]);

  int ret = 0;
  REP (i, N) REP (j, M) if (RET[i][j] == 'K') {
    FOR (dx, -1, 1) FOR (dy, -1, 1) {
      VS NE = RET;
      NE[i][j] = '#';
      int x = i + dx; int y = j + dy;
      if (x >= 0 && x < N && y >= 0 && y < M && RET[x][y] == '.') {
        NE[x][y] = 'K';
        if (solve(NE) == 0) return Q[RET] = 1;
      }
    }
  }  

  return Q[RET] = ret;
}

int main(int argc, char **argv) {
	COND = argc >= 2 && argv[1][0] == 'q' ? (int)1e9 : 0;
  int C;
  cin >> C;
  DB(C);
  FOR (mycase, 1, C) {
    DB(mycase);
    Q.clear();
    cin >> N >> M;
    DB(N<<" "<<M);
    VS RET(N);
    REP (i, N) cin >> RET[i];
    cout << "Case #" << mycase << ": ";
    if (solve(RET)) cout << "A" << endl;
    else cout << "B" << endl;
  }


	return 0;
}

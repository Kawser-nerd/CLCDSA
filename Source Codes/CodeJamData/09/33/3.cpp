#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/* PREWRITTEN CODE */

#define ALL(x) x.begin(),x.end()
#define PB push_back


#define FOR(i,p,k) for (int i=p; i<k; i++)
#define REP(i,n) for (int i=0; i<n; i++)
#define SIZE(x) (int)x.size()
/* COMPETITION CODE */

#define INF 10000000
    
int dyn[107][107];
int pos[107];

int main() {
  int T;
  scanf("%d", &T);
  REP (tests, T) {
    int L, N;
    scanf("%d %d", &L, &N);
    pos[0] = 0;
    pos[N+1] = L+1;
    REP (i, N) scanf("%d", &pos[i+1]);
    REP (i, N+2) dyn[i][i] = 0;
    REP (i, N+1) dyn[i][i+1] = 0;
    for (int d = 2; d < N+2; d++) REP (x, N+1) {
      int best = INF;
      for (int b = x+1; b < x+d; b++) if (x+d <= N+2) {
        int cur = dyn[x][b] + dyn[b][x+d];
        if (best > cur) best = cur;
      }
      dyn[x][x+d] = best + pos[x+d] - pos[x] - 2;
    }
    printf("Case #%d: %d\n", tests+1, dyn[0][N+1]);
  }
  return 0;
}
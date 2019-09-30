/* Writen by Filip Hlasek 2014 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 111
int N, A;
char graph[MAXN][MAXN];
int p[MAXN];

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  FOR(testcase, 1, T) {
    scanf("%d%d", &N, &A);
    REP(i, N) scanf("%s", graph[i]);
    REP(i, N) p[i] = i;
    printf("Case #%d:", testcase);
    bool ok = false;
    do {
      int a = p[0];
      REP(i, N) if (graph[p[i]][a] == 'Y') a = p[i];
      if (a == A) {
        REP(i, N) printf(" %d", p[i]);
        ok = true;
        break;
      }
    } while (next_permutation(p, p + N));
    if (!ok) printf(" IMPOSSIBLE");
    printf("\n");
  }
 return 0;
}

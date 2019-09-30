/* Writen by Filip Hlasek 2012 */
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

#define MAXN 21

bool visited[1 << MAXN][MAXN];
int L[MAXN], R[MAXN], N;


int main(int argc, char *argv[]){
  int T;
  scanf("%d",&T);
  REP(t,T){
    scanf("%d",&N);
    long long mask = 0;
    REP(i, N-1) scanf("%d%d",L+i, R+i);
    REP(j,N) REP(i, 1 << N) visited[i][j] = false;
    int x = 0, step = 0;
    while(x != N-1 && !visited[mask][x]){
      step++;
//      printf("x:%d\n",x);
      visited[mask][x] = true;
      mask ^= (1 << x);
      if(mask & (1 << x)) x = L[x] - 1; 
      else x = R[x] - 1;
    }
    printf("Case #%d: ", t + 1);
    if(x != N-1) printf("Infinity\n");
    else printf("%d\n",step);
  }
  return 0;
}

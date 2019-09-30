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
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

const int D[6][2] = {{-1,0},{-1,-1},{0,-1},{1,0},{1,1},{0,1}};
#define MAXN 7000
int color[MAXN][MAXN], cs[MAXN*MAXN], C;
int S,M;
int corner[6][2], edge[6][MAXN][2];

void dfs(int x,int y,int col){
  if(color[x][y] && color[x][y] != col){
    cs[color[x][y]]--;
    cs[col]++;
    color[x][y] = col;
    REP(d,6) dfs(x + D[d][0], y + D[d][1], col);
  }
}

int pos[10], POS;

bool solve(int x,int y,int step){
  bool bridge = false , fork = false, ring = false;
  POS = 0;
  REP(d,6){
    pos[POS] = color[x+D[d][0]][y+D[d][1]];
    if(pos[POS]){
      if(color[x+D[(d+1)%6][0]][y+D[(d+1)%6][1]] != pos[POS] && color[x+D[(d+2)%6][0]][y+D[(d+2)%6][1]] == pos[POS] &&
        (color[x+D[(d+4)%6][0]][y+D[(d+4)%6][1]] != pos[POS] || color[x+D[(d+5)%6][0]][y+D[(d+5)%6][1]] != pos[POS] ||
         color[x+D[(d+3)%6][0]][y+D[(d+3)%6][1]] != pos[POS])) ring = true;
      if(color[x+D[(d+1)%6][0]][y+D[(d+1)%6][1]] != pos[POS] && color[x+D[(d+2)%6][0]][y+D[(d+2)%6][1]] != pos[POS] &&
         color[x+D[(d+4)%6][0]][y+D[(d+4)%6][1]] != pos[POS] && color[x+D[(d+5)%6][0]][y+D[(d+5)%6][1]] != pos[POS] &&
         color[x+D[(d+3)%6][0]][y+D[(d+3)%6][1]] == pos[POS]) ring = true;
      POS++;
    }
  }
  int col;
  if(POS){
    col = pos[0];
    REP(i,POS) if(cs[pos[i]] > cs[col]) col = pos[i];
//    col = pos[rand()%POS];
  }
  else{ cs[C] = 0; col = C++; }
  color[x][y] = MAXN * MAXN - 1;
  dfs(x,y,col);

  int cnt = 0;
  REP(i,6) cnt += (color[corner[i][0]][corner[i][1]] == col);
  bridge = (cnt > 1);

  cnt = 0;
  REP(i,6) REP(j,S-2) if(color[edge[i][j][0]][edge[i][j][1]] == col){ cnt++; break; }
  fork = (cnt > 2);

  if(bridge || fork || ring){
    bool printed = false;
    if(bridge){ printf("bridge"); printed = true; }
    if(fork){
      if(printed) printf("-");
      printf("fork");
      printed = true;
    }
    if(ring){
      if(printed) printf("-");
      printf("ring");
    }
    printf(" in move %d\n",step);
    return true;
  }
  return false;
}

int main(int argc, char *argv[]){
  int T; 
  scanf("%d",&T);
  REP(t,T){
    scanf("%d%d",&S,&M);
    REP(i,2*S+2) REP(j,2*S+2) color[i][j] = 0;
    C = 1;
    corner[0][0] = 1; corner[0][1] = 1;
    corner[1][0] = 1; corner[1][1] = S;
    corner[2][0] = S; corner[2][1] = 1;
    corner[3][0] = 2*S-1; corner[3][1] = S;
    corner[4][0] = S; corner[4][1] = 2*S-1;
    corner[5][0] = 2*S-1; corner[5][1] = 2*S-1;
    FOR(i,2,S-1){ edge[0][i-2][0] = 1; edge[0][i-2][1] = i; }
    FOR(i,2,S-1){ edge[1][i-2][0] = i; edge[1][i-2][1] = 1; }
    FOR(i,2,S-1){ edge[2][i-2][0] = i; edge[2][i-2][1] = S+i-1; }
    FOR(i,2,S-1){ edge[3][i-2][0] = S+i-1; edge[3][i-2][1] = i; }
    FOR(i,2,S-1){ edge[4][i-2][0] = 2*S-1; edge[4][i-2][1] = S+i-1; }
    FOR(i,2,S-1){ edge[5][i-2][0] = S+i-1; edge[5][i-2][1] = 2*S-1; }
    bool done = false;
    printf("Case #%d: ",t+1);
    int x,y;
    REP(i,M){
      scanf("%d%d",&x,&y);
      if(done) continue;
      if(solve(x,y,i+1)) done = true;
    }
    if(!done) printf("none\n");
    //REP(i,2*S) REP(j,2*S) printf("i:%d j:%d color:%d\n",i,j,color[i][j]);
  }
  return 0;
}

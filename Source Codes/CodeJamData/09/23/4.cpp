#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

const int MAX = 22;
const int MID = 2000;
const int TOT = 4001;
const int INF = 0x3f3f3f3f;

int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int n, que;
char field[MAX][MAX];
int dp[MAX][MAX][TOT];
string bst[MAX][MAX][TOT];
int qbeg, qend, q[MAX*MAX*TOT][3];

void push(int x, int y, int num){
  qend++;
  q[qend][0] = x;
  q[qend][1] = y;
  q[qend][2] = num;
}

inline int valid(int x, int y){
  return ((x>=0) && (x<n) && (y>=0) && (y<n));
}

void go(int cx, int cy, int cnum){
  char sgn;
  string ns;
  int nx, ny, sx, sy, nnum, d1, d2, nd;
  for (d1=0; d1<4; d1++){
    sx = cx + dirs[d1][0];
    sy = cy + dirs[d1][1];
    if (!valid(sx, sy)) continue;
    sgn = field[sx][sy];
    for (d2=0; d2<4; d2++){
      nx = sx + dirs[d2][0];
      ny = sy + dirs[d2][1];
      if (!valid(nx, ny)) continue;
      if (sgn=='+') nnum = cnum + field[nx][ny]-'0';
      else nnum = cnum - (field[nx][ny]-'0');
      if (nnum<0 || nnum>=TOT) continue;
      nd = dp[cx][cy][cnum] + 1;
      if (nd > dp[nx][ny][nnum]) continue;
      ns = bst[cx][cy][cnum];
      ns += sgn;
      ns += field[nx][ny];
      if (nd < dp[nx][ny][nnum] || ns<bst[nx][ny][nnum]){
        if (dp[nx][ny][nnum] == INF) push(nx, ny, nnum);
        dp[nx][ny][nnum] = nd;
        bst[nx][ny][nnum] = ns;
      }
    }
  }
} 

int main(){
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int tn, t;
  scanf("%d\n", &tn);
  for (t=1; t<=tn; t++){
    printf("Case #%d:\n", t); 
    scanf("%d%d\n", &n, &que);
    int i, j;
    memset(dp, 0x3f, sizeof(dp));
    qbeg = 1;
    qend = 0;
    for (i=0; i<n; i++){
      for (j=0; j<n; j++){
        scanf("%c", &field[i][j]);
        if (field[i][j]>='0' && field[i][j]<='9'){
          int x = field[i][j]-'0';
          dp[i][j][MID + x] = 1;
          bst[i][j][MID + x] = field[i][j];
          push(i, j, MID+x);
        }
      }
      scanf("\n");
    }
    while (qbeg <= qend){
      go(q[qbeg][0], q[qbeg][1], q[qbeg][2]);
      qbeg++;
    }
    for (int cq=0; cq<que; cq++){
      int znum;
      scanf("%d", &znum);
      znum += MID;
      int nd=INF;
      string res="z";
      for (i=0; i<n; i++){
        for (j=0; j<n; j++){
          if (dp[i][j][znum]<nd || (dp[i][j][znum]==nd && bst[i][j][znum]<res)){
            nd = dp[i][j][znum];
            res = bst[i][j][znum];
          }
        }
      }
      printf("%s\n", res.c_str());
    }
  }  
  return 0;
}

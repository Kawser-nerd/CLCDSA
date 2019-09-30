#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
#define PI 3.14159265358979323846264338327950288
#define MAX 10000000
int T;
int N, M;
char mat[20][20];
short int mark[15][15][15][15][15][15][4][4];
short int shoot[15][15][4][2];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
short int dist[15][15][15][15][15][15][4][4];
int front, back;
short int que[10000005][8];
#define M(x) (mark[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]][x[6]][x[7]])
#define D(x) (dist[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]][x[6]][x[7]])
#define OK(a, b) ((a) >= 0 && (a) < N && (b) >= 0 && (b) < M && mat[a][b] != '#')
int main() {
   int i, j, k, l, m, Case = 1;
   scanf("%d", &T);
   memset(mark, -1, sizeof(mark));
   while (T --) {
      scanf("%d%d", &N, &M);
      for (i = 0; i < N; i ++)
	 scanf("%s", mat[i]);
      for (i = 0; i < N; i ++)
	 for (j = 0; j < M; j ++)
	    if (mat[i][j] != '#')
	       for (k = 0; k < 4; k ++) {
		  for (l = i, m = j; OK(l, m); l += dx[k], m += dy[k]);
		  l -= dx[k];
		  m -= dy[k];
		  shoot[i][j][k][0] = l;
		  shoot[i][j][k][1] = m;
	       }
      for (i = 0; i < N; i ++)
	 for (j = 0; j < M; j ++)
	    if (mat[i][j] == 'O') {
	       front = 1;
	       back = 0;
	       que[0][0] = i;
	       que[0][1] = j;
	       que[0][2] = shoot[i][j][0][0];
	       que[0][3] = shoot[i][j][0][1];
	       que[0][4] = shoot[i][j][1][0];
	       que[0][5] = shoot[i][j][1][1];
	       que[0][6] = 0;
	       que[0][7] = 1;
	       M(que[0]) = Case;
	       D(que[0]) = 0;
	    }
      int fini = 0;
      int ret;
      while (front != back) {
	 for (i = 0; i < 5; i ++)
	    for (j = 0; j < 5; j ++) {
	       if (i < 4 && j < 4 && i == j)
		  continue;
	       for (k = 0; k < 4; k ++) {
		  memcpy(que[front], que[back], sizeof(que[back]));
		  if (i < 4) {
		     que[front][2] = shoot[que[front][0]][que[front][1]][i][0];
		     que[front][3] = shoot[que[front][0]][que[front][1]][i][1];
		     que[front][6] = i;
		  }
		  if (j < 4) {
		     que[front][4] = shoot[que[front][0]][que[front][1]][j][0];
		     que[front][5] = shoot[que[front][0]][que[front][1]][j][1];
		     que[front][7] = j;
		  }
		  if (que[front][0] == que[front][2] && que[front][1] == que[front][3] && k == que[front][6]) {
		     que[front][0] = que[front][4];
		     que[front][1] = que[front][5];
		  }
		  else
		     if (que[front][0] == que[front][4] && que[front][1] == que[front][5] && k == que[front][7]) {
			que[front][0] = que[front][2];
			que[front][1] = que[front][3];
		     }
		     else {
			que[front][0] += dx[k];
			que[front][1] += dy[k];
		     }
		  if (OK(que[front][0], que[front][1]) && M(que[front]) < Case) {
		     M(que[front]) = Case;
		     D(que[front]) = D(que[back]) + 1;
		     if (mat[que[front][0]][que[front][1]] == 'X') {
			ret = D(que[front]);
			fini = 1;
			break;
		     }
		     front ++;
		     if (front >= MAX)
			front = 0;
		  }
	       }
	    }
	 if (fini)
	    break;
	 back ++;
	 if (back >= MAX)
	    back = 0;
      }
      printf("Case #%d: ", Case ++);
      if (fini)
	 printf("%d\n", ret);
      else
	 printf("THE CAKE IS A LIE\n");
   }
   return 0;
}


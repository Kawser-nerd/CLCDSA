#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <sstream>
#include <set>
#include <complex>
#include <algorithm>
using namespace std;
#define PI 3.14159265358979323846264338327950288
int T, N, M;
char mat[35][35];
int alltree[905][2];
int s;
long long graph[905][905];
long long tmp[905];
int dist[905][35][35];
int minDist[35][35];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
#define OK(a, b) ((a) >= 0 && (b) >= 0 && (a) < N && (b) < M && !mark[a][b] && mat[a][b] != '.')
int bfs(int x, int y, int res[35][35]) {
   int i, j;
   int que[905][2], front, back, mark[35][35];
   front = 1;
   back = 0;
   que[0][0] = x;
   que[0][1] = y;
   memset(mark, 0, sizeof(mark));
   mark[x][y] = 1;
   res[x][y] = 0;
   while (front > back) {
      for (i = 0; i < 4; i ++) {
	 que[front][0] = que[back][0] + dx[i];
	 que[front][1] = que[back][1] + dy[i];
	 if (OK(que[front][0], que[front][1])) {
	    mark[que[front][0]][que[front][1]] = 1;
	    res[que[front][0]][que[front][1]] = res[que[back][0]][que[back][1]] + 1;
   	    front ++;
	 }
      }
      back ++;
   }
   for (i = 0; i < N; i ++)
      for (j = 0; j < M; j ++)
	 minDist[i][j] = min(minDist[i][j], res[i][j]);
   return 0;
}
long long calc(long long x) {
   long long half = x / 2;
   return (x * (x + 1) / 2) - half * (half + 1) / 2 - (x - 1 - half) * (x - half) / 2;
}
int main() {
   int i, j, k, Case = 1;
   scanf("%d", &T);
   while (T --) {
      scanf("%d%d", &N, &M);
      for (i = 0; i < N; i ++)
	 scanf("%s", mat[i]);
      s = 0;
      for (i = 0; i < N; i ++)
	 for (j = 0; j < M; j ++)
	    minDist[i][j] = 1000000000;
      for (i = 0; i < N; i ++)
	 for (j = 0; j < M; j ++)
	    if (mat[i][j] == 'T') {
	       alltree[s][0] = i;
	       alltree[s][1] = j;
	       bfs(i, j, dist[s]);
	       s ++;
	    }
      long long ret = 0;
      for (i = 0; i < N; i ++)
	 for (j = 0; j < M; j ++)
	    if (mat[i][j] != '.')
   	       ret += minDist[i][j];
      for (i = 0; i < s; i ++)
	 for (j = 0; j < s; j ++)
	    graph[i][j] = calc(dist[i][alltree[j][0]][alltree[j][1]]);
      for (i = 0; i < s; i ++)
	 tmp[i] = 1000000000000000000LL;
      int done[905];
      memset(done, 0, sizeof(done));
      done[0] = 1;
      tmp[0] = 0;
      j = 0;
      while (1) {
	 for (i = 0; i < s; i ++)
	    if (!done[i])
	       tmp[i] = min(tmp[i], graph[j][i]);
	 j = -1;
	 for (k = 0; k < s; k ++)
	    if (!done[k] && (j == -1 || tmp[j] > tmp[k]))
	       j = k;
	 if (j == -1)
	    break;
	 done[j] = 1;
	 ret += tmp[j];
      }
      printf("Case #%d: %lld\n", Case ++, ret);
   }
   return 0;
}


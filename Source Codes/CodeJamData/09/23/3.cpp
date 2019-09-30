#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define PI 3.14159265358979323846264338327950288
int T;
int W, Q, N;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
#define OK(a, b) ((a) >= 0 && (b) >= 0 && (a) < W && (b) < W)
char mat[25][25];
char mark[25][25][750];
string ans[25][25][750];
int que[3000000][3];
int front, back;
int cmp(const int &a, const int &b) {
   return (ans[que[a][0]][que[a][1]][que[a][2]] < ans[que[b][0]][que[b][1]][que[b][2]]);
}
int main() {
   int i, j, Case = 1;
   scanf("%d", &T);
   while (T --) {
      scanf("%d%d", &W, &Q);
      for (i = 0; i < W; i ++)
	 scanf("%s", mat[i]);
      memset(mark, 0, sizeof(mark));
      front = 0;
      for (i = 0; i < W; i ++)
	 for (j = 0; j < W; j ++)
	    if (mat[i][j] >= '0' && mat[i][j] <= '9') {
	       mark[i][j][mat[i][j] - '0' + 250] = 1;
	       que[front][0] = i;
	       que[front][1] = j;
	       que[front][2] = mat[i][j] - '0' + 250;
	       ans[i][j][mat[i][j] - '0' + 250] = mat[i][j];
	       front ++;
	    }
      back = 0;
      while (front > back) {
	 int x = que[back][0], y = que[back][1], val = que[back][2];
	 string last = ans[que[back][0]][que[back][1]][que[back][2]];
	 for (i = 0; i < 4; i ++)
	    if (OK(x + dx[i], y + dy[i]))
	       for (j = 0; j < 4; j ++)
		  if (OK(x + dx[i] + dx[j], y + dy[i] + dy[j])) {
		     int val2 = val + (mat[x + dx[i] + dx[j]][y + dy[i] + dy[j]] - '0') * (mat[x + dx[i]][y + dy[i]] == '+' ? 1 : -1);
		     que[front][0] = x + dx[i] + dx[j];
		     que[front][1] = y + dy[i] + dy[j];
		     que[front][2] = val2;
		     if (val2 >= 0 && val2 < 750) {
			string tmp = last + mat[x + dx[i]][y + dy[i]] + mat[que[front][0]][que[front][1]];
			if (!mark[que[front][0]][que[front][1]][que[front][2]]) {
			   mark[que[front][0]][que[front][1]][que[front][2]] = 1;
			   ans[que[front][0]][que[front][1]][que[front][2]] = tmp;
			   front ++;
			}
			else
			   if (ans[que[front][0]][que[front][1]][que[front][2]].length() == tmp.length() && ans[que[front][0]][que[front][1]][que[front][2]] > tmp)
			      ans[que[front][0]][que[front][1]][que[front][2]] = tmp;
		     }
		  }
	 back ++;
      }
      printf("Case #%d:\n", Case ++);
      while (Q --) {
	 scanf("%d", &N);
	 string ret = "";
	 for (i = 0; i < W; i ++)
	    for (j = 0; j < W; j ++)
	       if (mark[i][j][N + 250])
		  if (ret == "" || ret.length() > ans[i][j][N + 250].length() || ret.length() == ans[i][j][N + 250].length() && ret > ans[i][j][N + 250])
		     ret = ans[i][j][N + 250];
	 printf("%s\n", ret.c_str());
      }
   }
   return 0;
}

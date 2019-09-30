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
#define MASK ((1 << M) - 1)
int T;
int N, M;
char mat[25][25];
int ans[20][20][1 << 15];
int cost(int m, int y) {
   int ret = 0;
   if (m & (1 << M - 1))
      ret += 2;
   if (y && (m & 1))
      ret += 2;
   return ret;
}
int dfs(int x, int y, int m) {
   if (y == M)
      return dfs(x + 1, 0, m);
   if (x == N)
      return 0;
   if (ans[x][y][m] != -1)
      return ans[x][y][m];
   int &ret = ans[x][y][m];
   ret = 0;
   if (mat[x][y] != '.')
      ret = max(ret, dfs(x, y + 1, (m * 2 + 1) & MASK) + 4 - cost(m, y));
   if (mat[x][y] != '#')
      ret = max(ret, dfs(x, y + 1, (m * 2) & MASK));
   return ret;
}
int main() {
   int i, j, k, Case = 1;
   scanf("%d", &T);
   while (T --) {
      scanf("%d%d", &N, &M);
      for (i = 0; i < N; i ++)
	 scanf("%s", mat[i]);
      for (i = 0; i < N; i ++)
	 for (j = 0; j < M; j ++)
	    for (k = 0; k < (1 << M); k ++)
   	       ans[i][j][k] = -1;
      printf("Case #%d: %d\n", Case ++, dfs(0, 0, 0));
   }
   return 0;
}


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
int T;
int N, M;
int mat[105][105];
int dx[2], dy[2];
int cntx, cnty;
int ret;
int dfs(int x, int y) {
   if (x < 0 || y < 0 || x >= N || y >= M)
      return 0;
   if (mat[x][y])
      return 0;
   mat[x][y] = 1;
   ret ++;
   for (int i = 0; i < 2; i ++)
      dfs(x + dx[i], y + dy[i]);
   return 0;
}
int main() {
   int i, j, k, Case = 1;
   scanf("%d", &T);
   while (T --) {
      scanf("%d%d", &N, &M);
      for (i = 0; i < 2; i ++)
	 scanf("%d%d", &dx[i], &dy[i]);
      scanf("%d%d", &cntx, &cnty);
      memset(mat, 0, sizeof(mat));
      ret = 0;
      dfs(cntx, cnty);
      printf("Case #%d: %d\n", Case ++, ret);
   }
   return 0;
}


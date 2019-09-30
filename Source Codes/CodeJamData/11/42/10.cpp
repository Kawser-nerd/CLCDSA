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
#include <cassert>
#include <complex>
using namespace std;
#define PI 3.14159265358979323846264338327950288
int R, C;
int T;
int num[505][505];
long long sum[3][505][505];
#define max(a, b) ((a) > (b) ? (a) : (b))
inline long long get(int v, int a1, int a2, int b1, int b2) {
   return sum[v][a2][b2] - sum[v][a1][b2] - sum[v][a2][b1] + sum[v][a1][b1];
}
inline int check(int a, int b, int s) {
   long long val1 = get(0, a, a + s, b, b + s);
   long long val2 = get(1, a, a + s, b, b + s);
   long long val3 = get(2, a, a + s, b, b + s);
   val1 -= num[a][b] + num[a + s - 1][b] + num[a][b + s - 1] + num[a + s - 1][b + s - 1];
   val2 -= a * num[a][b] + (a + s - 1) * num[a + s - 1][b] + a * num[a][b + s - 1] + (a + s - 1) * num[a + s - 1][b + s - 1];
   val3 -= b * num[a][b] + b * num[a + s - 1][b] + (b + s - 1) * num[a][b + s - 1] + (b + s - 1) * num[a + s - 1][b + s - 1];
   if (val2 * 2 == val1 * (2 * a + s - 1) && val3 * 2 == val1 * (2 * b + s - 1))
      return 1;
   return 0;
}
int main() {
   int i, j, k, Case = 1;
   scanf("%d", &T);
   while (T --) {
      scanf("%d%d%*d", &R, &C);
      for (i = 0; i < R; i ++) {
	 char tmp[505];
	 scanf("%s", tmp);
	 for (j = 0; j < C; j ++)
	    num[i][j] = tmp[j] - '0';
      }
      for (k = 0; k < 3; k ++)
	 for (i = 0; i <= R; i ++)
	    for (j = 0; j <= C; j ++)
	       if (i == 0 || j == 0)
		  sum[k][i][j] = 0;
	       else {
		  sum[k][i][j] = sum[k][i - 1][j] + sum[k][i][j - 1] - sum[k][i - 1][j - 1];
		  if (k == 0)
		     sum[k][i][j] += num[i - 1][j - 1];
		  else
		     if (k == 1)
			sum[k][i][j] += num[i - 1][j - 1] * (i - 1);
		     else
			sum[k][i][j] += num[i - 1][j - 1] * (j - 1);
	       }
      int ans = -1;
      for (i = 0; i < R; i ++)
	 for (j = 0; j < C; j ++)
	    for (k = 3; i + k <= R && j + k <= C; k ++)
	       if (check(i, j, k))
		  ans = max(ans, k);
      if (ans == -1)
	 printf("Case #%d: IMPOSSIBLE\n", Case ++);
      else
	 printf("Case #%d: %d\n", Case ++, ans);
   }
   return 0;
}


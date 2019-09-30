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
int T, N;
int info[1005][4];
double limit[8];
#define Eps 1E-8
#define equal(a, b) (fabs((a) - (b)) < Eps)
int con(double *res, int x) {
   res[0] = (x & 1 ? 1 : -1);
   res[1] = (x & 2 ? 1 : -1);
   res[2] = (x & 4 ? 1 : -1);
   res[3] = limit[x];
   return 0;
}
int solve(double mat[5][5], double res[5]) {
   int i, j, k, l;
   for (i = 0; i < 3; i ++) {
      for (j = 0; j < 3; j ++)
	 if (!equal(0, mat[i][j]))
	    break;
      for (k = 0; k < 3; k ++)
	 if (k != i) {
	    double t = mat[k][j] / mat[i][j];
	    for (l = 0; l < 4; l ++)
	       mat[k][l] -= t * mat[i][l];
	 }
   }
   for (i = 0; i < 3; i ++)
      for (j = 0; j < 3; j ++)
	 if (!equal(0, mat[i][j]))
	    res[j] = mat[i][3] / mat[i][j];
   return 0;
}
int main() {
   int i, j, k, Case = 1, l;
   double f, r, m;
   double mat[5][5], tmp[5];
   scanf("%d", &T);
   while (T --) {
      scanf("%d", &N);
      for (i = 0; i < N; i ++)
	 for (j = 0; j < 4; j ++)
	    scanf("%d", &info[i][j]);
      f = 0;
      r = 1E10;
      while (f + 1E-8 < r && (r - f) > 1E-8 * f) {
	 for (i = 0; i < 8; i ++)
	    limit[i] = 1E10;
	 m = (f + r) / 2;
	 for (i = 0; i < N; i ++)
	    for (j = 0; j < 8; j ++)
	       limit[j] = min(limit[j], ((j & 1) ? 1 : -1) * info[i][0] + ((j & 2) ? 1 : -1) * info[i][1] + ((j & 4) ? 1 : -1) * info[i][2] + m * info[i][3]);
	 double OK = 0;
	 for (i = 0; i < 8; i ++)
	    for (j = i + 1; j < 8; j ++)
	       for (k = j + 1; k < 8; k ++)
		  if (i + j != 7 && j + k != 7 && i + k != 7) {
		     con(mat[0], i);
		     con(mat[1], j);
		     con(mat[2], k);
		     solve(mat, tmp);
		     for (l = 0; l < 8; l ++)
			if (limit[l] < tmp[0] * ((l & 1) ? 1 : -1) + tmp[1] * ((l & 2) ? 1 : -1) + tmp[2] * ((l & 4) ? 1 : -1) - Eps)
			   break;
		     if (l >= 8)
			OK = 1;
		  }
	 if (OK)
	    r = m;
	 else
	    f = m;
      }
      printf("Case #%d: %lf\n", Case ++, f);
   }
   return 0;
}


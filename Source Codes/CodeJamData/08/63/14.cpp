#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
#define PI 3.14159265358979323846264338327950288
#define tar 1000000LL
int C;
int X, M;
double P;
double Ans[17][1 << 15];
int main() {
   int i, j, k, Case = 1;
   scanf("%d", &C);
   while (C --) {
      scanf("%d%lf%d", &M, &P, &X);
      for (i = 1; i <= (1 << M); i ++)
	 if ((long long)X * (1 << M) < tar * i)
	    break;
      X = i - 1;
      for (i = 0; i <= M; i ++)
	 for (j = 0; j <= (1 << M); j ++)
	    if (i == 0)
	       if (j == (1 << M))
		  Ans[i][j] = 1;
	       else
		  Ans[i][j] = 0;
	    else {
	       Ans[i][j] = 0;
	       for (k = 0; k <= j && k + j <= (1 << M); k ++)
		  Ans[i][j] = max(Ans[i][j], Ans[i - 1][j - k] * (1 - P) + Ans[i - 1][j + k] * P);
	    }
      printf("Case #%d: %.6lf\n", Case ++, Ans[M][X]);
   }
   return 0;
}


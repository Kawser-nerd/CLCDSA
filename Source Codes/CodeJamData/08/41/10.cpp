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
int T;
int N, V;
int info[10005][2];
long long Ans[10005][2];
int main() {
   int i, j, Case = 1, k, l;
   scanf("%d", &T);
   while (T --) {
      scanf("%d%d", &N, &V);
      for (i = 0; i < (N - 1) / 2; i ++)
	 scanf("%d%d", &info[i][0], &info[i][1]);
      for (; i < N; i ++)
	 scanf("%d", &info[i][0]);
      for (i = N - 1; i >= 0; i --)
	 for (j = 0; j < 2; j ++)
	    if (i >= (N - 1) / 2)
	       if (j == info[i][0])
		  Ans[i][j] = 0;
	       else
		  Ans[i][j] = 1000000000;
	    else {
	       Ans[i][j] = 1000000000;
	       for (k = 0; k < 2; k ++)
		  for (l = 0; l < 2; l ++)
		     if ((k | l) == j)
			Ans[i][j] = min(Ans[i][j], Ans[i * 2 + 1][k] + Ans[i * 2 + 2][l] + (info[i][0] == 0 ? 0 : info[i][1] ? 1LL : 1000000000LL));
	       for (k = 0; k < 2; k ++)
		  for (l = 0; l < 2; l ++)
		     if ((k & l) == j)
			Ans[i][j] = min(Ans[i][j], Ans[i * 2 + 1][k] + Ans[i * 2 + 2][l] + (info[i][0] == 1 ? 0 : info[i][1] ? 1LL : 1000000000LL));
	    }
      printf("Case #%d: ", Case ++);
      if (Ans[0][V] >= 1000000000LL)
	 printf("IMPOSSIBLE\n");
      else
	 printf("%d\n", (int)Ans[0][V]);
   }
   return 0;
}


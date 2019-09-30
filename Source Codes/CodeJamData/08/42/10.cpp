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
int T, N, M, A;
int main() {
   int i, j, Case = 1, k, l;
   int resi, resj, resk, resl;
   scanf("%d", &T);
   while (T --) {
      scanf("%d%d%d", &N, &M, &A);
      resi = -1;
      for (i = 0; i <= N && resi == -1; i ++)
	 for (j = 0; j <= M && resi == -1; j ++)
	    for (k = 0; k <= N && resi == -1; k ++)
	       for (l = 0; l <= M && resi == -1; l ++)
		  if (i * l - j * k == A) {
		     resi = i;
		     resj = j;
		     resk = k;
		     resl = l;
		  }
      printf("Case #%d: ", Case ++);
      if (resi == -1)
	 printf("IMPOSSIBLE\n");
      else
	 printf("0 0 %d %d %d %d\n", resi, resj, resk, resl);
   }
   return 0;
}


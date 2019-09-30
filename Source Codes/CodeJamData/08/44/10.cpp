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
int K, N, T;
char str[50005];
int cost[20][20];
int cost2[20][20];
int Ans[1 << 16][20];
int main() {
   int i, j, Case = 1, k, l;
   scanf("%d", &T);
   while (T --) {
      scanf("%d", &K);
      scanf("%s", str);
      N = strlen(str);
      for (i = 0; i < K; i ++)
	 for (j = 0; j < K; j ++)
	    if (i != j) {
	       cost[i][j] = 0;
	       for (k = 0; k < N / K; k ++)
		  if (str[k * K + i] != str[k * K + j])
		     cost[i][j] ++;
	    }
      for (i = 0; i < K; i ++)
	 for (j = 0; j < K; j ++)
	    if (i != j) {
	       cost2[i][j] = 0;
	       for (k = 0; k < N / K - 1; k ++)
		  if (str[k * K + i] != str[(k + 1) * K + j])
		     cost2[i][j] ++;
	    }
      int ret = N + 5;
      for (i = 0; i < K; i ++) {
	 for (j = 0; j < (1 << K); j ++)
	    for (k = 0; k < K; k ++)
	       Ans[j][k] = N + 5;
	 for (j = 0; j < (1 << K); j ++)
	    if (j & (1 << i))
	       for (k = 0; k < K; k ++)
		  if (j & (1 << k)) {
		     if (j == (1 << k)) {
			Ans[j][k] = 0;
			continue;
		     }
		     for (l = 0; l < K; l ++)
			if (l != k && (j & (1 << l)))
			   Ans[j][k] = min(Ans[j][k], Ans[j ^ (1 << k)][l] + cost[l][k]);
		  }
	 for (k = 0; k < K; k ++)
	    ret = min(ret, Ans[(1 << K) - 1][k] + cost2[k][i]);
      }
      printf("Case #%d: %d\n", Case ++, ret + 1);
   }
   return 0;
}


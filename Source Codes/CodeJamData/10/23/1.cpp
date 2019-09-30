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
#define MOD 100003
int T;
int N;
long long ans[505][505];
long long cst[505][505];
int main() {
   int i, j, k;
   int Case = 1;
   for (i = 0; i <= 500; i ++)
      for (j = 0; j <= i; j ++)
	 if (j == 0 || j == i)
	    cst[i][j] = 1;
	 else
	    cst[i][j] = (cst[i - 1][j] + cst[i - 1][j - 1]) % MOD;
   for (i = 2; i <= 500; i ++)
      for (j = 1; j <= i - 1; j ++) {
	 ans[i][j] = 0;
	 if (j == 1)
	    ans[i][j] = 1;
	 else
	    for (k = 1; k <= j - 1; k ++) {
	       ans[i][j] += ans[j][k] * cst[i - j - 1][j - k - 1];
	       ans[i][j] %= MOD;
	    }
      }
   scanf("%d", &T);
   while (T --) {
      scanf("%d", &N);
      long long ret = 0;
      for (i = 1; i <= N; i ++)
	 ret += ans[N][i];
      ret %= MOD;
      printf("Case #%d: %lld\n", Case ++, ret);
   }
   return 0;
}


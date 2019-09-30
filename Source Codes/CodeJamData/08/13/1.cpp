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
#define MOD 1000
int T;
long long N;
int one[2][2] = {{6, 1}, {-4, 0}};
int mat[50][2][2];
int out(int x) {
   printf("%d%d%d\n", x / 100, x / 10 % 10, x % 10);
   return 0;
}
int main() {
   int i, j, Case = 1, k, l;
   long long cnt[2];
   scanf("%d", &T);
   memcpy(mat[0], one, sizeof(one));
   for (i = 1; i < 50; i ++) {
      memset(mat[i], 0, sizeof(mat[i]));
      for (j = 0; j < 2; j ++)
	 for (k = 0; k < 2; k ++)
	    for (l = 0; l < 2; l ++)
	       mat[i][j][l] = (mat[i][j][l] + mat[i - 1][j][k] * mat[i - 1][k][l]) % MOD;
   }
   while (T --) {
      scanf("%lld", &N);
      cnt[0] = 6;
      cnt[1] = 2;
      for (i = 0; i < 50; i ++)
	 if (N & (1LL << i)) {
	    long long tmp[2] = {0, 0};
	    for (j = 0; j < 2; j ++)
	       for (k = 0; k < 2; k ++)
		  tmp[k] = (tmp[k] + cnt[j] * mat[i][j][k]) % MOD;
	    cnt[0] = tmp[0];
	    cnt[1] = tmp[1];
	 }
      printf("Case #%d: ", Case ++);
      out((cnt[1] + 999) % MOD);
   }
   return 0;
}


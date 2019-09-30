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
int T, N, M;
int mat[55][55];
int sum(int x) {
   int i;
   int ret = 0;
   switch (M % 3) {
      case 0:
	 for (i = 1; i < M; i += 3)
	    ret += mat[x][i];
	 return ret;
      case 1:
	 for (i = 0; i < M; i += 3)
	    ret += mat[x][i];
	 return ret;
      case 2:
	 for (i = 0; i < M; i += 3)
	    ret += mat[x][i];
	 return ret;
   }
   return -1;
}
int calc(int x) {
   int ret, i;
   if (x % 3 == 2) {
      ret = sum(1) - sum(0);
      for (i = 2; i < x; i += 3)
	 ret += sum(i + 2) - sum(i + 1);
      return ret;
   }
   ret = sum(N - 2) - sum(N - 1);
   for (i = N - 3; i > x; i -= 3)
      ret += sum(i - 2) - sum(i - 1);
   return ret;
}
int main() {
   int i, j, k, Case = 1;
   scanf("%d", &T);
   while (T --) {
      scanf("%d%d", &N, &M);
      for (i = 0; i < N; i ++)
	 for (j = 0; j < M; j ++)
	    scanf("%d", &mat[i][j]);
      int ret = 0;
      if ((N / 2) % 3 == 2)
	 ret = calc(N / 2);
      else
	 ret = sum(N / 2) - calc(N / 2 + 1) - calc(N / 2 - 1);
      printf("Case #%d: %d\n", Case ++, ret);
   }
   return 0;
}


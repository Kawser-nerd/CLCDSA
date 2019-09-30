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
int T;
int N, B;
int ret;
int left;
int num[10][10];
int dfs(int x) {
   int i;
   if (left == 0) {
      ret ++;
      return 0;
   }
   for (i = x + 1; i <= left; i ++) {
      int j, k = 0;
      for (j = i; j; j /= B, k ++)
	 if (num[k][j % B])
	    break;
      if (j == 0) {
	 k = 0;
	 for (j = i; j; j /= B, k ++)
	    num[k][j % B] ++;
	 left -= i;
	 dfs(i);
	 left += i;
	 k = 0;
	 for (j = i; j; j /= B, k ++)
	    num[k][j % B] --;
      }
   }
   return 0;
}
int main() {
   int i, j, Case = 1;
   scanf("%d", &T);
   while (T --) {
      scanf("%d%d", &N, &B);
      ret = 0;
      left = N;
      memset(num, 0, sizeof(num));
      dfs(0);
      printf("Case #%d: %d\n", Case ++, ret);
   }
   return 0;
}


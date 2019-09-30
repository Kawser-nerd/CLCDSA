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
int C;
int N;
int all[205];
int main() {
   int i, j, Case = 1;
   scanf("%d", &T);
   while (T --) {
      scanf("%d", &C);
      N = 0;
      for (i = 0; i < C; i ++) {
	 int p, n;
	 scanf("%d%d", &p, &n);
	 while (n --)
	    all[N ++] = p;
      }
      int ret = 0;
      while (1) {
	 int done = 1;
	 sort(all, all + N);
	 for (i = 0; i < N - 1; i ++)
	    if (all[i] == all[i + 1]) {
	       all[i] --;
	       all[i + 1] ++;
	       ret ++;
	       done = 0;
	    }
	 if (done)
	    break;
      }
      printf("Case #%d: %d\n", Case ++, ret);
   }
   return 0;
}


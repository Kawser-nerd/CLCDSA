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
long long all[2][1005];
int main() {
   int i, Case = 1;
   scanf("%d", &T);
   while (T --) {
      scanf("%d", &N);
      for (i = 0; i < N; i ++)
	 scanf("%lld", &all[0][i]);
      for (i = 0; i < N; i ++)
	 scanf("%lld", &all[1][i]);
      sort(all[0], all[0] + N);
      sort(all[1], all[1] + N);
      long long ret = 0;
      for (i = 0; i < N; i ++)
	 ret += all[0][i] * all[1][N - 1 - i];
      printf("Case #%d: %lld\n", Case ++, ret);
   }
   return 0;
}


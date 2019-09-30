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
int T;
int N;
int info[5005][3];
int cnt[5005][2], s;
int ret, limit;
int cmp(const void *a, const void *b) {
   int *pa = (int *)a, *pb = (int *)b;
   if (pa[0] != pb[0])
      return (pa[0] > pb[0] ? 1 : -1);
   if (pa[1] != pb[1])
      return (pa[1] > pb[1] ? 1 : -1);
   return 0;
}
int solve() {
   int i, j;
   multiset <int, greater<int> > all;
   qsort(cnt, s, sizeof(int) * 2, cmp);
   for (i = 0; i < s; i ++) {
      all.insert(cnt[i][1]);
      while (!all.empty() && *(all.begin()) > limit - cnt[i][0])
	 all.erase(all.begin());
      ret = max(ret, (int)all.size());
   }
   return 0;
}
int main() {
   int i, j, k, Case = 1;
   scanf("%d", &T);
   while (T --) {
      scanf("%d", &N);
      ret = 0;
      for (i = 0; i < N; i ++)
	 scanf("%d%d%d", &info[i][0], &info[i][1], &info[i][2]);
      for (i = 0; i < N; i ++) {
	 s = 0;
	 for (j = 0; j < N; j ++)
	    if (info[j][0] <= info[i][0]) {
	       memcpy(cnt[s], info[j] + 1, sizeof(int) * 2);
	       s ++;
	    }
	 limit = 10000 - info[i][0];
	 solve();
      }
      printf("Case #%d: %d\n", Case ++, ret);
   }
   return 0;
}


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
#include <cassert>
#include <complex>
using namespace std;
#define PI 3.14159265358979323846264338327950288
int all[5005][3];
int order[5005];
int tot;
int N, T;
int X, S, R, t;
int cmp(int a, int b) {
   return all[a][2] < all[b][2];
}
int main() {
   int i, j, Case = 1;
   scanf("%d", &T);
   while (T --) {
      scanf("%d%d%d%d%d", &X, &S, &R, &t, &N);
      tot = 0;
      int cnt = 0;
      for (i = 0; i < N; i ++) {
	 int tmp1, tmp2, tmp3;
	 scanf("%d%d%d", &tmp1, &tmp2, &tmp3);
	 if (tmp1 > cnt) {
	    all[tot][0] = cnt;
	    all[tot][1] = tmp1;
	    all[tot][2] = S;
	    tot ++;
	 }
	 cnt = tmp1;
	 all[tot][0] = cnt;
	 all[tot][1] = tmp2;
	 all[tot][2] = S + tmp3;
	 tot ++;
	 cnt = tmp2;
      }
      if (cnt < X) {
	 all[tot][0] = cnt;
	 all[tot][1] = X;
	 all[tot][2] = S;
	 tot ++;
      }
      for (i = 0; i < tot; i ++)
	 order[i] = i;
      sort(order, order + tot, cmp);
      R -= S;
      double ans = 0;
      double left = t;
      for (i = 0; i < tot; i ++) {
	 double tmp = (double)(all[order[i]][1] - all[order[i]][0]) / (double)(all[order[i]][2] + R);
	 double tmpr = min(tmp, left);
	 left -= tmpr;
	 ans += tmpr;
	 ans += (double)(all[order[i]][1] - all[order[i]][0] - tmpr * (double)(all[order[i]][2] + R)) / (double)all[order[i]][2];
      }
      printf("Case #%d: %.10lf\n", Case ++, ans);
   }
   return 0;
}


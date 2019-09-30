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
#define oo 1000000000000000001LL
int T;
long long L;
long long B[105];
long long ans[105][100005];
int N;
long long gcdd(long long a, long long b) {
   return (b ? gcdd(b, a % b) : a);
}
int main() {
   int i, j, Case = 1;
   scanf("%d", &T);
   while (T --) {
      scanf("%lld%d", &L, &N);
      for (i = 0; i < N; i ++)
	 scanf("%lld", &B[i]);
      sort(B, B + N);
      for (i = 0; i <= N - 1; i ++)
	 if (i == 0) {
	    for (j = 0; j < B[N - 1]; j ++)
		  if (j == 0)
		     ans[i][j] = 0;
		  else
		     ans[i][j] = oo;
	 }
	 else {
	    set <pair <long long, int> > all;
	    for (j = 0; j < B[N - 1]; j ++) {
	       ans[i][j] = ans[i - 1][j];
	       all.insert(make_pair(ans[i][j], j));
	    }
	    while (!all.empty()) {
	       j = all.begin() -> second;
	       all.erase(all.begin());
	       if (j + B[i - 1] < B[N - 1])
		  if (ans[i][j + B[i - 1]] > ans[i][j] + 1) {
		     all.erase(make_pair(ans[i][j + B[i - 1]], j + B[i - 1]));
		     ans[i][j + B[i - 1]] = ans[i][j] + 1;
		     all.insert(make_pair(ans[i][j + B[i - 1]], j + B[i - 1]));
		  }
	       if (j + B[i - 1] >= B[N - 1])
		  if (ans[i][j + B[i - 1] - B[N - 1]] > ans[i][j]) {
		     all.erase(make_pair(ans[i][j + B[i - 1] - B[N - 1]], j + B[i - 1] - B[N - 1]));
		     ans[i][j + B[i - 1] - B[N - 1]] = ans[i][j];
		     all.insert(make_pair(ans[i][j + B[i - 1] - B[N - 1]], j + B[i - 1] - B[N - 1]));
		  }
	    }
	 }
      long long ret = oo;
      for (i = 0; i < B[N - 1]; i ++)
	 if ((L - i) % B[N - 1] == 0 && ret > ans[N - 1][i] + (L - i) / B[N - 1])
	    ret = ans[N - 1][i] + (L - i) / B[N - 1];
/*      reverse(B, B + N);
      long long gcd[105];
      gcd[0] = 0;
      for (i = 0; i < N; i ++)
	 gcd[i + 1] = gcdd(gcd[i], B[i]);
      if (L % gcd[N] != 0) {
	 printf("Case %d: IMPOSSIBLE\n", Case ++);
	 continue;
      }
      long long cnt = L;
      long long ret = 0;
      for (i = N - 1; i > 0; i --)
	 while (cnt % gcd[i] != 0) {
	    cnt -= B[i];
	    sol[i] ++;
	    ret ++;
	 }
      sol[0] += cnt / B[0];
      ret += cnt /= B[0];*/
      if (ret == oo)
	 printf("Case #%d: IMPOSSIBLE\n", Case ++);
      else
	 printf("Case #%d: %lld\n", Case ++, ret);
   }
   return 0;
}


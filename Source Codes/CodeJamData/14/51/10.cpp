/* Written by Filip Hlasek 2014 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 1111111
int N, P, Q, R, S;
int cnt[MAXN];

bool can_take(long long n) {
  int groups = 1;
  long long sum = 0;
  REP(i, N) {
    if (cnt[i] > n) return false;
    if (sum + cnt[i] > n) {
      groups++;
      sum = 0;
    }
    sum += cnt[i];
  }
  return groups <= 3;
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  REP(t, T) {
    scanf("%d%d%d%d%d", &N, &P, &Q, &R, &S);
    REP(i, N) cnt[i] = ((long long)i * P + Q) % R + S;

    long long left = 1, right = (long long)4 * MAXN * MAXN;
    while (left < right) {
      long long middle = (left + right) / 2;
      if (can_take(middle)) right = middle;
      else left = middle + 1;
    }
    long long total = 0;
    REP(i, N) total += cnt[i];
    double ans = (double)(total - left) / total;
    printf("Case #%d: %.10lf\n", t + 1, ans);
  }
  return 0;
}

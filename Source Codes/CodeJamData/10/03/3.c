/* There are only N possible starts for the queue */

#include <stdio.h>
#include <string.h>

#define MAX_N 1005

long long g[MAX_N];
long long used[MAX_N];
long long profit[MAX_N];
long long r, k, n;

long long solve(long long start, long long r) {
  long long i, sum, total, old_start, period, nperiods, period_profit;

  for (i=0; i<n; i++) used[i]=-1;

  total = 0;
  for (i=0; i<r; i++) {

    if (used[start]>=0) {
      period = i-used[start];
      period_profit = total - profit[start];
      nperiods = (r-i)/period;
      i += nperiods * period;
      //printf("%lld %lld %lld\n", period, nperiods, i);
      total += nperiods * period_profit;
      if (i>=r) break;
    }

    sum = 0;
    old_start = start;
    while (1) {
      if (sum + g[start] > k) break;
      sum += g[start];
      start = (start+1)%n;
      if (start==old_start) break;
    }
    profit[old_start] = total;
    total += sum;
    used[old_start] = i;
  }

  return total;
}

int main() {
  int i, j, t;
  
  scanf("%d", &t);
  for (i=1; i<=t; i++) {
    scanf("%lld %lld %lld\n", &r, &k, &n);
    for (j=0; j<n; j++)
      scanf("%lld", &g[j]);
    printf("Case #%d: %lld\n", i, solve(0, r));
  }

  return 0;
}

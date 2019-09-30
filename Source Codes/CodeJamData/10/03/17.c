#include <assert.h>
#include <stdio.h>
#include <string.h>

#define MAX_N 1000

int main(int argc, char **argv) {
  int tno, tests, used[MAX_N];
  long long g[MAX_N];
  long long euros[MAX_N];

  assert(argc >= 3);
  freopen(argv[1], "r", stdin);
  freopen(argv[2], "w", stdout);

  scanf("%d", &tests);
  for (tno = 1; tno <= tests; ++tno) {
    long long r, k, earnings, offset, cycle_earnings;
    int i, n, start = 0, cycle_length;

    scanf("%lld%lld%d", &r, &k, &n);
    for (i = 0; i < n; ++i) {
      scanf("%lld", &g[i]);
    }

    memset(used, 0, sizeof(used));
    euros[0] = 0;

    for (i = 1; ; ++i) {
      int j;
      long long count = 0;

      if (used[start]) {
        offset = used[start] - 1;
        cycle_length = i - used[start];
        cycle_earnings = euros[i - 1] - euros[offset];
        break;
      }

      used[start] = i;

      for (j = 0; j < n; ++j) {
        count += g[start];
        if (count > k) {
          count -= g[start];
          break;
        }
        if ((++start) == n) {
          start = 0;
        }
      }

      if (i == 1) {
        euros[i] = count;
      } else {
        euros[i] = euros[i - 1] + count;
      }
    }

    if (r < i) {
      earnings = euros[r];
    } else {
      earnings = euros[offset];
      r -= offset;
      earnings += cycle_earnings * (r / cycle_length);
      if (r % cycle_length) {
        earnings += euros[offset + (r % cycle_length)] - euros[offset];
      }
    }

    printf("Case #%d: %lld\n", tno, earnings);
  }

  return 0;
}

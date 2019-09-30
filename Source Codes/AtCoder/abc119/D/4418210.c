#include <stdio.h>
#include <stdint.h>

int64_t bsrch(int64_t ary[], size_t sz, int64_t v)
{
  size_t low = 0;
  size_t high = sz - 1;

  while (low < high) {
    size_t mid = low + (high - low) / 2;
    if (ary[mid] < v) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  return low;
}

int main(void)
{
  const int64_t inf = 100000000000;
  int a, b, q;
  scanf("%d %d %d", &a, &b, &q);
  int64_t s[a + 2], t[b + 2], x[q];
  for (int i = 1; i <= a; i++) scanf("%lld", &s[i]);
  for (int i = 1; i <= b; i++) scanf("%lld", &t[i]);
  for (int i = 0; i < q; i++) scanf("%lld", &x[i]);
  s[0] = t[0] = -inf;
  s[a + 1] = t[b + 1] = inf;
  for (int i = 0; i < q; i++) {
    int64_t ans = inf;
    int64_t d[4];
    size_t si = bsrch(s, a + 2, x[i]);
    size_t ti = bsrch(t, b + 2, x[i]);
    int64_t s_east = s[si] - x[i];
    int64_t s_west = x[i] - s[si - 1];
    int64_t t_east = t[ti] - x[i];
    int64_t t_west = x[i] - t[ti - 1];
    d[0] = s_east > t_east ? s_east : t_east;
    d[1] = s_west > t_west ? s_west : t_west;
    d[2] = s_west > t_east ? s_west + t_east * 2 : s_west * 2 + t_east;
    d[3] = t_west > s_east ? t_west + s_east * 2 : t_west * 2 + s_east;
    for (int j = 0; j < 4; j++) {
      if (ans > d[j]) ans = d[j];
    }
    printf("%lld\n", ans);
  }
} ./Main.c: In function ‘main’:
./Main.c:27:38: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘int64_t * {aka long int *}’ [-Wformat=]
   for (int i = 1; i <= a; i++) scanf("%lld", &s[i]);
                                      ^
./Main.c:28:38: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘int64_t * {aka long int *}’ [-Wformat=]
   for (int i = 1; i <= b; i++) scanf("%lld", &t[i]);
                                      ^
./Main.c:29:37: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘int64_t * {aka long int *}’ [-Wformat=]
   for (int i = 0; i < q; i++) scanf("%lld", &x[i]);
                                     ^
./Main.c:48:12: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘int64_t {aka long int}’ [-Wformat=]
     printf("%lld\n", ans);
            ^
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute ...
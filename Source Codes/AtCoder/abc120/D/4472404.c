#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>

int64_t root(int64_t u[], int64_t i)
{
  if (u[i] < 0) return i;
  return u[i] = root(u, u[i]);
}

int64_t size(int64_t u[], int64_t i)
{
  return -u[root(u, i)];
}

int main(void)
{
  int64_t n, m;
  scanf("%" SCNd64 "%" SCNd64, &n, &m);
  int64_t a[m], b[m], ans[m], u[n];
  for (int i = 0; i < n; i++) u[i] = -1;
  for (int i = 0; i < m; i++) {
    scanf("%" SCNd64 "%" SCNd64, &a[i], &b[i]);
    a[i]--;
    b[i]--;
  }
  ans[m - 1] = n * (n - 1) / 2;
  for (int i = m - 1; i > 0; i--) {
    ans[i - 1] = ans[i];
    if (root(u, a[i]) != root(u, b[i])) {
      int64_t x = root(u, a[i]);
      int64_t y = root(u, b[i]);
      if (size(u, a[i]) < size(u, b[i])) {
        int64_t t = x;
        x = y;
        y = t;
      }
      ans[i - 1] -= u[x] * u[y];
      u[x] += u[y];
      u[y] = x;
    }
  }
  for (int i = 0; i < m; i++) {
    printf("%" PRId64 "\n", ans[i]);
  }
} ./Main.c: In function ‘main’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%" SCNd64 "%" SCNd64, &n, &m);
   ^
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%" SCNd64 "%" SCNd64, &a[i], &b[i]);
     ^
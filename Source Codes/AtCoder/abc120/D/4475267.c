#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>

static int64_t u[100000];

int64_t root(int64_t i)
{
  if (u[i] < 0) return i;
  return u[i] = root(u[i]);
}

int main(void)
{
  int64_t n, m;
  scanf("%" SCNd64 "%" SCNd64, &n, &m);
  int64_t a[m], b[m], ans[m];
  for (int i = 0; i < n; i++) u[i] = -1;
  for (int i = 0; i < m; i++) {
    scanf("%" SCNd64 "%" SCNd64, &a[i], &b[i]);
    a[i]--;
    b[i]--;
  }
  ans[m - 1] = n * (n - 1) / 2;
  for (int i = m - 1; i > 0; i--) {
    ans[i - 1] = ans[i];
    int64_t ra = root(a[i]);
    int64_t rb = root(b[i]);
    if (ra != rb) {
      ans[i - 1] -= u[ra] * u[rb];
      if (u[ra] < u[rb]) {
        u[ra] += u[rb];
        u[rb] = ra;
      } else {
        u[rb] += u[ra];
        u[ra] = rb;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    printf("%" PRId64 "\n", ans[i]);
  }
} ./Main.c: In function ‘main’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%" SCNd64 "%" SCNd64, &n, &m);
   ^
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%" SCNd64 "%" SCNd64, &a[i], &b[i]);
     ^
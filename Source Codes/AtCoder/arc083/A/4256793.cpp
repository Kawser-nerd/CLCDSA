#include <cstdio>
#include <algorithm>
#include <vector>

int main() {
  int A, B, C, D, E, F;
  scanf("%d %d %d %d %d %d", &A, &B, &C, &D, &E, &F);

  std::vector<int> a(F+1), b(F+1);
  for (int i = 0; i <= F; i += A)
    for (int j = 0; j <= F; j += B) {
      if (100*(i+j) > F) break;
      a[100*(i+j)] = 1;
    }

  for (int i = 0; i <= F; i += C)
    for (int j = 0; j <= F; j += D) {
      if (i+j > F) break;
      b[i+j] = 1;
    }

  int res_a = 1;
  int res_b = 0;
  for (int ai = 0; ai <= F; ++ai) {
    if (!a[ai]) continue;
    for (int bi = 0; bi <= F; ++bi) {
      if (!b[bi]) continue;
      if (ai+bi > F) continue;
      if (bi*100 > E*ai) continue;
      if (res_b*(ai+bi) <= bi*(res_a+res_b)) {
        res_a = ai;
        res_b = bi;
      }
    }
  }
  printf("%d %d\n", res_a+res_b, res_b);
}
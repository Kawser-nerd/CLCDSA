#include <cstdio>
#include <cstdint>
#include <map>
#include <algorithm>

int main() {
  int N;
  scanf("%d", &N);

  std::map<int, int> F;
  for (int i = 0; i < N; ++i) {
    int a;
    scanf("%d", &a);
    ++F[a];
  }

  intmax_t res = 0;
  for (const auto& p: F) {
    int a = p.first;
    int k = p.second;
    if (k == a) continue;
    if (k < a) {
      res += k;
    } else {
      res += k-a;
    }
  }
  printf("%jd\n", res);
}
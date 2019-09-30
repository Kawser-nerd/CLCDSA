#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> A(3);
  int even = 0;
  int odd = 0;
  for (auto& ai: A) {
    scanf("%d", &ai);
    ++((ai % 2 > 0)? odd:even);
  }

  int res = 0;
  if (even == 2) {
    for (auto& ai: A)
      if (ai % 2 == 0) ++ai;
    ++res;
  } else if (odd == 2) {
    for (auto& ai: A)
      if (ai % 2 == 1) ++ai;
    ++res;
  }

  std::sort(A.begin(), A.end());
  res += (A[2]-A[1]) / 2;
  res += (A[2]-A[0]) / 2;
  printf("%d\n", res);
}
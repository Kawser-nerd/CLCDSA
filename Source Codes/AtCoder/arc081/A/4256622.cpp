#include <cstdio>
#include <cstdint>
#include <set>
#include <vector>
#include <algorithm>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<intmax_t> L;
  std::set<intmax_t> A;
  for (size_t i = 0; i < N; ++i) {
    intmax_t a;
    scanf("%jd", &a);
    if (A.count(a)) {
      A.erase(a);
      L.push_back(a);
    } else {
      A.insert(a);
    }
  }
  std::sort(L.rbegin(), L.rend());
  if (L.size() < 2) {
    puts("0");
  } else {
    printf("%jd\n", L[0]*L[1]);
  }
}
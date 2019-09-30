#include <cstdio>
#include <cstdint>
#include <deque>
#include <algorithm>

int main() {
  size_t n;
  scanf("%zu", &n);

  std::deque<int> b;
  for (size_t i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    if (i % 2 == 0) {
      b.push_back(a);
    } else {
      b.push_front(a);
    }
  }
  if (n % 2 == 1)
    std::reverse(b.begin(), b.end());

  for (size_t i = 0; i < n; ++i)
    printf("%d%c", b[i], i+1<n? ' ':'\n');
}
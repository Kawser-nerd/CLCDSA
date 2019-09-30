#include <cstdio>
#include <algorithm>

const int N = 26;

int n, p[N];

int main() {
  int tcase;
  scanf("%d", &tcase);
  for (int tid = 1; tid <= tcase; ++tid) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
    printf("Case #%d:", tid);
    do {
      int i = std::max_element(p, p + n) - p;
      int t = p[i];
      if (t == 0) break;
      putchar(' ');
      int cnt = 0;
      for (int j = 0; j < n; ++j) if (p[j] == t) ++cnt;
      if (cnt == 2) {
        for (int j = 0; j < n; ++j) if (p[j] == t) --p[j], putchar(j + 'A');
      } else {
        putchar(i + 'A');
        --p[i];
      }
    } while (1);
    putchar('\n');
  }
  return 0;
}

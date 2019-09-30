#include <cstdio>

int const kMaxN = 100000;

int g_count[kMaxN];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    ++g_count[a];
    ++g_count[b];
  }

  bool allEven = true;
  for (int i = 0; i < n && allEven; ++i)
    allEven = allEven && g_count[i] % 2 == 0;

  printf("%s\n", allEven ? "YES" : "NO");
  return 0;
}
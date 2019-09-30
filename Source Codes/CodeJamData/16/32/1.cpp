#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int b;
    long long m;
    cin >> b >> m;
    if (m > (1LL << (b - 2))) {
      puts("IMPOSSIBLE");
      continue;
    }
    puts("POSSIBLE");
    for (int i = 0; i < b; i++) {
      for (int j = 0; j < b; j++) {
        if (i < j && j < b - 1) {
          putchar('1');
          continue;
        }
        if (j == b - 1 && (i == 0 || ((m - 1) & (1LL << (i - 1))))) {
          putchar('1');
          continue;
        }
        putchar('0');
      }
      putchar('\n');
    }
  }
  return 0;
}

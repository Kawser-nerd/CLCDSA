#include <bits/stdc++.h>

using namespace std;

string good[77777];
char a[77777];
char b[77777];
string bad;

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
      cin >> good[i];
    }
    cin >> bad;
    bool cont = false;
    for (int i = 0; i < n; i++) {
      if (good[i] == bad) {
        cont = true;
        break;
      }
    }
    if (cont) {
      puts("IMPOSSIBLE");
      continue;
    }
    int na = 0, nb = 0;
    int ptr = 0;
    for (int i = 0; ; i++) {
      char c = '0' + (i & 1);
      if (bad[ptr] == c) {
        ptr++;
        if (ptr == l) {
          break;
        }
      }
      a[na++] = c;
    }
    char last = '0';
    for (int i = 0; i < l; i++) {
      if (bad[i] == last) {
        b[nb++] = '0' + '1' - bad[i];
      }
      b[nb++] = '?';
      last = bad[i];
    }
    if (na == 0) {
      a[na++] = '1';
    }
    for (int i = 0; i < na; i++) {
      putchar(a[i]);
    }
    printf(" ");
    for (int i = 0; i < nb; i++) {
      putchar(b[i]);
    }
    printf("\n");
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

char s[777][777];

int main() {
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d:\n", qq);
    int h, w;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
      scanf("%s", s[i]);
    }
    for (int i = 0; i < h; i++) {
      char last = '?';
      for (int j = 0; j < w; j++) {
        if (s[i][j] != '?') last = s[i][j];
        s[i][j] = last;
      }
    }
    for (int i = 0; i < h; i++) {
      char last = '?';
      for (int j = w - 1; j >= 0; j--) {
        if (s[i][j] != '?') last = s[i][j];
        s[i][j] = last;
      }
    }
    for (int j = 0; j < w; j++) {
      char last = '?';
      for (int i = 0; i < h; i++) {
        if (s[i][j] != '?') last = s[i][j];
        s[i][j] = last;
      }
    }
    for (int j = 0; j < w; j++) {
      char last = '?';
      for (int i = h - 1; i >= 0; i--) {
        if (s[i][j] != '?') last = s[i][j];
        s[i][j] = last;
      }
    }
    for (int i = 0; i < h; i++) {
      puts(s[i]);
    }
  }
  return 0;
}

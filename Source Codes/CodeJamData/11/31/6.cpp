#include <cstdio>
#include <algorithm>

using namespace std;

char s[100][100];

int main (void) {
  int tn;
  scanf ("%d", &tn);
  for (int tt = 1; tt <= tn; tt++) {
    int h, w;
    scanf ("%d%d", &h, &w);
    for (int i = 0; i < h; i++) {
      scanf ("%s", s[i]);
    }
    int ok = 1;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (s[i][j] == '#') {
          if (s[i + 1][j] == '#' && s[i][j + 1] == '#' && s[i + 1][j + 1] == '#') {
            s[i][j] = '/';
            s[i + 1][j] = '\\';
            s[i][j + 1] = '\\';
            s[i + 1][j + 1] = '/';
          } else {
            ok = 0;
          }
        }
      }
    }
    printf ("Case #%d:\n", tt);
    if (ok) {
      for (int i = 0; i < h; i++) {
        puts (s[i]);
      }
    } else {
      puts ("Impossible");
    }
  }
  return 0;
}
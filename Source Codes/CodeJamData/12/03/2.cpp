#include <cassert>
#include <cstdio>
#include <map>
#include <set>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int mark[9999999];

int main(void) {
  int tn, nt;
  scanf("%d", &nt);
  for (tn=1; tn<=nt; tn++) {
    printf ("Case #%d: ", tn);

    int a, b;
    scanf("%d %d", &a, &b);
    memset (mark, 0, sizeof (mark));

    int ans = 0;
    for (int i = a; i <= b; i++) {
      int d[10];
      int x = i, j = 0;
      while (x > 0) {
        d[j++] = x % 10;
        x /= 10;
      }
      for (int k = 0; k < j; k++) {
        int cur = 0;
        for (int t = 0; t < j; t++) {
          cur = cur * 10 + d[(k - t + j) % j];
        }
        if (i < cur && cur <= b && mark[cur] != i) {
          mark[cur] = i;
          ans++;
        }
      }
    }

    fprintf (stderr, "Case #%d: \n", tn);
    printf ("%d\n", ans);
  }

  return 0;
}

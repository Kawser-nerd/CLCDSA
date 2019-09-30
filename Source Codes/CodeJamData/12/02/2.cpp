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

int a[105];

int main(void) {
  int tn, nt;
  scanf("%d", &nt);
  for (tn=1; tn<=nt; tn++) {
    printf ("Case #%d: ", tn);

    int res = 0, n, s, p;
    scanf("%d%d%d", &n, &s, &p);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (a[i] <= 1) {
        res += (a[i] >= p);
        i--, n--;
      }
    }
    assert (s <= n);
    sort (a, a + n);
    reverse (a, a + n);

    for (int i = 0; i < n; i++) {
      if ((a[i] + 2) / 3 >= p) {
        res++;
        continue;
      }
      if ((a[i] + 1) / 3 + 1 >= p && s > 0) {
        res++;
        s--;
        continue;
      }
    }


    printf ("%d\n", res);
  }

  return 0;
}

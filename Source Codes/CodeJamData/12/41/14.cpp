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

int d[10005], l[10005];
int besth[10005];
int n;
int ans;

int main(void) {
  int tn, nt;
  scanf("%d", &nt);
  for (tn = 1; tn <= nt; tn++) {
    printf ("Case #%d: ", tn);
    fprintf (stderr, "Case #%d: \n", tn);

    d[0] = 0;
    l[0] = 0;
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d %d", &d[i], &l[i]);
    }
    scanf("%d", &d[n + 1]);

    memset (besth, -1, sizeof (besth));

    besth[1] = d[1];

    for (int i = 1; i <= n; i++)
      if (besth[i] >= 0)
      for (int j = i + 1; j <= n + 1 && d[j] <= besth[i] + d[i]; j++) {
        besth[j] = max(besth[j], min (d[j] - d[i], l[j]));
      }

    puts (besth[n + 1] >= 0 ? "YES" : "NO");
  }

  return 0;
}

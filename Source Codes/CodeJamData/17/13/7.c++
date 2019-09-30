#include <cassert>
#include <cstdio>

int main () {
  int tn;
  assert (scanf ("%d", &tn) == 1);
  for (int tt = 1; tt <= tn; tt++) {
    int hd, ad, hk, ak, b, d;
    assert (scanf ("%d%d%d%d%d%d", &hd, &ad, &hk, &ak, &b, &d) == 6);
    int ans = (int)1e9;
    for (int bb = 0; bb <= 100; bb++) {
      for (int dd = 0; dd <= 100; dd++) {
        int tb = bb, td = dd;
        int thd = hd, thk = hk;
        int tad = ad, tak = ak;
        int res = 0;
        while (thd > 0 && thk > 0) {
          res++;
          if (thd <= tak - d * !!td && !(td == 0 && tb == 0 && tad >= thk)) {
            // heal!
            if (thd == hd - tak) {
              // noway: must heal, cannot win
              thd = -1;
              break;
            }
            thd = hd;
          } else if (td) {
            td--;
            tak = tak - d;
          } else if (tb) {
            tb--;
            tad = tad + b;
          } else {
            thk = thk - tad;
          }
          if (thk > 0) {
            thd = thd - tak;
          }
        }
        if (thd > 0 && res < ans)
          ans = res;
      }
    }
    if (ans == (int)1e9)
      printf ("Case #%d: IMPOSSIBLE\n", tt);
    else
      printf ("Case #%d: %d\n", tt, ans);
  }
  return 0;
}


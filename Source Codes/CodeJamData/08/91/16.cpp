#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

#define m 100

int a[m], b[m], c[m], n, nt;

int main()
{
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  scanf("%d", &nt);
  forn (tt, nt)
  {
    fprintf(stderr, "Case #%d:\n", tt + 1);
    printf("Case #%d: ", tt + 1);

    scanf("%d", &n);
    int ans = 0;
    forn (i, n)
      scanf("%d%d%d", &a[i], &b[i], &c[i]);
    for (int A = 0; A <= 10000; A++)
      for (int B = 0; A + B <= 10000; B++)
      {
        int C = 10000 - A - B, cnt = 0;
        forn (i, n)
          cnt += a[i] <= A && b[i] <= B && c[i] <= C;
        ans = max(ans, cnt);
      }
    printf("%d", ans);

    fprintf(stderr, "Case #%d done\n", tt + 1);
    puts("");
  }
  return 0;
}

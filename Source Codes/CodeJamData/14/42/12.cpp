/**         
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2014.05.31
 */

#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int N = 1e3 + 1;

int n, a[N], b[N];

void solve()
{
  scanf("%d", &n);
  assert(n < N);
  forn(i, n)
    scanf("%d", &a[i]), b[i] = a[i];
  sort(b, b + n);

  int ans = 0;
  forn(_, n)
  {
    int i = find(a, a + n, b[_]) - a;
    int l = 0, r = 0;
    forn(j, n)
      if (a[j] > a[i])
        (j < i ? l : r)++;
    ans += min(l, r);
  }
  printf("%d\n", ans);
}

int main()
{
  int tn;
  scanf("%d", &tn);
  forn(t, tn)
  {
    printf("Case #%d: ", t + 1);
    solve();
  }
  return 0;
}

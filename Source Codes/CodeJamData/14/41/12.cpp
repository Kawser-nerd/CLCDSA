/**         
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2014.05.31
 */

#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int N = 1e4;

int n, x, a[N];

void solve()
{
  scanf("%d%d", &n, &x);
  forn(i, n)
    scanf("%d", &a[i]);
  sort(a, a + n);

  int l = 0, r = n - 1, ans = 0;
  while (l < r)
    if (a[l] + a[r] <= x)
      ans++, l++, r--;
    else
      ans++, r--;
  printf("%d\n", ans + (l <= r));
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

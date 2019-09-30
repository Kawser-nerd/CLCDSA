#include <cassert>
#include <cstdio>

#include <queue>

using namespace std;

int main () {
  int tn;
  assert (scanf ("%d", &tn) == 1);
  for (int tt = 1; tt <= tn; tt++) {
    long long k, n;
    assert (scanf ("%lld%lld\n", &n, &k) == 2);
    queue <pair <long long, long long>> q;
    q.push (make_pair (n, 1ll));
    while (true) {
      assert (q.size ());
      auto x = q.front (); q.pop ();
      while (q.size () && q.front ().first == x.first) {
        x.second += q.front ().second;
        q.pop ();
      }
      assert (x.first > 0);
      long long l = x.first / 2, r = x.first - 1 - l;
      // fprintf (stderr, "[times: %lld] split [%lld] -> [%lld + 1 + %lld]\n", x.second, x.first, l, r);
      if (k <= x.second) {
        printf ("Case #%d: %lld %lld\n", tt, l, r);
        break;
      }
      k -= x.second;
      q.push (make_pair (l, x.second));
      q.push (make_pair (r, x.second));
    }
  }
  return 0;
}


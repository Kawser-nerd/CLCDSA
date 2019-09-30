#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

typedef long long ll;

using namespace std;



int main (void) {
  int tn;
  scanf ("%d", &tn);
  for (int tt = 1; tt <= tn; tt++) {
    fprintf (stderr, "tt = %d\n", tt);
    printf ("Case #%d: ", tt);

    int n;
    cin >> n;
    ll l, r;
    cin >> l >> r;

    vector <ll> v(n), gc(n + 1), lc(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort (v.begin(), v.end());

    lc[0] = 1;
    ll inf = 1000000000000000000ll;
    for (int i = 0; i < n; i++) {
      ll t = v[i] / __gcd (v[i], lc[i]);

      if (lc[i]  < inf / t) {
        lc[i + 1] = lc[i] * t;
      } else {
        lc[i + 1] = inf;
      }
    }

    gc[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
      gc[i] = __gcd(v[i], gc[i + 1]);
    }

    ll res = -1;

    for (int i = 0; i <= n; i++) {
      if (lc[i] != inf && (i == n || lc[i + 1] != lc[i])) {
        ll lt = l / lc[i] + (l % lc[i] != 0),
           rt = r / lc[i];
 //       cerr << "lc = " << lc[i] << " " << "(" << lt << ";" << r << ")\n";
//        cerr << "gc = " << gc[i] << endl;

        if (lt <= rt && gc[i] % lc[i] == 0) {
          ll x = gc[i] /  lc[i];
          ll md = -1;
//          cerr << "x = " << x << endl;
          for (ll t = 1; t * t <= x; t++) {
            if (x % t == 0) {
              ll u = x / t;
              if (lt <= u && u <= rt) {
                if (md == -1 || md > u) {
                  md = u;
                }
              }
              u = t;
              if (lt <= u && u <= rt) {
                if (md == -1 || md > u) {
                  md = u;
                }
              }

            }
          }
          if (x == 0) {
            md = lt;
          }
          if (md != -1) {
            ll test = lc[i] * md;
            if (res == -1 || res > test) {
              res = test;
            }
          }
        }
      }
    }

    if (res == -1) {
      puts ("NO");
    } else {
      cout << res << endl;
    }

  }
  return 0;
}
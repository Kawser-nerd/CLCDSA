#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define REP(i,n) FOR(i,0,n)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define INF 1000000000
#define X first
#define Y second
#define pb push_back

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int tt;
  cin >> tt;
  REP (t, tt) {
    cout << "Case #" << t+1 << ": ";
    int n;
    cin >> n;
    vector <pair<int, int> > a(n);
    REP (i, n)
      cin >> a[i].X >> a[i].Y;

    int s = 0;
    int res = 0;

    while (s < 2*n) {
      bool ok = false;

      REP (i, n) {
        if (a[i].Y <=s) {
          s++;
          if (a[i].X <=s)
            s++;
          a[i].Y = INF;
          a[i].X = INF;
          res++;
          ok = true;
        }
      }
      if (ok) continue;

      REP(i, n) {
        if (a[i].X <=s) {
          s++;
          a[i].X = INF;
          res++;
          ok = true;
          break;
        }
      }

      if (!ok)
        break;
    }

    if (s<2*n)
      cout << "Too Bad" << endl;
    else
      cout << res << endl;
  }

  return 0;
}

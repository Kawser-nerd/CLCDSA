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

typedef long double cfloat;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int tt;
  cin >> tt;
  REP (t, tt) {
    printf("Case #%d: ", t+1);

    int a, b;
    cin >> a >> b;

    vector<cfloat> p(a);

    REP (i, a)
      cin >> p[i];

    cfloat res = b+2;

    cfloat pp = 1;

    REP (i, a+1) {
      res = min(res, (a-i + b-i+1) + (1-pp)*(b+1));

      if (i<p.size())
        pp *= p[i];
    }

    printf("%.6Lf\n", res);
  }

  return 0;
}

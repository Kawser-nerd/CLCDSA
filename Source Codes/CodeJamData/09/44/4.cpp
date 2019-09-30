#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair

typedef double dbl;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

struct pnt
{
  dbl x, y;

  pnt( dbl _x = 0, dbl _y = 0 ) : x(_x), y(_y) { }

  pnt operator + ( pnt p ) { return pnt(x + p.x, y + p.y); }
  pnt operator - ( pnt p ) { return pnt(x - p.x, y - p.y); }
  pnt operator * ( dbl k ) { return pnt(x * k, y * k); }
  pnt operator / ( dbl k ) { return pnt(x / k, y / k); }

  dbl operator * ( pnt p ) { return x * p.y - y * p.x; }
  dbl operator ^ ( pnt p ) { return x * p.x + y * p.y; }

  dbl d2() { return x * x + y * y; }
  dbl d() { return sqrt(d()); }

  pnt norm() { return *this / d(); }
  pnt ort() { return pnt(-y, x); }
};

const int maxn = 43;

int n, an;
pnt p[maxn], a[maxn * maxn];
dbl r[maxn];
ll s[maxn * maxn];

dbl sqr( dbl x )
{
  return x * x;
}

int Solve( dbl R )
{
  if (n == 1)
    return R >= r[0];
  an = 0;
  forn(i, n)
    a[an++] = p[i];
  forn(i, n)
    forn(j, i)
      if (mp(p[i].x, p[i].y) != mp(p[j].x, p[j].y))
        if (r[i] <= R && r[j] <= R)
        {
          dbl r1 = R - r[i], r2 = R - r[j];
          pnt c2 = p[j] - p[i];

          dbl A = 2 * c2.x;
          dbl B = 2 * c2.y;
          dbl C = sqr(r2) - sqr(c2.x) - sqr(c2.y) - sqr(r1);
          dbl no = hypot(A, B);
          C /= no, A /= no, B /= no;

          dbl d = sqrt(fabs(r1 * r1 - C * C));
          a[an++] = p[i] - pnt(A, B) * C + pnt(-B, A) * d;
          a[an++] = p[i] - pnt(A, B) * C - pnt(-B, A) * d;
        }

  memset(s, 0, sizeof(s));
  forn(i, an)
    forn(j, n)
      if (R >= r[j] && (p[j] - a[i]).d2() <= sqr(R - r[j]) + 1e-9)
        s[i] |= (ll)1 << j;

  ll all = ((ll)1 << n) - 1;
  forn(i, an)
    forn(j, i)
      if ((s[i] | s[j]) == all)
        return 1;
  return 0;
}

int main()
{
  int tn;
  scanf("%d", &tn);
  for (int tt = 1; tt <= tn; tt++)
  {
    fprintf(stderr, "%d\n", tt);
    scanf("%d", &n);
    forn(i, n)
      scanf("%lf%lf%lf", &p[i].x, &p[i].y, &r[i]);

    dbl mi = 0, ma = 1e4;
    forn(k, 60)
    {
      dbl R = (mi + ma) * 0.5;
      if (Solve(R))
        ma = R;
      else
        mi = R;
    }
    printf("Case #%d: %.20lf\n", tt, mi);
  }
  return 0;
}

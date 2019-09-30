#include <cstdio>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

typedef long double dbl;
typedef pair <dbl, dbl> pnt;

#define maxn 1000010

#define x first
#define y second
#define eps 1e-13

pnt read() {
  dbl x, y;
  cin >> x >> y;
  return pnt(x, y);
}

pnt operator - (pnt a, pnt b) {return pnt(a.x - b.x, a.y - b.y);}
dbl operator % (pnt a, pnt b) {return a.x * b.x + a.y * b.y;}

dbl f(dbl r, dbl x) {
  if (x < 0) {
    return M_PI * r * r - f(r, -x);
  }
  dbl y = sqrt(max(r * r - x * x, (dbl)0));
  return atan2(y, x) * r * r - x * y;
}

dbl get(pnt a, pnt b, pnt c) {
  dbl ab = hypot(a.x - b.x, a.y - b.y);
  dbl r = hypot(a.x - c.x, a.y - c.y);

  if (ab < eps) {
    return M_PI * r * r;
  }
  
  dbl x = (c - a) % (b - a) / ab;
  return f(r, x);
}

int main (void) {
  int tn;
  scanf("%d", &tn);

  for (int t = 1; t <= tn; t++) {
    printf("Case #%d: ", t);
    int n, m;
    cin >> n >> m;
    assert(n == 2);
    pnt a = read(), b = read();
    for (int i = 0; i < m; i++) {
      pnt c = read();
      printf("%.20lf%c", (double)(get(a, b, c) + get(b, a, c)), " \n"[i + 1 == m]);
    }
  }

  return 0;
} 
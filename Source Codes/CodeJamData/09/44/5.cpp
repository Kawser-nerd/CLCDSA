#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <sstream>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define eps 1e-12

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define forit(i, s) for(__typeof(s.begin()) i = s.begin(); i != s.end(); i++)
#define sz(v)((v).size())

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;

using namespace std;

struct pnt
{
  dbl x, y;
  pnt( dbl _x = 0 , dbl _y = 0 ) : x(_x), y(_y){}
  pnt rot( dbl co, dbl si ){return pnt(x * co - y * si, x * si + y * co);}
  dbl d(){return sqrt(x * x + y * y);}
};

bool operator < ( pnt a, pnt b ){return a.x < b.x - eps || a.x < b.x + eps && a.y < b.y - eps;}
pnt operator + ( pnt a, pnt b ){return pnt(a.x + b.x, a.y + b.y);}
pnt operator - ( pnt a, pnt b ){return pnt(a.x - b.x, a.y - b.y);}


#define maxn 55

pnt _p[maxn];
dbl _r[maxn];
int n;

dbl _R;

vector <ll> ch;

void add( pnt q )
{
  ll code = 0;
  for (int i = 0; i < n; i++)
    if ((_p[i] - q).d() + _r[i] < _R + eps)
      code |= (1ll << i);
//  cerr << q.x << " " << q.y << " " << code << endl;
  ch.push_back(code);
}


void add( pnt c1, dbl r1, pnt c2, dbl r2)
{
  dbl d = (c1 - c2).d();

  if (d < eps)
    return;

  dbl x = (r1 * r1 + d * d - r2 * r2) / (2 * d);
  if (x > r1 + eps)
    return;
  dbl y = sqrt(max((dbl)0.0, r1 * r1 - x * x));

  dbl co = (c2.x - c1.x) / d,
         si = (c2.y - c1.y) / d;

  add(pnt(x, y).rot(co, si) + c1);
  add(pnt(x, -y).rot(co, si) + c1);
}


bool ok( dbl R )
{
  _R = R;

  ch.clear();
  for (int i = 0; i < n; i++)
  {
    add(_p[i]);
    for (int j = i + 1; j < n; j++)
      add(_p[i], R - _r[i], _p[j], R - _r[j]);
  }

  ll need = (1ll << n) - 1;
  for (int i = 0; i < (int)ch.size(); i++)
    for (int j = i; j < (int)ch.size(); j++)
      if ((ch[i] | ch[j]) == need)
        return true;
  return false;
}

int main( void )
{
  int tn;
  scanf("%d", &tn);

  for (int tt = 1; tt <= tn; tt++)
  {
    cerr << tt << endl;
    printf("Case #%d: ", tt);

    scanf("%d", &n);

    dbl l = 0, r = 1e10;
    for (int i = 0; i < n; i++)
    {
      cin >> _p[i].x >> _p[i].y >> _r[i];
      l = max(_r[i], l);
    }

    for (int t = 0; t < 300; t++)
    {
      dbl c = (l + r) / 2;
      if (ok(c))
        r = c;
      else
        l = c;
    }

    printf("%.20lf\n", (double)r);
  }

  return 0;
}
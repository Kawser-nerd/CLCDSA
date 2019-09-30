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

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int maxp = (int)1e6 + 10;
const int maxn = 43;

int k, d, x[maxn];
int pn, p[maxp], is[maxp];

int MOD;

inline int Mul( int a, int b )
{
  return ((ll)a * b) % MOD;
}

int Pow( int a, int b)
{
  int r = 1;
  while (b)
  {
    if (b & 1)
      r = Mul(r, a);
    a = Mul(a, a);
    b >>= 1;
  }
  return r;
}

int Div( int a, int b )
{
  return Mul(a, Pow(b, MOD - 2));
}                              

int main()
{
  for (int i = 2; i < maxp; i++)
    if (!is[i])
    {
      p[pn++] = i;
      for (int j = i + i; j < maxp; j += i)
        is[j] = 1;
    }

  int tn;
  scanf("%d", &tn);
  for (int tt = 1; tt <= tn; tt++)
  {
    fprintf(stderr, "%d\n", tt);
    printf("Case #%d: ", tt);

    scanf("%d%d", &d, &k);
    forn(i, k)
      scanf("%d", &x[i]);

    int ma = 1;
    forn(i, d)
      ma *= 10;

    if (k <= 2)
    {
      if (k == 2 && x[0] == x[1])
        printf("%d\n", x[0]);
      else
        puts("I don't know.");
      continue;
    }
    if (x[0] == x[1])
    {
      printf("%d\n", x[0]);
      continue;
    }

    fprintf(stderr, "%d %d pn=%d ma=%d\n", d, k, pn, ma);

    set <int> value;
    forn(i, pn) if (p[i] <= ma)
    {
      if (sz(value) > 1)
        break;
      MOD = p[i];
      int a = Div(x[2] - x[1], x[1] - x[0]);
      a = (a % MOD + MOD) % MOD;

      int bad = 0;
      forn(j, k)
        if (x[j] >= p[i])
          bad = 1;
      if (bad)
        continue;
      
      int b = (x[1] - (ll)x[0] * a) % p[i];
      if (b < 0)
        b += p[i];

//        fprintf(stderr, "p=%d a=%d b=%d\n", p[i], a, b);

      forn(j, k - 1)
        if (((ll)x[j] * a + b - x[j + 1]) % p[i] != 0)
          bad = 1;
      if (!bad)
        value.insert(((ll)x[k - 1] * a + b) % p[i]);
    }

    assert(value.size());
    if (value.size() > 1)
      puts("I don't know.");
    else
      printf("%d\n", *value.begin());
  }
  return 0;
}


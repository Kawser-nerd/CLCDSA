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

const int maxn = 73;
const int MOD = (int)1e9 + 7;

ll n;
int b, an, a[maxn];

int C[maxn][maxn], fact[maxn];
int res[maxn][maxn][maxn];
int num[maxn][maxn * maxn];

inline void Add( int &a, int b )
{
  if ((a += b) >= MOD)
    a -= MOD;
}

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

int F( int i, int h, int add )
{
  if (i == an)
    return (add == 0 && h == 0);

  int &r = res[i][h][add];
  if (r != -1)
    return r;
  r = 0;

  int mi = a[i] - add;
  if (mi < 0)
    mi += b;

  forn(is0, 2)
    for (int s = mi; s <= h * b; s += b)
    {
      if (is0 > h)
        continue;

      int koef = num[h - is0][s];
      int sum = add + s;
      sum /= b;

      int tmp = Mul(koef, fact[h]);
      forn(end, h - is0 + 1)
        Add(r, Mul(C[h - is0][end], Mul(tmp, F(i + 1, h - end, sum))));
    }
//  printf("i=%d h=%d add=%d : %d\n", i, h, add, r);
  return r;
}

int main()
{
  fact[0] = 1;
  forn(i, maxn) if (i)
    fact[i] = Mul(fact[i - 1], i);
  C[0][0] = 1;
  forn(i, maxn - 1)
    forn(j, maxn - 1)
      Add(C[i + 1][j + 1], C[i][j]), Add(C[i + 1][j], C[i][j]);

  int tn;
  scanf("%d", &tn);
  for (int tt = 1; tt <= tn; tt++)
  {
    fprintf(stderr, "%d\n", tt);

    scanf("%I64d%d", &n, &b);
    fprintf(stderr, "n=%I64d b=%d\n", n, b);
    an = 0;
    while (n)
      a[an++] = n % b, n /= b;
    
    memset(num, 0, sizeof(num));
    memset(res, -1, sizeof(res));

    num[0][0] = 1;
    for (int i = 1; i < b; i++)
    {
      int ma = i * i;
      for (int k = i - 1; k >= 0; k--)
        forn(sum, ma)
          Add(num[k + 1][sum + i], num[k][sum]);
    }
    fprintf(stderr, "!\n");

    int sum = 0;
    forn(num, b + 1)
    {
      int x = F(0, num, 0);
      for (int i = 1; i <= num; i++)
        x = Div(x, i);
      Add(sum, x);
    }

    printf("Case #%d: %d\n", tt, sum);
  }
  return 0;
}
        



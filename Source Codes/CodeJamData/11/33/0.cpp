/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <ctime>
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
#include <fstream>

using namespace std;

#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%Ld"
#endif

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair

#define EOL(i, n) " \n"[i == (n) - 1]
#define LEN(a) (int)(sizeof(a) / sizeof(a[0]))
#define IS(a, i) (((a) >> (i)) & 1)

typedef double dbl;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

template <class T> T inline sqr(T x) { return x * x; }
template <class T> inline void relaxMin( T &a, T b ) { a = min(a, b); }
template <class T> inline void relaxMax( T &a, T b ) { a = max(a, b); }

string str( int i ) { char s[100]; sprintf(s, "%d", i); return string(s); }

inline int sign( int x ) { return x > 0 ? 1 : (x < 0 ? -1 : 0); }
inline int myAbs( int a ) { return a > 0 ? a : -a; }

const int maxN = (int)1e4 + 10;
const ll inf = (ll)1e18;
const int maxX = (int)1e8 + 100;
const int maxP = (int)6e6;

unsigned char is[maxX / 8 + 1];
int pn = 0, p[maxP];

int N;
ll L, H, a[maxN], g[maxN], lcm[maxN];

int xn;
ll x[99];
int k[99];

vector <ll> D;

void go( ll val, int i )
{
  if (i == xn)
  {
    D.pb(val);
    return;
  }
  for (int j = 0; j <= k[i]; j++)
    go(val, i + 1), val *= x[i];
}

void getD( ll X )
{
  D.clear();
  xn = 0;
  for (int i = 0; i < pn && (ll)p[i] * p[i] <= X; i++)
    if (X % p[i] == 0)
    {
      k[xn] = 0, x[xn] = p[i];
      while (X % p[i] == 0)
        k[xn]++, X /= p[i];
      xn++;
    }
  if (X > 1)
    k[xn] = 1, x[xn++] = X;
  go(1, 0);
}

int main()
{
  for (int i = 2; i * i < maxX; i++)
    if (!IS(is[i >> 3], i & 7))
      for (int j = i * i; j < maxX; j += i)
        is[j >> 3] |= 1 << (j & 7);
  for (int i = 2; i < maxX; i++)
    if (!IS(is[i >> 3], i & 7))
      p[pn++] = i;

  int tn;
  scanf("%d", &tn);
  forab(tt, 1, tn)
  {
    fprintf(stderr, "%d\n", tt);
    scanf("%d%I64d%I64d", &N, &L, &H);
    forn(i, N)
      scanf("%I64d", &a[i]);
    sort(a, a + N);
    g[N - 1] = a[N - 1];
    for (int i = N - 2; i >= 0; i--)
      g[i] = __gcd(a[i], g[i + 1]);
    lcm[0] = 1;
    forn(i, N)
    {
      ll x = lcm[i], y = a[i] / __gcd(a[i], lcm[i]);
      if (x >= inf / y)
        lcm[i + 1] = inf;
      else
        lcm[i + 1] =  x * y;
    }

    int good = 0;
    forn(i, N)
      if (lcm[i] <= g[i] && g[i] % lcm[i] == 0)
      {
        getD(g[i] / lcm[i]);
        sort(all(D));
        forn(j, sz(D))
        {
          ll x = lcm[i] * D[j];
          if (L <= x && x <= H)
          {
            printf("Case #%d: %I64d\n", tt, x);
            good = 1;
            break;
          }
        }
        if (good)
          break;
      }
    if (!good)
      if (lcm[N] <= H)
      {
        ll x = lcm[N] * ((L + lcm[N] - 1) / lcm[N]);
        if (x <= H)
        {
          printf("Case #%d: %I64d\n", tt, x);
          good = 1;
        }
      }
    if (!good)
      printf("Case #%d: NO\n", tt);
  }
  return 0;
}

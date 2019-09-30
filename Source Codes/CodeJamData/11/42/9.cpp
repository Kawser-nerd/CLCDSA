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

const int maxn = 503;

int h, w, d;
char s[maxn][maxn];
int a[maxn][maxn];
ll sum1[maxn][maxn];
ll sum2[maxn][maxn];
ll sum3[maxn][maxn];

int main()
{
  int tn;
  scanf("%d", &tn);
  forab(tt, 1, tn)
  {
    scanf("%d%d%d", &h, &w, &d);
    forn(i, h)
      scanf("%s", s[i]);
    forn(i, h)
      forn(j, w)
        a[i][j] = d + (s[i][j] - '0');

    #define CALC(sum1, expr) \
      zero(sum1); \
      fornd(i, h) \
        fornd(j, w) \
          sum1[i][j] = -sum1[i + 1][j + 1] + sum1[i + 1][j] + sum1[i][j + 1] + expr; 
    CALC(sum1, a[i][j]);
    CALC(sum2, a[i][j] * i);
    CALC(sum3, a[i][j] * j);

    int ma = 0;
    for (int K = 3; K <= min(h, w); K++)
      forn(y1, h - K + 1)
        forn(x1, w - K + 1)
        {
          int x2 = x1 + K, y2 = y1 + K;
          #define GET(sum) sum[y1][x1] - sum[y1][x2] - sum[y2][x1] + sum[y2][x2]
          ll sx = GET(sum3), sy = GET(sum2), m = GET(sum1);
          x2--, y2--;
          sx -= (ll)a[y1][x1] * x1 + a[y2][x2] * x2 + a[y2][x1] * x1 + a[y1][x2] * x2;
          sy -= (ll)a[y1][x1] * y1 + a[y2][x2] * y2 + a[y2][x1] * y2 + a[y1][x2] * y1;
          m -= (ll)a[y1][x1] + a[y2][x2] + a[y2][x1] + a[y1][x2];
          if (K > ma && sx * 2 == (x1 + x2) * m && sy * 2 == (y1 + y2) * m)
            ma = K;
        }
    if (ma < 3)
      printf("Case #%d: IMPOSSIBLE\n", tt);
    else
      printf("Case #%d: %d\n", tt, ma);
  }
  return 0;
}

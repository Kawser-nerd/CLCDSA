/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2012.05.26
 */

/* Template */

#include <cstdarg>
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
#include <queue>
#include <bitset>
#include <numeric>
#include <iterator>

using namespace std;

#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%lld"
#endif

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define Fill(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define mp make_pair
#define uni(a) (unique(all(a)) - (a).begin());
#define BS(a, x, less) (lower_bound(all(a), x, less) - (a).begin())

#define EOL(i, n) " \n"[i == (n) - 1]
#define LEN(a) (int)(sizeof(a) / sizeof(a[0]))
#define IS(a, i) (((a) >> (i)) & 1)
#define LAST(a) (a)[sz(a) - 1]
#define ONE(n) ((1 << (n)) - 1)

typedef short int16;
typedef unsigned short uint16;
typedef unsigned int uint;
typedef double dbl;
typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vs;
typedef pair <int, int> pii;
typedef vector <pii> vpii;
typedef unsigned char byte;

template <class T> T inline sqr(T x) { return x * x; }
template <class T> inline void relaxMin( T &a, T b ) { a = min(a, b); }
template <class T> inline void relaxMax( T &a, T b ) { a = max(a, b); }
template <class T> inline T sign( T x ) { return x > 0 ? 1 : (x < 0 ? -1 : 0); }
template <class T> inline T myAbs( T a ) { return a > 0 ? a : -a; }
template <class T> T iteratorK( T a, int k ) { while (k--) a++; return a; }

#define DEBUG 1
void err( const char *fmt, ... )
{
  #if DEBUG
  va_list list;
  va_start(list, fmt);
  vfprintf(stderr, fmt, list);
  fflush(stderr);
  #endif
}

void Assert( bool f, const char *fmt = "", ... )
{
  if (!f)
  {
    va_list list;
    va_start(list, fmt);
    err(fmt, list);
    exit(1);
  }
}

unsigned R() { return (rand() << 15) + rand(); }

double start = clock();
void TimeStamp( const char *s = 0, ... )
{
  va_list list;
  va_start(list, s);
  if (s)
  {
    fprintf(stderr, "time = %.2f : ", (clock() - start) / CLOCKS_PER_SEC);
    vfprintf(stderr, s, list);
    fprintf(stderr, "\n");
  }
  else
    fprintf(stderr, "time = %.2f\n", (clock() - start) / CLOCKS_PER_SEC);
  start = clock();
}

void MiniTimeStamp( const char *s )
{
  fprintf(stderr, "time = %.2f : %s\n", (double)(clock() - start) / CLOCKS_PER_SEC, s);
}

/* The main part */

const int maxN = 1010;

int n, L, W, p[maxN], r[maxN], x[maxN], y[maxN];
                                                    
inline bool rless( int i, int j ) { return r[i] > r[j]; }

void Pack( int lx, int ly, int rx, int ry )
{
  //printf("Pack [%d,%d] - [%d,%d]\n", lx, ly, rx, ry);

  lx = max(lx, 0), ly = max(ly, 0);
  rx = min(rx, L), ry = min(ry, W);

  if (lx >= rx || ly >= ry)
    return;
  forn(i, n)
    if (p[i] != -1)
    {
      int j = p[i], R = r[j];
      if (lx + 2 * R <= rx && ly + 2 * R <= ry)
      {
        x[j] = lx + R, y[j] = ly + R, p[i] = -1;
        //printf("put2 (%d,%d) %d\n", x[j], y[j], R);
        Pack(lx, ly + 2 * R, lx + 2 * R, ry);
        lx += 2 * R;
      }
    }
}

int main()
{
#ifdef DEBUG
  double tmp_start = clock();
  fprintf(stderr, "Start\n");
#endif

  int tn;
  scanf("%d", &tn);
  forn(tt, tn)
  {
    scanf("%d%d%d", &n, &L, &W);
    forn(i, n)
      scanf("%d", &r[i]), p[i] = i;
    sort(p, p + n, rless);

    int cy = 0;
    while (1)
    {
      //printf("cy = %d\n", cy);
      int ma = -1;
      forn(i, n)
        if (p[i] != -1)
          ma = i, i = n;
      if (ma == -1)
        break;
      
      int dh = (cy ? 2 : 1) * r[p[ma]];
      int j, cx = 0;
      vector <pair<pii, pii> > toPack;

      forn(i, n)
        if ((j = p[i]) != -1)
        {
          int R = r[j];
          int X = cx ? cx + R : cx;
          int Y = cy + (cy ? r[j] : 0);
          if (X <= L)
          {
            //printf("put1 (%d,%d) %d\n", X, Y, R);
            x[j] = X, y[j] = Y, p[i] = -1;
            toPack.pb(mp(mp(cx, Y + R), mp(X + R, cy + dh)));
            cx = X + R;
          }
        }

      forn(i, sz(toPack))
        Pack(toPack[i].first.first, toPack[i].first.second, toPack[i].second.first, toPack[i].second.second);

      cy += dh;
    }

    printf("Case #%d:", tt + 1);
    forn(i, n)
      printf(" %d %d", x[i], y[i]);
    puts("");

    forn(i, n)
      assert(0 <= x[i] && x[i] <= L && 0 <= y[i] && y[i] <= W);
    forn(i, n)
      forn(j, i)
        assert(abs(x[i] - x[j]) >= r[i] + r[j] || abs(y[i] - y[j]) >= r[i] + r[j]);
  }

#ifdef DEBUG
  fprintf(stderr, "Total time = %.2f\n", (clock() - tmp_start) / CLOCKS_PER_SEC);
#endif
  return 0;
}

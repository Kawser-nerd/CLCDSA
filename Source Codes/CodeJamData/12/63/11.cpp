/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2012.07.27
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
#define ONE(n) ((1 << (n)) - 1)
#define LAST(a) (a)[sz(a) - 1]
#define LASTC(s) (s)[strlen((s)) - 1]

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

const int M = 1010;
const ll inf = (ll)1e18;

void out( ll x )
{
  if (x == -inf)
    printf("-inf");
  else if (x == inf)
    printf("inf");
  else
    printf("%I64d", x);
}

struct rect
{
  ll s_min, s_max;
  ll d_min, d_max;

  rect() { }

  rect( ll a, ll b, ll c, ll d )
  {
    s_min = a, s_max = b;
    d_min = c, d_max = d;
  }

  bool is_intr( rect r )
  {
    ll s = min(r.s_max, s_max) - max(r.s_min, s_min) + 1;
    ll d = min(r.d_max, d_max) - max(r.d_min, d_min) + 1;
    if (s <= 0 || d <= 0)
      return 0;
    s_min = max(s_min, r.s_min), s_max = min(s_max, r.s_max);
    d_min = max(d_min, r.d_min), d_max = min(d_max, r.d_max);
    return 1;
  }
  bool in( ll x, ll y )
  {
    return s_min <= x + y && x + y <= s_max && d_min <= x - y && x - y <= d_max;
  }
  void out()
  {
    printf("[");
    ::out(s_min);
    printf(",");
    ::out(s_max);
    printf(" ");
    ::out(d_min);
    printf(",");
    ::out(d_max);
    printf("] ");
  }
};

int n, rn, tn;
ll x[M], y[M];
char c[M];
rect r[2 * M], t[2 * M];

void Add( rect r1, rect r2 )
{
/*
  printf("Add ");
  r1.out();
  r2.out();
  puts("");
*/
  rect tmp;
  tn = 0;
  forn(i, rn)
  {
    tmp = r[i];
    if (tmp.is_intr(r1))
      t[tn++] = tmp;//, printf("add: "), tmp.out(), r[i].out(), r1.out(), puts("");
    tmp = r[i];
    if (tmp.is_intr(r2))
      t[tn++] = tmp;//, printf("add: "), tmp.out(), r[i].out(), r2.out(), puts("");
  }
  rn = tn;
  forn(i, tn)
    r[i] = t[i];
}

int is = 0;
ll rx = -1, ry = -1, d = -1;

void Try( rect r, ll x, ll y, int dx, int dy )
{
  const int C = 10;
  forab(i, -C, C)
    forab(j, -C, C)
    {
      ll cx = x + i, cy = y + j;
      if ((cx & 1) == dx && (cy & 1) == dy && r.in(cx, cy))
      {
        if (!is || abs(cx) + abs(cy) < d ||
           (abs(cx) + abs(cy) == d && cx > rx) ||
           (abs(cx) + abs(cy) == d && cx == rx && cy > ry))
         d = abs(cx) + abs(cy), rx = cx, ry = cy, is = 1;
      }
    }
}

void Try2( rect r, ll s, ll d, int dx, int dy )
{
  Try(r, (s + d) / 2, (s - d) / 2, dx, dy);
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
    fprintf(stderr, "Case #%d:\n", tt + 1);
    printf("Case #%d: ", tt + 1);
//    puts("");
    scanf("%d", &n);
    forn(i, n)
      scanf("%I64d%I64d %c", &x[i], &y[i], &c[i]);

    is = 0;
    rx = -1, ry = -1, d = -1;
    forn(dx, 2)
      forn(dy, 2)
      {
        int good = 1;
        forn(i, n)
          good &= (((dx + x[i]) & 1) ? '#' : '.') == c[i] || (((dy + y[i]) & 1) ? '#' : '.') == c[i];
        if (!good)
          continue;
        rn = 0;
        r[rn++] = rect(-inf, inf, -inf, inf);
        forn(i, n)
        {
          //printf("%I64d %I64d\n", x[i], y[i]);
          if ((((dx + x[i]) & 1) ? '#' : '.') != c[i]) // dy > dx
          {
            //puts("Case 1");
            Add(rect(x[i] + y[i] + 1, inf, -inf, x[i] - y[i] - 1), rect(-inf, x[i] + y[i] - 1, x[i] - y[i] + 1, inf));
          }
          if ((((dy + y[i]) & 1) ? '#' : '.') != c[i]) // dx > dy
          {
            //puts("Case 2");
            Add(rect(x[i] + y[i] + 1, inf, x[i] - y[i] + 1, inf), rect(-inf, x[i] + y[i] - 1, -inf, x[i] - y[i] - 1));
          }
          assert(rn <= 1 + 2 * (i + 1));
          //printf("rn = %d\n", rn);
        }
        forn(i, rn)
        {
          //printf("%d: ", i);
          //r[i].out();
          //puts("");
          if (r[i].in(0, 0))
            Try(r[i], 0, 0, dx, dy);
          Try2(r[i], r[i].s_min, r[i].d_min, dx, dy);
          Try2(r[i], r[i].s_max, r[i].d_min, dx, dy);
          Try2(r[i], r[i].s_max, r[i].d_max, dx, dy);
          Try2(r[i], r[i].s_min, r[i].d_max, dx, dy);
          Try2(r[i], r[i].s_min, 0, dx, dy);
          Try2(r[i], r[i].s_max, 0, dx, dy);
          Try2(r[i], 0, r[i].d_min, dx, dy);
          Try2(r[i], 0, r[i].d_max, dx, dy);

          Try(r[i], r[i].s_min, 0, dx, dy);
          Try(r[i], r[i].s_max, 0, dx, dy);
          Try(r[i], 0, r[i].s_min, dx, dy);
          Try(r[i], 0, r[i].s_max, dx, dy);
          Try(r[i], r[i].d_min, 0, dx, dy);
          Try(r[i], r[i].d_max, 0, dx, dy);
          Try(r[i], 0, -r[i].d_min, dx, dy);
          Try(r[i], 0, -r[i].d_max, dx, dy);
        }
      }
    if (!is)
      puts("Too damaged");
    else
      printf("%I64d %I64d\n", rx, ry);
  }

#ifdef DEBUG
  fprintf(stderr, "Total time = %.2f\n", (clock() - tmp_start) / CLOCKS_PER_SEC);
#endif
  return 0;
}

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

typedef double dbl;

const dbl eps = 1e-9;

struct pnt
{
  int x, y;

  pnt( int _x = 0, int _y = 0 ) : x(_x), y(_y) { }

  inline pnt operator - () const { return pnt(-x, -y); }

  inline pnt operator + ( const pnt &p ) const { return pnt(x + p.x, y + p.y); }
  inline pnt operator - ( const pnt &p ) const { return pnt(x - p.x, y - p.y); }
  inline pnt operator * ( const int &k ) const { return pnt(x * k, y * k); }
  inline pnt operator / ( const int &k ) const { return pnt(x / k, y / k); }

  inline ll operator * ( const pnt &p ) const { return (ll)x * p.y - (ll)y * p.x; }
  inline ll operator ^ ( const pnt &p ) const { return (ll)x * p.x + (ll)y * p.y; }

  inline bool operator == ( const pnt &p ) const { return x == p.x && y == p.y; }
  inline bool operator != ( const pnt &p ) const { return !(*this == p); }
  inline bool operator < ( const pnt &p ) const { return x < p.x || (x == p.x && y < p.y); }

  inline void read() { assert(scanf("%d%d", &x, &y) == 2); }

  pnt rot()
  {
    return pnt(y, -x);
  }

  inline int d2() const { return (int)x * x + (int)y * y; }
};

const int maxN = 103;

int n, m, A[maxN], B[maxN], a[maxN][4], b[maxN][4];
pnt p[maxN];
int res;
int cnt[4], used[maxN], was[maxN][4];

void go( int x, int i, int j, int dx, int dy )
{
  if (j == 4)
    i++, j = 0;
  if (!x)
  {
    res = max(res, dx * dx + dy * dy);
    return;
  }

  if (i + 1 < n || !cnt[j])
    go(x, i, j + 1, dx, dy);

  if (cnt[j] > 0)
  {
    if (!was[i][j])
      used[i]++;
    was[i][j]++;
    cnt[j]--;
    if (!was[i][j ^ 2])
      go(x - 1, i, j, dx + a[i][j], dy + b[i][j]);
    cnt[j]++;
    was[i][j]--;
    if (!was[i][j])
      used[i]--;
  }
}

void Solve( int x )
{          
  Fill(cnt, 0);
  Fill(used, 0);
  Fill(was, 0);
  forn(i, x)
    cnt[i % 4]++;
  go(x, 0, 0, 0, 0);
}

int main()
{
#ifdef DEBUG
  double tmp_start = clock();
  fprintf(stderr, "Start\n");
#endif

//  pnt(1, 0).rot(-M_PI / 2).outln();

  int tn;
  scanf("%d", &tn);
  forn(tt, tn)
  {
    fprintf(stderr, "Case #%d:\n", tt + 1);
    printf("Case #%d: ", tt + 1);

    scanf("%d%d", &n, &m);
    forn(i, n)
    {
      scanf("%d%d", &p[i].x, &p[i].y);
      A[i] = p[i].x - p[i].y;
      B[i] = p[i].y + p[i].x;
      a[i][0] = +A[i], b[i][0] = +B[i];
      a[i][1] = +B[i], b[i][1] = -A[i];
      a[i][2] = -A[i], b[i][2] = -B[i];
      a[i][3] = -B[i], b[i][3] = +A[i];
    }

    res = 0;
    forab(i, 1, m)
      Solve(i);

    printf("%.6f\n", sqrt(res));
#ifdef DEBUG
    fprintf(stderr, "time = %.2f\n", (clock() - tmp_start) / CLOCKS_PER_SEC);
#endif
  }

#ifdef DEBUG
  fprintf(stderr, "Total time = %.2f\n", (clock() - tmp_start) / CLOCKS_PER_SEC);
#endif
  return 0;
}

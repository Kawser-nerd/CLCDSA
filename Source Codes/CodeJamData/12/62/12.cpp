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

const int maxN = (int)1e4 + 10;

double p[maxN];
int n, k, c[maxN], o[maxN], cur[maxN];
                                
bool pless( int i, int j )
{
  return p[i] < p[j];
}

double P_bad, P_wake, P_sleep;

void Do( int i )
{
//  printf("do: i = %d, p = %.3f\n", i, p[i]);

  P_bad += P_sleep * p[i];
  double p1 = (P_sleep + P_wake) * (1 - p[i]);
  double p2 = P_wake * p[i];
  P_sleep = p1;
  P_wake = p2;
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

    scanf("%d%d", &n, &k);
    forn(i, n)
    {
      int a, b;
      scanf("%d%*c%d%d", &a, &b, &c[i]);
      p[i] = (double)a / b;
      o[i] = i;
    }
    sort(o, o + n, pless);

    double Q = 1;
    forn(num, k + 1)
    {
      forn(i, n)
        cur[i] = c[i];

//      printf("num = %d\n", num);

      int pos = n - 1;
      P_bad = 0;
      P_wake = 1;
      P_sleep = 0;
      vi v;
      forn(i, num)
      {
        while (!cur[o[pos]])
          pos--;
        v.pb(o[pos]);
        cur[o[pos]]--;
      }
      pos = 0;
      forn(i, k - num)
      {
        while (!cur[o[pos]])
          pos++;
        v.pb(o[pos]);
        cur[o[pos]]--;
      }
      sort(all(v), pless);
      reverse(all(v));
      forn(i, sz(v))
        Do(v[i]);
      Q = min(Q, P_bad);
    }
    printf("%.12f\n", Q);
  }

#ifdef DEBUG
  fprintf(stderr, "Total time = %.2f\n", (clock() - tmp_start) / CLOCKS_PER_SEC);
#endif
  return 0;
}

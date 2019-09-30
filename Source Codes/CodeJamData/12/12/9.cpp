/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2012.04.02
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
#define Fill(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define mp make_pair
#define uni(a) (unique(all(a)) - (a).begin());
#define BS(a, x, less) (lower_bound(all(a), x, less) - (a).begin())

#define EOL(i, n) " \n"[i == (n) - 1]
#define LEN(a) (int)(sizeof(a) / sizeof(a[0]))
#define IS(a, i) (((a) >> (i)) & 1)
#define LAST(a) a[sz(a) - 1]
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
void TimeStamp()
{
  fprintf(stderr, "time = %.2f\n", (clock() - start) / CLOCKS_PER_SEC);
  start = clock();
}

/* The main part */

const int maxN = 1010;

int n, k, a[maxN], b[maxN], c[maxN];
int num, res;

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
    printf("Case #%d: ", tt + 1);
    scanf("%d", &n);
    forn(i, n)
      scanf("%d%d", &a[i], &b[i]);
    k = 0, num = 0, res = 0;
    while (n > 0 || k > 0)
    {
      sort(c, c + k);
      if (k > 0 && c[0] <= num)
      {
        //printf("num=%d,[%d] ", num, c[0]);
        num++, c[0] = c[--k];
      }
      else
      {
        if (n == 0 || *min_element(a, a + n) > num)
          break;
        forn(i, n)
          a[i] = max(a[i], num);

        int good = -1;
        forn(i, n)
          if (a[i] == num && b[i] <= num)
            good = i;
        if (good != -1)
        {
          //printf("num=%d,[%d,%d] ", num, a[good], b[good]);
          res++, num += 2;
          n--, a[good] = a[n], b[good] = b[n];
        }
        else
        {
          forn(i, n)
            if (a[i] == num && (good == -1 || b[i] > b[good]))
              good = i;

          //printf("num=%d,[%d,%d] ", num, a[good], b[good]);
          num++;
          c[k++] = b[good];
          res += 2;
          n--, a[good] = a[n], b[good] = b[n];
        }
      }
    }
    //printf("num = %d, n = %d, k = %d ", num, n, k);

    if (n > 0 || k > 0)
      puts("Too Bad");
    else
      printf("%d\n", res);
  }

#ifdef DEBUG
  fprintf(stderr, "Total time = %.2f\n", (clock() - tmp_start) / CLOCKS_PER_SEC);
#endif
  return 0;
}

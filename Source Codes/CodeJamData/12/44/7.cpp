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

const int maxN = 63;

int w, h, cnt[10], was[maxN][maxN];
char s[maxN][maxN], is[maxN][maxN];
                        
void dfs( int x, int y, int i )
{
  if (s[y][x] == '#' || (was[y][x] & (1 << i)))
    return;
  cnt[i]++;
  was[y][x] |= 1 << i;
  dfs(x + 1, y, i);
  dfs(x - 1, y, i);
  dfs(x, y - 1, i);
}

template <const int max_size, typename HashType>
struct hashTable
{
  char cc, used[max_size];
  HashType hash[max_size];

  hashTable() { cc = 1; }

  inline int position( HashType H ) const
  {
    int i = H % max_size;
    while (used[i] == cc && hash[i] != H)
      if (++i == max_size)
        i = 0;
    return i;
  }

  void clear() { cc++; }

  inline int is( int pos ) { return used[pos] == cc; }
  inline void add( HashType H, int pos ) { used[pos] = cc, hash[pos] = H; }
};

hashTable<(int)2e6 + 3, ull> mem;
int good;
char GOAL;

int dx[3] = {1, -1, 0};
int dy[3] = {0, 0, 1};

void go( char is[maxN][maxN] )
{
  if (good)
    return;
  int bad = 0;
  forab(i, 1, h)
    forab(j, 1, w)
      bad |= (is[i][j] != (s[i][j] == GOAL));
  if (!bad)
  {
    good = 1;
    return;
  }

  ull H = 0;
  forab(i, 1, h)
    forab(j, 1, w)
      H = H * 239017 + is[i][j];
  int hpos = mem.position(H);
  //printf("h = %I64u, hpos = %d, is = %d\n", h, hpos, mem.is(hpos));
  if (mem.is(hpos))
    return;
  mem.add(H, hpos);

/*
  printf("come in [h = %d, w = %d]\n", h, w);
  forab(i, 1, h)
  {
    forab(j, 1, w)
      printf("%d", is[i][j]);
    puts("");
  }
*/

  char is2[maxN][maxN];
  forn(k, 3)
  {
    forab(i, 1, h)
      forab(j, 1, w)
        is2[i][j] = 0;
    forab(i, 1, h)
      forab(j, 1, w)
        if (is[i][j])                
        {
          int j1 = j + dx[k];
          int i1 = i + dy[k];
          if (s[i1][j1] == '#')
            is2[i][j] = 1;
          else
            is2[i1][j1] = 1;
        }
    go(is2);
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
    fprintf(stderr, "tt = %d of %d\n", tt, tn);
    printf("Case #%d:\n", tt + 1);

    scanf("%d%d", &h, &w);
    forab(i, 1, h)
      scanf("%s", s[i]);
    forab(i, 0, h + 1)
      forab(j, 0, w + 1)
        if (!j || !i || i == h || j == w)
          s[i][j] = '#';

    fprintf(stderr, "read: over\n");

    Fill(cnt, 0);
    Fill(was, 0);
    forab(i, 1, h)
      forab(j, 1, w)
        if (isdigit(s[i][j]))
          dfs(j, i, s[i][j] - '0');

    fprintf(stderr, "dfs: over\n");

    forn(k, 10)
      if (cnt[k])
      {
        printf("%d: %d ", k, cnt[k]);
        forab(i, 1, h)
          forab(j, 1, w)
            is[i][j] = IS(was[i][j], k);
        good = 0;
        mem.clear();
        GOAL = '0' + k;
        //fprintf(stderr, "k = %d, h = %d, w = %d\n", k, h, w);
        go(is);
        puts(good ? "Lucky" : "Unlucky");
      }
  }

#ifdef DEBUG
  fprintf(stderr, "Total time = %.2f\n", (clock() - tmp_start) / CLOCKS_PER_SEC);
#endif
  return 0;
}

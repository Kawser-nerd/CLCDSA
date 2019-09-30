/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2012.06.09
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

const int maxS = 6010;
const int maxSS = maxS * maxS;
const int maxM = (int)1e5 + 10;

int S, M, x[maxM], y[maxM];
int p[maxSS], size[maxSS];
char P1[maxSS], P2[maxSS], is[maxSS];
char was[maxS][maxS];
int bn[64], isBridge, isFork, isCycle;
int firstBridge, firstFork, firstCycle;

int dx[] = {-1, -1, 0, 0, 1, 1};
int dy[] = {-1, 0, -1, 1, 0, 1};

int get( int a )
{
  return a == p[a] ? a : (p[a] = get(p[a]));
}

void join( int a, int b )
{
  if (!is[a] || !is[b])
    return;
  a = get(a), b = get(b);
  if (a == b)
    return;
  if (size[a] > size[b])
    swap(a, b);
  p[a] = b;
  size[b] += size[a];
  //printf("[%d or %d, %d or %d]\n", P1[b], P1[a], P2[b], P2[a]);
  P1[b] |= P1[a];
  P2[b] |= P2[a];
  //printf("[%d,%d] : %d bits, %d bits\n", P1[b], P2[b], bn[(int)P1[b]], bn[(int)P2[b]]);
  if (bn[(int)P1[b]] >= 2) isBridge = 1;
  if (bn[(int)P2[b]] >= 3) isFork = 1;
}

inline int F( int x, int y )
{
  return x * maxS + y;
}

void Init()
{
  Fill(is, 0);
  Fill(P1, 0);
  Fill(P2, 0);
  forn(i, maxSS)
    size[i] = 1, p[i] = i;

  P1[F(1, 1)] |= 1 << 0;
  P1[F(1, S)] |= 1 << 1;
  P1[F(S, 1)] |= 1 << 2;
  P1[F(S, 2 * S - 1)] |= 1 << 3;
  P1[F(2 * S - 1, S)] |= 1 << 4;
  P1[F(2 * S - 1, 2 * S - 1)] |= 1 << 5;

  forab(i, 1, S - 2)
  {
    P2[F(1, i + 1)] |= 1 << 0;
    P2[F(i + 1, 1)] |= 1 << 1;
    P2[F(1 + i, S + i)] |= 1 << 2;
    P2[F(S + i, 1 + i)] |= 1 << 3;
    P2[F(S + i, 2 * S - 1)] |= 1 << 4;
    P2[F(2 * S - 1, S + i)] |= 1 << 5;
  }
}

void Clear( int x, int y )
{
  is[F(x, y)] = 1;
  forn(k, 6)
    join(F(x, y), F(x + dx[k], y + dy[k]));
}

int main()
{
#ifdef DEBUG
  double tmp_start = clock();
  fprintf(stderr, "Start\n");
#endif

  forn(i, 64)
    bn[i] = bn[i / 2] + (i % 2);
  int tn;
  scanf("%d", &tn);
  forn(tt, tn)
  {
    fprintf(stderr, "Case #%d: \n", tt + 1);
    printf("Case #%d: ", tt + 1);
    scanf("%d%d", &S, &M);
    //printf("[%d moves]\n", M);
    forn(i, M)
      scanf("%d%d", &x[i], &y[i]);

    isBridge = isFork = isCycle = 0;
    firstCycle = firstBridge = firstFork = M;
    
    Init();
    forn(i, M)
    {
      is[F(x[i], y[i])] = 1;
      //printf("[fill %d,%d]\n", x[i], y[i]);
      forn(k, 6)
      {
        //printf("[join (%d,%d) (%d,%d)]\n", x[i], y[i], x[i] + dx[k], y[i] + dy[k]);
        join(F(x[i], y[i]), F(x[i] + dx[k], y[i] + dy[k]));
      }
      if (isBridge && firstBridge == M)
        firstBridge = i;
      if (isFork && firstFork == M)
        firstFork = i;
    }

    Init();
    Fill(was, 0);
    forn(i, M)
      was[x[i]][y[i]] = 1;
    //printf("[S=%d] ", S);
    {
      forab(x, 1, 2 * S - 1)
      {
        int ly, ry;
        if (x <= S)
          ly = 1, ry = S + x - 1;
        else
          ry = 2 * S - 1, ly = x - S + 1;
        //printf("%d:[%d,%d] ", x, ly, ry);
        forab(y, ly, ry)
          if (!was[x][y])
            Clear(x, y);
      }
    }
    fornd(i, M)
    {
      forn(k, 6)
      {
        int x1 = x[i] + dx[k], y1 = y[i] + dy[k];
        int t = F(x1, y1) ;
        if (is[t])
        {
          t = get(t);
          if (!P1[t] && !P2[t])
            firstCycle = i;
        }
      }
      Clear(x[i], y[i]);
    }
    //printf("[%d,%d,%d,M=%d] ", firstCycle, firstBridge, firstFork, M);

    int res = min(firstCycle, min(firstBridge, firstFork));
    if (res == M)
      puts("none");
    else
    {
      int first = 1;
      if (firstBridge == res) printf("%sbridge", first ? "" : "-"), first = 0;
      if (firstFork   == res) printf("%sfork",   first ? "" : "-"), first = 0;
      if (firstCycle  == res) printf("%sring",   first ? "" : "-"), first = 0;
      printf(" in move %d\n", res + 1);
    }
  }

#ifdef DEBUG
  fprintf(stderr, "Total time = %.2f\n", (clock() - tmp_start) / CLOCKS_PER_SEC);
#endif
  return 0;
}

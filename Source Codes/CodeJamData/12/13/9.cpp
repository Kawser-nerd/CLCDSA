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

template <class T> string str( T i );
template <class P1, class P2> string str( pair <P1, P2> i );
template <class T> string str( T begin, T end );
template <class T> string str( vector <T> i ) { return str(all(i)); }
template <class T> string str( int n, T begin ) { return str(begin, begin + n); }
string str( int i ) { char s[100]; sprintf(s, "%d", i); return string(s); }

template <class T> string str( T i )
{ 
  stringstream ss;
  ss << i;
  return ss.str();
}
template <class P1, class P2> string str( pair <P1, P2> i )
{ 
  stringstream ss;
  ss << "<" << str(i.first) << ", " << str(i.second) << ">";
  return ss.str();
}
template <class T> string str( T begin, T end )
{
  stringstream ss;
  ss << "[";
  int f = 0;
  while (begin != end)
    ss << (f ? ", " : "") << str(*begin++), f = 1;
  ss << "]";
  return ss.str();
}
string str( ll num, int bn )
{
  stringstream ss;
  while (bn--)
    ss << (num & 1), num >>= 1;
  return ss.str();
}
string str( int num, int bn ) { return str((ll)num, bn); }
#define cstr(...) str(__VA_ARGS__).c_str()

/* The main part */

#define NAME "a"

const int maxN = 53;
const double eps = 1e-8;

int k, n, v[maxN], pos[maxN], type[maxN];
double T[maxN * maxN], S[maxN];
int p[maxN];
int cc, no[maxN];

int Compare( double x, double y )
{
  if (fabs(y) < 1)
    return x > y + eps ? 1 : (x > y - eps ? 0 : -1);
  return x / y > 1 + eps ? 1 : (x / y > 1 - eps ? 0 : -1);
}

bool sLess( int i, int j ) { return S[i] > S[j]; }

bool Check1()
{
  forn(a, n)
    forn(b, n)
      if (a != b && S[a] <= S[b])
        if (Compare(S[a] + 5, S[b]) > 0)
          if (type[a] == type[b])
            return 0;
  return 1;
}

bool Check2()
{
  forn(a, n)
    forn(b, n)
      if (a != b && S[a] <= S[b])
        if (Compare(S[a] + 5, S[b]) > 0 || (Compare(S[a] + 5, S[b]) == 0 && v[a] > v[b]))
          if (type[a] == type[b])
            return 0;
  return 1;
}

void GetNew()
{
  forn(a, n)
  {
    int deg = 0;
    forn(b, n)
      deg += a != b && Compare(S[a] + 5, S[b]) > 0 && Compare(S[b] + 5, S[a]) > 0;
    //printf("%d : %d\n", a, deg);
    if (!deg) 
      no[a] = cc++;
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
    fprintf(stderr, "%d of %d\n", tt, tn);
    printf("Case #%d: ", tt + 1);
    //puts("");

    scanf("%d", &n);
    forn(i, n)
    {
      char ch;
      scanf(" %c%d%d", &ch, &v[i], &pos[i]);
      type[i] = (ch == 'L');
    }

    k = 0;
    forn(i, n)
      forn(j, n)
        if (v[i] != v[j])
        {
          double t = (double)(pos[j] - pos[i] - 5) / (v[i] - v[j]);
          if (t >= 0)
            assert(k < LEN(T)), T[k++] = t;
        }
    sort(T, T + k);

    cc = 1;
    forn(i, n)
      no[i] = 0;

    double res = -1;
    forn(i, k)
    {
      forn(j, n)
        S[j] = pos[j] + T[i] * v[j];

/*
      printf("T = %.10f\n", T[i]);
      forn(j, n)
        printf("%d : S = %.10f, v = %d, no = %d, type = %d\n", j, S[j], v[j], no[j], type[j]);
*/

      GetNew();

/*
      printf("T = %.10f\n", T[i]);
      forn(j, n)
        printf("%d : S = %.10f, v = %d, no = %d, type = %d\n", j, S[j], v[j], no[j], type[j]);
*/

      forn(j, n)
        p[j] = j;
      sort(p, p + n, sLess);
      
      int bad = 0;
      forn(j, n)
      {
        int a = p[j];
        int changeNo = -1;
        forn(b, n)
          if (Compare(S[a] + 5, S[b]) == 0 && v[a] > v[b] && type[a] == type[b])
            changeNo = no[b];
        if (changeNo != -1)
        {
          //printf("change1: a = %d, %d to %d\n", a, no[a], changeNo);
          if (no[a] == changeNo)
          {
            bad = 1;
            break;
          }
          int x = no[a];
          forn(i, n)
            if (no[i] == x)
              type[i] ^= 1, no[i] = changeNo;
          if (!Check1())
          {
            bad = 1;
            break;
          }
        }
        else
        {
          forn(b, n)
            if (Compare(S[a] + 5, S[b]) == 0 && v[a] > v[b])
              changeNo = no[b];
          //printf("change2: a = %d, %d to %d\n", a, no[a], changeNo);
          if (changeNo != -1)
          {
            int x = no[a];
            forn(j, n)
              if (no[j] == x)
                no[j] = changeNo;
          }
        }
      }

      if (bad || !Check2())
      {
        res = T[i];
        break;
      }
    }
    if (res == -1)
      puts("Possible");
    else
      printf("%.20f\n", res);
  }

#ifdef DEBUG
  fprintf(stderr, "Total time = %.2f\n", (clock() - tmp_start) / CLOCKS_PER_SEC);
#endif
  return 0;
}

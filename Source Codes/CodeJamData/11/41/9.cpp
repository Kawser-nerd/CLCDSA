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

const int maxn = (int)1e6 + 10;

int X, S, R, N, B[maxn], E[maxn], w[maxn], p[maxn];
dbl t;

inline bool pless( int i, int j )
{
  return w[i] < w[j];
}

int main()
{
  int tn;
  scanf("%d", &tn);
  forab(tt, 1, tn)
  {
    scanf("%d%d", &X, &S);
    scanf("%d%lf%d", &R, &t, &N), R -= S;
    E[N] = X, w[N] = S, p[N] = N;
//    printf("X=%d S=%d R=%d N=%d\n", X, S, R, N);
    forn(i, N)
    {
      scanf("%d%d%d", &B[i], &E[i], &w[i]), p[i] = i;
      w[i] += S, E[i] -= B[i], E[N] -= E[i];
    }
    N++;
//    forn(i, N)
//      printf("%d : %d\n", i, w[i]);
    sort(p, p + N, pless);

    dbl sum = 0;
    forn(j, N)
    {
      int i = p[j];
      dbl t1 = (dbl)E[i] / (R + w[i]);
      dbl dt = min(t, t1);
//      printf("dt = %.20lf, t1 = %.20lf, add = %.20lf, v = %d\n", dt, t1, dt + (dbl)(E[i] - (R + w[i]) * dt) / w[i], w[i]);
      sum += dt + (dbl)(E[i] - (R + w[i]) * dt) / w[i];
      t -= dt;
    }
    printf("Case #%d: %.20lf\n", tt, sum);
  }
  return 0;
}

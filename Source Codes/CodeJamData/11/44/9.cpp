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

const int maxn = 403 + 100;

int n1, n, m, c[maxn][maxn];
int qst, qen, q[maxn], u[maxn], d[maxn];
vi s[maxn];
int res;

int f[maxn][maxn];

const int M = 20;
char bn[1 << M];
int c1[maxn][maxn / M];
int was[maxn][maxn / M];
int tmp[maxn / M];

int main()
{
  forn(i, 1 << M)
    bn[i] = bn[i >> 1] + (i & 1);

  int tn;
  scanf("%d", &tn);
  forab(tt, 1, tn)
  {
    scanf("%d%d", &n, &m), n1 = n / M + 1;
    fprintf(stderr, "%d : %d, %d\n", tt, n, m);
//    fprintf(stderr, "n1 = %d\n", n1);
    zero(c);
    zero(c1);
    zero(was);
    while (m--)
    {
      int a, b;
      scanf("%d,%d", &a, &b);
      c[a][b] = c[b][a] = 1;
      c1[a][b / M] |= 1 << (b % M);
      c1[b][a / M] |= 1 << (a % M);
    }

    forn(i, n + 1)
      u[i] = 0, s[i].clear();
    qst = qen = 0;
    u[0] = 1, q[qen++] = 0, d[0] = 0;
    while (qst < qen)
    {
      int v = q[qst++];
      s[d[v]].pb(v);
      was[d[v]][v / M] |= 1 << (v % M);
      forn(i, n)
        if (!u[i] && c[v][i])
          q[qen++] = i, u[i] = 1, d[i] = d[v] + 1;
    }

    int D = d[1];
    const int inf = (int)1e9;
    res = d[1];
    forn(i, n)
      forn(j, n)
        f[i][j] = -inf;
    forn(i, n)
      if (u[i] && d[i] == 1)
        f[0][i] = 1;
    forn(b, qen) 
      forn(a, b)
      {
        int i = q[a], j = q[b];
        if (f[i][j] == -inf || d[i] + 1 != d[j] || d[j] >= D)
          continue;
        vi &v = s[d[j] + 1];
        int curD = d[j];
        forn(k, sz(v))
        {
          int x = v[k];
          if (c[j][x])
          {
            int Num = 0;
            forn(t, n1)
              Num += bn[was[curD][t] & (c1[i][t] | c1[j][t] | (d[j] == D - 1 ? 0 : c1[x][t]))];
            relaxMax(f[j][x], f[i][j] + Num);
          }
        }
      }

    forn(i, n)
      if (u[i] && d[i] == D - 1 && c[i][1] && f[i][1] != -inf)
      {
        int cnt = f[i][1];
        forn(j, n)
          if (c[i][j] && u[j] && d[j] == D)
            cnt++;
        res = max(res, cnt);
      }
        
    printf("Case #%d: %d %d\n", tt, d[1] - 1, res - d[1]);
  }
  return 0;
}
                       
/**         
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2014.05.31
 */

#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define zero(a) memset(a, 0, sizeof(a))

typedef long long ll;

const int M = 1000;
const int N = 100;
const int LEN = 100;
const int VN = LEN * M + 1;
const int MOD = 1e9 + 7;

int m, n, f[VN];
char s[M][LEN + 1];
int vn, next[VN][26];
int c[N + 2][N + 2];

inline void add( int &a, int b )
{
  if ((a += b) >= MOD)
    a -= MOD;
}

inline int mul( int a, int b )
{
  return (ll)a * b % MOD;
}

inline int newV()
{
  int r = vn++;
  assert(r < VN);
  zero(next[r]);
  f[r] = 0;
  return r;
}

void add(const char *s)
{
  int v = 0;
  for (; *s; s++)
  {
    int &r = next[v][*s - 'A'];
    if (!r)
      r = newV();
    v = r;
  }
  f[v]++;
}

int res, cnt;

inline void relax( int x )
{
  //printf("[%d]", x);
  cnt = mul(cnt, x);
}     

int all, g0[N + 1], g1[N + 1];

void apply( int x )
{
  forn(i, all + 1)
    if (g0[i])
      forn(j, x + 1)
        if (j <= i && x - j <= all - i)
        {
          //printf("%d --> %d\n", i, i + x - j);
          add(g1[i + x - j], mul(mul(g0[i], c[i][j]), c[all - i][x - j]));
        }
}

void calc( int v )
{
  int end = f[v];
  forn(i, 26)
    if (next[v][i])
      calc(next[v][i]), f[v] += f[next[v][i]];
  int x = min(f[v], n);
  res += x;
  if (!v)
  {
    //printf("[root:%d]", c[n][x]);
    relax(c[n][x]);
  }
  if (x == 1)
    return;
  int simple = 0;
  forn(i, 26)
    simple |= (next[v][i] && min(n, f[next[v][i]]) == x);
  if (simple)
  {
    if (end)
      relax(x);
    forn(i, 26)
      if (next[v][i])
        relax(c[x][min(n, f[next[v][i]])]);
    return;
  }

  memset(g0, 0, sizeof(g0));
  all = x;
  if (end)
    g0[1] = x;
  else
    g0[0] = 1;

  forn(i, 26)
    if (next[v][i])
    {
      memset(g1, 0, sizeof(g1));
      //printf("[apply %d]", f[next[v][i]]);
      apply(min(n, f[next[v][i]]));
      memcpy(g0, g1, sizeof(g1));
    }
  //printf("[%d->%d]", x, g0[x]);
  relax(g0[x]);
}

void solve()
{
  scanf("%d%d ", &m, &n);
  forn(i, m)
    gets(s[i]);
  vn = 0, newV();
  forn(j, m)
    add(s[j]);
  res = 0, cnt = 1;
  calc(0);
  printf("%d %d\n", res, cnt);
}

int main()
{
  c[0][0] = 1;
  forn(i, N + 1)
    forn(j, N + 1)
    {
      add(c[i + 1][j], c[i][j]);
      add(c[i + 1][j + 1], c[i][j]);
    }
/*
  forn(i, 10)
  {
    forn(j, 10)
      printf("%d ", c[i][j]);
    puts("");
  }
*/
  int tn;
  scanf("%d", &tn);
  forn(t, tn)
  {
    fprintf(stderr, "Case #%d: ", t + 1);
    printf("Case #%d: ", t + 1);
    solve();
    fprintf(stderr, "ok\n");
  }
  return 0;
}

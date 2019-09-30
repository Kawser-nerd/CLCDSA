#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>

#define pb push_back
#define mp make_pair
#define TASKNAME "D-large"

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

#ifdef linux
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

#define sz(x) ((int)(x).size())

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<pii> vpii;

const int inf = 1e9;
const double eps = 1e-9;
const double INF = inf;
const double EPS = eps;

char s[110][110];
int D[110], P[110];
int Q[110], bq, eq;

bool check (vb u, int t, int f)
{
  if (u[t]==0)
    return 0;
  int n=(int)u.size(), i;
  for (i=0; i<n; i++)
    D[i]=-1;
  bq=0, eq=1, Q[0]=t, D[t]=0;    
  while (bq<eq)
  {
    int v=Q[bq++];
    if (f==v)
      continue;
    for (int i=0; i<n; i++)
      if (u[i] && s[v][i]=='Y' && D[i]==-1)
        D[i]=D[v]+1, P[i]=v, Q[eq++]=i;
  }
  for (i=0; i<n; i++)
    if (u[i] && D[i]==-1 && (f==-1 || s[f][i]=='N'))
      return 0;
  return 1;
}

void solve (int tst)
{
  int i, n, t;
  cerr<<"solve "<<tst<<endl;
  printf("Case #%d:", tst);
  scanf("%d %d", &n, &t);
  for (i=0; i<n; i++)
    scanf(" %s", s[i]);
  vb u;
  u.resize(n);
  for (i=0; i<n; i++)
    u[i]=1;
  if (!check(u,t,-1))
  {
    puts(" IMPOSSIBLE");
    return;
  }
  int cur=-1;
  for (int i=0; i<=n; i++)
  {
    if (check(u,t,i))
    {
      printf(" %d", i), cur=i;
      break;
    }
  }
  for (i=1; i<n; i++)
    for (int j=0; j<=n; j++)
    {
      assert(j<n);
      if (j!=cur && u[j])
      {
        int nc=cur;
        if (s[cur][j]=='N')
          nc=j;
        int ls=j+cur-nc;
        u[ls]=0;
        if (check(u,t,nc))
        {
          printf(" %d", j);
          cur=nc;
          break;
        }
        u[ls]=1;
      }
    }
  printf("\n");
}
               
int main()
{
  int tst;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &tst);
  for (int cnt=1; cnt<=tst; cnt++)
    solve(cnt);  
  TIMESTAMP(end);
  return 0;
}

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
#define TASKNAME "A-large"

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

int u[4100], n;
vvb F;

void dfsr (int);

void dfsc (int v)
{
  u[v+n]=1;
  for (int i=0; i<n; i++)
    if (F[i][v] && u[i]==0)
      dfsr(i);
}

void dfsr (int v)
{  
  u[v]=1;
  for (int i=0; i<n; i++)
    if (F[v][i] && u[i+n]==0)
      dfsc(i);
}

int solve (vvb V)
{ 
  F=V, n=(int)V.size();
  memset(u,0,sizeof(u));
  dfsr(0);
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      if (V[i][j]!=(u[i]==u[n+j]))
        return inf;
  int res=0;
  int c=0;
  for (int i=0; i<n; i++)
    c+=u[i];
  if (c!=n/2)
    return inf;
  c=0;
  for (int i=0; i<n; i++)
    c+=u[i+n];
  if (c!=n/2)
    return inf;
  for (int i=0; i<2*n; i++)
    if (u[i]!=(i&1))
      res++;
  assert(res%2==0);
  if (res>n)
    res=2*n-res;
  return res/2;
}

char s[2100];

void solve (int tst)
{
  int n, i, j;
  cerr<<"solve "<<tst<<endl;
  scanf("%d", &n), n*=2;
  assert(n<=2000);
  vvb V;
  V.resize(n);
  for (i=0; i<n; i++)
  {
    scanf(" %s", s);
    assert((int)strlen(s)==n);
    V[i].resize(n);
    for (j=0; j<n; j++)
      V[i][j]=(s[j]=='1');
  }
  int res=solve(V);
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      V[i][j]=(!V[i][j]);
/*    bool t;
    for (i=0; i<n; i++)
      for (j=0; j<i; j++)
        t=V[i][j], V[i][j]=V[j][i], V[j][i]=t;*/
  res=min(res,solve(V));
  printf("Case #%d: ", tst);
  if (res==inf)
    puts("IMPOSSIBLE");
  else
    printf("%d\n", res);
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

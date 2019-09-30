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
#define TASKNAME ""

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

int D[110][1100];

void solve (int tst)
{
  int n, p, q, g, h, i, j, k;
  cerr<<"Solve "<<tst<<endl;
  memset(D,-1,sizeof(D));
  scanf("%d%d%d", &p, &q, &n);
  D[0][1]=0;
  for (i=0; i<n; i++)
  {
    scanf("%d%d", &h, &g);
    for (j=0; j<1100; j++)
      if (D[i][j]!=-1)
      {
        D[i+1][j+(h+q-1)/q]=max(D[i+1][j+(h+q-1)/q],D[i][j]);     
        for (k=0; k*q<h; k++)
        {          
          int s=(h-k*q+p-1)/p;
          if (s<=j+k)
            D[i+1][j+k-s]=max(D[i+1][j+k-s],D[i][j]+g);
        }
      }
  }
  int res=-1;
  for (i=0; i<1100; i++)
    res=max(res,D[n][i]);
  assert(res!=-1);
  printf("Case #%d: %d\n", tst, res);
}
               
int main()
{
  int tst;
  #ifdef LOCAL
  freopen(TASKNAME"large.in","r",stdin);
  freopen(TASKNAME"out","w",stdout);
  #endif
  scanf("%d", &tst);
  for (int cnt=1; cnt<=tst; cnt++)
    solve(cnt);  
  TIMESTAMP(end);
  return 0;
}

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
#define TASKNAME "e"

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

const int maxe=123123;

int e;
ll D[5100];

void solve (int tst)
{
  cerr<<"solve  "<<tst<<endl;
  printf("Case #%d: ", tst);
  e=0;
  ll n, a, b;
  cin>>n>>a>>b;
  if (n==1)
  {
    puts("0");
    return;
  }
  D[0]=1;
  for (int i=1; ; i++)
  {
    assert(i<=5050);
    D[i]=1;
    if (i>=a)
      D[i]=1+D[i-a];
    if (i>=b)
      D[i]=D[i-a]+D[i-b];
    if (D[i]>=n)
    {
      cout<<i<<endl;
      return;
    }
  }
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

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

const int maxn = 1123123;

ll S[maxn];
int A[maxn];

void solve (int tst)
{
  int i, j, n, p, r, s, q;
  scanf("%d%d%d%d%d", &n, &p, &q, &r, &s);
  for (i=0; i<n; i++)
    A[i]=((i*1ll*p+q)%r+s);
  for (i=0; i<n; i++)
    S[i+1]=S[i]+A[i];
  int p1=lower_bound(S,S+n+1,S[n]/3)-S;
  int p2=lower_bound(S,S+n+1,(2ll*S[n])/3ll)-S;
  //cerr<<p1<<" "<<p2<<" "<<S[p1]<<" "<<S[p2]<<" "<<S[n]<<endl;
  ll res=S[n];
  for (i=p1-10; i<=p1+10; i++)
    if (i>=0 && i<=n)
      for (j=p2-10; j<=p2+10; j++)
        if (i<j && j<=n)
          res=min(res,max(S[i],max(S[n]-S[j],S[j]-S[i])));
  printf("Case #%d: %.12lf\n", tst, ((double)(S[n]-res))/S[n]);
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

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

const int maxe = (int)5e6;
const int maxn = 2100;

int en;
int e, V[maxe], Dest[maxe], Next[maxe], Head[maxn];
int u[maxn], uit, Lv[maxn], end, st, B[maxn], mfl;

void adde (int v1, int v2, int v)
{
  Next[e]=Head[v1], Head[v1]=e, Dest[e]=v2, V[e]=v, e++;
  assert(e<maxe);
}

void add (int v1, int v2, int v)
{
  //cerr<<"add "<<v1<<" "<<v2<<"  "<<v<<endl;
  adde(v1,v2,v), adde(v2,v1,0);
}

bool dfs (int v)
{
  if (v==en)
    return 1;
  u[v]=1;
  for (int r=Head[v]; r!=-1; r=Next[r])
    if ((!u[Dest[r]]) && V[r])
    {
      V[r]--, V[r^1]++;
      if (dfs(Dest[r]))
        return 1;
      V[r]++, V[r^1]--;
    }
  return 0;
}

vi Ev[maxn];
char Tp[maxn];
int Id[maxn];

int flow;
int Q[maxn], bq, eq;

int dfs (int v, int fl)
{ 
  int nfl, nv, ne;
  u[v]=uit;
  if (v==end)
  {
    flow+=fl;
    return fl;
  }
  for ( ; B[v]!=-1; B[v]=Next[B[v]])
  {
    ne=B[v], nv=Dest[ne];
    if (u[nv]!=uit && V[ne]>=mfl && Lv[nv]==Lv[v]+1)
    {
      nfl=dfs(nv,min(V[ne],fl));
      if (nfl) 
      {
        V[ne]-=nfl, V[ne^1]+=nfl;
        return nfl;
      }
    }
  }
  return 0;
}

int getflow (int n, int _st, int _end)
{
  int v, r, i;
  flow=0;
  st=_st, end=_end, mfl=1;
  while (mfl)
  {
    while (true)
    {
      for (i=0; i<n; i++)
        Lv[i]=inf, B[i]=Head[i];
      Lv[st]=0, Q[0]=st, bq=0, eq=1;
      while (bq<eq) 
      {
        v=Q[bq++];
        for (r=Head[v]; r!=-1; r=Next[r])
          if (V[r]>=mfl && Lv[Dest[r]]==inf)
            Lv[Dest[r]]=Lv[v]+1, Q[eq++]=Dest[r];
      }
      if (Lv[end]==inf)
        break;
      uit++;
      while (dfs(st,inf))
        uit++;
    }
    mfl>>=1;
  }
  return flow;
}

void solve (int tst)
{
  cerr<<"Solve "<<tst<<endl;
  printf("Case #%d: ", tst);
  int i, cnte=0, n, j, k, cntl=0;
  e=0;
  memset(Head,-1,sizeof(Head));
  memset(Tp,0,sizeof(Tp));
  for (i=0; i<maxn; i++)
    Ev[i].clear();
  scanf("%d", &n), en=n+1;
  add(0,en+2,n);       
  add(en+2,en+1,2*n);
  for (i=1; i<=n; i++)
  {
    scanf(" %c %d", &Tp[i], &Id[i]);
    if (Tp[i]=='L')
      add(i,en,1), cntl++;
    else
      add(0,i,1), cnte++;
    if (Id[i])
      Ev[Id[i]].pb(i);
  }
  add(en+1,en,n+cnte-cntl);
  for (i=1; i<=n; i++)
    if (Tp[i]=='E' && Id[i]==0)
      for (j=i+1; j<=n; j++)
        if (Tp[j]=='L' && Id[j]==0)
          add(i,j,1);  
  for (i=1; i<=n; i++)
    if (Tp[i]=='L' && Id[i]==0)
      add(en+2,i,1);
  for (i=1; i<maxn; i++)
  {
    for (j=0; j<(int)Ev[i].size(); j++)
    {
      int t1=Ev[i][j], t2=(j==(int)Ev[i].size()-1)?(n+1):(Ev[i][j+1]);
      if (Tp[t1]=='E')
      {
        //cerr<<"EWEGG  "<<i<<" "<<j<<" "<<t1<<" "<<t2<<endl;
        if (t2<=n && Tp[t2]=='L')
          add(t1,t2,1);
        for (k=t1+1; k<t2; k++)
          if (Tp[k]=='L' && Id[k]==0)
            add(t1,k,1);
      }
      else
      {
        t2=(j==0)?(-1):(Ev[i][j-1]);
        for (k=t2+1; k<t1; k++)
          if (Tp[k]=='E' && Id[k]==0)
            add(k,t1,1);
      }
    }
    if (Ev[i].size())
    {
      int t=Ev[i][0];
      if (Tp[t]=='L')
        add(en+2,t,1);
    }
  }
  int flow=getflow(en+3,0,en);
  //cerr<<flow<<endl;
  assert(flow<=cnte+n);
  int ans=n+cnte-flow;
  for (i=1; i<=n; i++)
    if (Tp[i]=='E' && (Id[i]==0 || i==Ev[Id[i]].back()))
      add(i,en+1,1);
  flow=getflow(en+3,0,en);
  //cerr<<flow<<endl;
  if (ans!=flow)
  {
    puts("CRIME TIME");
    return;
  }
  printf("%d\n", ans);
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

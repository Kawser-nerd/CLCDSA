// Jakub Radoszewski

//#include<iostream>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>
#include<numeric>
#include<cassert>
using namespace std;

#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define FORD(I,A,B) for(int I=(A);I>=(B);I--)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define INFTY 100000000
#define VAR(V,init) __typeof(init) V=(init)
#define FORE(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define SIZE(x) ((int)(x).size())

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef vector<string> VS;

ll nwd(ll a,ll b) { return !b?a:nwd(b,a%b); }
inline int CEIL(int a,int b) { return a%b ? a/b+1 : a/b; }
template <class T> inline T sqr(const T&a) { return a*a; }

int los(int m)
{
  return (int)((double)m*(rand()/(RAND_MAX+1.0)));
}


/* Najliczniejsze skojarzenie w grafie dwudzielnym.
 * Zlozonosc: O(VE), ale w praktyce _bardzo_ szybkie. */


/* Wierzcholki 0..(n1-1) | n1..(n1+n2-1) */
#define MAXN 4010

int n1,n2;
VI t[MAXN];

bool c[2*MAXN];
int skoj[2*MAXN]; /* Tablica skojarzen */

bool dfs(int v)
{
  c[v]=true;
  REP(i,SIZE(t[v]))
  {
    int x=t[v][i];
    if (skoj[x]==-1 || (!c[skoj[x]] && dfs(skoj[x])))
    {
      skoj[v]=x; skoj[x]=v;
      return true;
    }
  }
  return false;
}

void kojarz()
{
  REP(i,n1+n2) skoj[i]=-1;
  bool dasie=true;
  while (dasie)
  {
    dasie=false;
    REP(i,n1) c[i]=false;
    REP(i,n1) if (skoj[i]==-1 && !c[i]) dasie|=dfs(i);
  }
}

void tc()
{
  int ile;
  scanf("%d",&ile);
  VS t1,t2;
  map<string,int> mapa1,mapa2;
  char aa[100],bb[100];
  vector<PII> kraw;
  REP(i,ile)
  {
    scanf("%s%s",aa,bb);
    string a(aa),b(bb);
    if (mapa1.find(a)==mapa1.end())
    {
      mapa1[a]=SIZE(t1);
      t1.PB(a);
    }
    if (mapa2.find(b)==mapa2.end())
    {
      mapa2[b]=SIZE(t2);
      t2.PB(b);
    }
    kraw.PB(MP(mapa1[a],mapa2[b]));
  }
  n1=SIZE(t1); n2=SIZE(t2);
  REP(i,n1+n2) t[i].clear();
  REP(i,ile)
  {
    t[kraw[i].FI].PB(n1+kraw[i].SE);
  }
  kojarz();
  int wyn=0;
  REP(i,n1) if (skoj[i]!=-1) ++wyn;
  printf("%d\n",ile-(n1+n2-wyn));
}

int main()
{
  int ILE;
  scanf("%d",&ILE);
  FOR(iii,1,ILE)
  {
    printf("Case #%d: ",iii);
    fprintf(stderr,"Case #%d:\n",iii);
    tc();
  }
  return 0;
}

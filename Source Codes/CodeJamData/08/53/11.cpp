/* Jakub Radoszewski (jakubr) */

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
#define INFTY 1000000000
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

VS parse(string s)
{
  string a;
  VS wyn;
  REP(i,(int)s.size())
    if (s[i]!=' ') a+=s[i];
    else if (!a.empty()) { wyn.PB(a); a=""; }
  if (!a.empty()) wyn.PB(a);
  return wyn;
}

int toi(char ch) { return int(ch)-int('0'); }

int chg(char ch) { return int(ch)-int('a'); }

/* Najliczniejsze skojarzenie w grafie dwudzielnym.
 * Zlozonosc: O(VE), ale w praktyce _bardzo_ szybkie. */


/* Wierzcholki 0..(n1-1) | n1..(n1+n2-1) */
#define MAXN 7010

int n1,n2;
VI t[MAXN];

bool c[2*MAXN];
int skoj[2*MAXN]; /* Tablica skojarzen */

/* Pokrycie wierzcholkowe - wrzucamy wierzcholki incydentne z jakimikolwiek
 * wierzcholkami nieskojarzonymi i jakkolwiek uzupelniamy, dodajac z kazdej
 * skojarzonej pary jeden wierzcholek. */

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

int ILE;
char tab[100][100];
int n,m;

PII daj(int i,int j)
{
  PII p;
  if (j%2==0) p.FI=1; else p.FI=2;
  p.SE=n*(j/2)+i;
  return p;
}

int x[]={0,1,0,1};
int y[]={-1,-1,1,1};
inline int ins(int g,int h) { return g>=0 && g<h; }

int main()
{
  scanf("%d",&ILE);
  FOR(LICZ,1,ILE)
  {
    printf("Case #%d: ",LICZ);
    scanf("%d%d",&n,&m);
    n1=n2=n*m;
    REP(i,n1) t[i].clear();
    REP(i,n) scanf("%s",tab[i]);
    REP(i,n/2) REP(j,m) swap(tab[i][j],tab[n-1-i][j]);
    set<pair<PII,PII> > bylo;
    REP(i,n) REP(j,m)
    {
      PII p=daj(i,j);
//      printf("(%d %d) (%d %d)\n",i,j,p.FI,p.SE);
      if (tab[i][j]=='x') continue;
      REP(z,4)
      {
        int a=i+x[z],b=j+y[z];
        if (ins(a,n) && ins(b,m))
        {
          if (tab[a][b]=='x') continue;
          PII q=daj(a,b);
          PII k=p,l=q;
          if (k.FI==2) swap(k,l);
          if (bylo.count(MP(k,l))) continue;
          t[k.SE].PB(n1+l.SE);
          bylo.insert(MP(k,l));
          bylo.insert(MP(l,k));
        }
      }
    }
    kojarz();
    int w=0;
    REP(i,n) REP(j,m) if (tab[i][j]=='.') w++;
    REP(i,n1) if (skoj[i]!=-1) w--;
    printf("%d\n",w);
  }
  return 0;
}

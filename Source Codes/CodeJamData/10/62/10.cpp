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

int los(int m)
{
  return (int)((double)m*(rand()/(RAND_MAX+1.0)));
}

void wypisz(PII p)
{
  printf("(%d %d)\n",p.FI,p.SE);
}
void wypisz(VI t)
{
  REP(i,SIZE(t)) printf("%d ",t[i]); puts("");
}
void wypisz(vector<PII> t)
{
  REP(i,SIZE(t)) printf("(%d %d) ",t[i].FI,t[i].SE); puts("");
}
void wypisz(VS t)
{
  REP(i,SIZE(t)) printf("%s\n",t[i].c_str());
}
void wypisz(vector<VI> t)
{
  REP(i,SIZE(t)) wypisz(t[i]);
}


int ILE;

int n;

VI tab[1010][3];

map<PII,PII> mapa;

int m;

int wyn;

int ob[1010];

int obejscie(int v)
{
  ob[v]=1;
  REP(jj,(v==0 ? 3 : 2))
  {
    if (!tab[v][jj].empty())
    {
      VI pom;
      REP(i,SIZE(tab[v][jj]))
      {
        int w=tab[v][jj][i];
        pom.PB(obejscie(w));
      }
      sort(ALL(pom)); reverse(ALL(pom));
      if (SIZE(pom)>1) wyn=max(wyn,2+pom[0]+pom[1]);
      ob[v]+=pom[0];
    }
  }
  if (v==0) ob[v]+=2;
  wyn=max(wyn,ob[v]);
  return ob[v];
}

int main()
{
  scanf("%d",&ILE);
  FOR(iii,1,ILE)
  {
    printf("Case #%d: ",iii);
    fprintf(stderr,"Case #%d: \n",iii);
    scanf("%d",&n);
    mapa.clear();
    mapa[MP(0,1)]=MP(0,0);
    mapa[MP(1,2)]=MP(0,1);
    mapa[MP(0,2)]=MP(0,2);
    REP(i,n) REP(j,3) tab[i][j].clear();
    m=1;
    FOR(i,3,n-1)
    {
      int a,b; scanf("%d%d",&a,&b); a--; b--;
      if (a>b) swap(a,b);
      PII q=mapa[MP(a,b)];
      tab[q.FI][q.SE].PB(m);
      mapa[MP(a,i)]=MP(m,0);
      mapa[MP(b,i)]=MP(m,1);
      m++;
    }
    wyn=0;
    obejscie(0);
    printf("%d\n",wyn);
  }
  return 0;
}

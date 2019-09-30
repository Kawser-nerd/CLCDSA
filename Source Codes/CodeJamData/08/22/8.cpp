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

int ILE;

bool pr[1000007];
int dz[1000007];

void sito()
{
  FOR(i,2,1000000) pr[i]=1;
  FOR(i,2,1000000) if (pr[i])
  {
    int j=2*i;
    while (j<=1000000) { pr[j]=0; dz[j]=max(dz[j],i); j+=i; }
  }
}

/***** Pasted code follows ****/
/* Struktura danych dla zbiorow rozlacznych.
 * Zlozonosc: O(n log*n) */

#define MAX_N 1000001
int p[MAX_N],rank[MAX_N];

inline void makeset(int x)
{
  p[x]=x; rank[x]=0;
}

int findset(int x)
{
  if (x!=p[x]) p[x]=findset(p[x]);
  return p[x];
}

inline void link(int x,int y)
{
  if (rank[x]>rank[y]) p[y]=x;
  else
  {
    p[x]=y;
    if (rank[x]==rank[y]) rank[y]++;
  }
}

inline void unia(int x,int y)
{
  if (findset(x)!=findset(y))
    link(findset(x),findset(y));
}

/**** End of pasted code ****/

ll Dz[1000007];
//ll akt[1000007];
ll a,b,P;
VI pp;

/*inline void dodziel(int x,int y)
{
  while (akt[x]%y==0) akt[x]/=y;
}*/

void sito1()
{
  FOR(i,2,1000000) if (pr[i])
  {
    ll k=((a+(i-1))/(ll)i)*(ll)i;
    int k0=int(k-a);
    pp.clear();
    while (k0<=b-a)
    {
      if ((ll)i>=P) pp.PB(k0);
//      dodziel(k0,i);
      k0+=i;
    }
    REP(j,SIZE(pp)-1) unia(pp[j],pp[j+1]);
  }
}

//vector<pair<ll,int> > qq;

/*void dobij()
{
  int i=0;
  while (i<SIZE(qq))
  {
    int i0=i;
    pp.clear();
    while (i0<SIZE(qq) && qq[i0].FI==qq[i].FI)
    {
      if (qq[i0].FI>=P) pp.PB(qq[i0].SE);
      i0++;
    }
    i=i0;
    REP(j,SIZE(pp)-1) unia(pp[j],pp[j+1]);
  }
}*/

VI pom;

int main()
{
  scanf("%d",&ILE);
  sito();
  FOR(LICZ,1,ILE)
  {
    printf("Case #%d:",LICZ);
    scanf("%I64d%I64d%I64d",&a,&b,&P);
    int l=int(b-a);
//    FOR(i,0,l) akt[i]=a+i;
    FOR(i,0,l) makeset(i);
    sito1();
//    qq.clear();
//    FOR(i,0,l) if (akt[i]>1LL) qq.PB(MP(akt[i],i));
//    sort(ALL(qq));
//    dobij();
    pom.clear();
    FOR(i,0,l) pom.PB(findset(i));
    sort(ALL(pom));
    pom.erase(unique(ALL(pom)),pom.end());
    printf(" %d\n",SIZE(pom));
  }
  return 0;
}

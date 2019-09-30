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
VI pom;
int wyn[1000007];



/* An interval tree */
int drz[2500007];
int ile;
int k,n;

inline void ustaw(int x,int w)
{
  int v=ile+x;
  drz[v]=w;
  while (v!=1)
  {
    v/=2;
    drz[v]=drz[2*v]+drz[2*v+1];
  }
}

inline int zlicz(int a,int b)
{
  if (a>b) return 0;
  int va=a+ile,vb=b+ile;
  int w=drz[va];
  if (vb!=va) w+=drz[vb];
  while (va/2!=vb/2)
  {
    if (va%2==0) w+=drz[va+1];
    if (vb%2==1) w+=drz[vb-1];
    va/=2; vb/=2;
  }
  return w;
}
/* End of the interval tree. */



inline int nast(int poz)
{
  int a=poz+1,b=k-1;
  if (zlicz(a,b)<1)
  {
    a=0; b=poz-1;
  }
  int lo=a;
  while (a<b)
  {
    int c=(a+b)/2;
    if (zlicz(lo,c)>=1) b=c; else a=c+1;
  }
  return a;
}

inline int znajdz(int poz,int ile)
{
  int a=poz,b=k-1;
  int u=-1;
  if ((u=zlicz(a,b))<ile)
  {
    a=0; b=poz-1;
    ile-=u;
  }
  int lo=a;
  while (a<b)
  {
    int c=(a+b)/2;
    if (zlicz(lo,c)>=ile) b=c; else a=c+1;
  }
  return a;
}

int main()
{
  scanf("%d",&ILE);
  FOR(LICZ,1,ILE)
  {
    printf("Case #%d:",LICZ);
    scanf("%d%d",&k,&n);
    pom.clear();
    REP(i,n) { int a; scanf("%d",&a); pom.PB(a); }
    FOR(i,1,k) wyn[i]=-1;
    ile=1;
    while (ile<k) ile*=2;
    FOR(i,1,2*ile-1) drz[i]=0;
    REP(i,k) ustaw(i,1);
    int akt=0,rozm=k;
    FOR(i,1,k)
    {
      int ile=i%rozm;
      if (!ile) ile=rozm;
      int poz=znajdz(akt,ile);
      wyn[poz+1]=i;
      ustaw(poz,0);
      if (i<k) akt=nast(poz);
      rozm--;
    }
    REP(i,n) printf(" %d",wyn[pom[i]]); puts("");
  }
  return 0;
}

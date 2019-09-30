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
typedef pair<ll,ll> PLL;
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


/* Algorytm Euklidesa. */

/* Rozszerzony Euklides.
 * Dla a i b podaje (p,q,d) takie, ze ap+bq=d. */
void euclid(int a, int b, ll &p, ll &q, int &d)
{
  if (!b) { p=1; q=0; d=a; } else
  {
    ll p1,q1; int d1;
    euclid(b,a%b,p1,q1,d1);
    d=d1;
    p=q1; q=p1-q1*(a/b);
  }
}

/* Odwrotnosc v modulo p (NWD(v,p)=1). */
int odwrotnosc(int v,int p)
{
  ll x,y; int z;
  euclid(v,p,x,y,z);
  return int(x%p+p)%p;
}

int ILE;
#define MD 10007

inline PLL cnt(int m)
{
  PLL p=MP(1,0);
  int m1=m/MD;
  p.SE=m1;
  if (m1%2==1) p.FI=-1;
  FOR(j,m1*MD+1,m) { p.FI*=(ll)j; p.FI%=MD; }
  if (m1>0)
  {
    PLL q=cnt(m1);
    p.SE+=q.SE;
    p.FI*=q.FI;
    p.FI%=MD;
  }
  return p;
}

inline int licz(int a,int b)
{
  if ((2*a-b)%3) return 0;
  int x=(2*a-b)/3;
  int y=a-2*x;
  if (x<0 || y<0) return 0;
  PLL p=cnt(x+y),q1=cnt(x),q2=cnt(y);  
  p.SE-=(q1.SE+q2.SE);
  if (p.SE) return 0;
  p.FI%=MD; p.FI=(p.FI+MD)%MD;
  q1.FI%=MD; q1.FI=(q1.FI+MD)%MD;
  q2.FI%=MD; q2.FI=(q2.FI+MD)%MD;
  ll w=p.FI;
  w*=odwrotnosc((int)q1.FI,MD); w%=MD;
  w*=odwrotnosc((int)q2.FI,MD); w%=MD;
  return w;
}

inline int doit(vector<PII> t)
{
  sort(ALL(t));
  int l=SIZE(t);
  REP(i,l-1) if (t[i].FI==t[i+1].FI) return 0;
  REP(i,l-1) if (t[i].SE>=t[i+1].SE) return 0;
  ll w=1;
  REP(i,l-1)
  {
    w*=licz(t[i+1].FI-t[i].FI,t[i+1].SE-t[i].SE);
    w%=MD;
  }
  return w;
}

PII t[20];

int main()
{
  scanf("%d",&ILE);
  FOR(LICZ,1,ILE)
  {
    printf("Case #%d: ",LICZ);
    int h,w,r;
    scanf("%d%d%d",&h,&w,&r);
    if (h==1 && w==1) { puts("1"); continue; }
    memset(t,0,sizeof(t));
    REP(i,r)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      t[i]=MP(a-1,b-1);
    }
    int wyn=0;
    REP(mask,(1<<r))
    {
      int m0=mask,il=0;
      while (m0) { il+=m0%2; m0/=2; }
      int zn=1;
      if (il%2) zn=-1;
      vector<PII> tab;
      tab.PB(MP(0,0)); tab.PB(MP(h-1,w-1));
      REP(i,r) if (mask&(1<<i)) tab.PB(t[i]);
      wyn+=zn*doit(tab);
    }
    wyn%=MD; wyn+=MD; wyn%=MD;
    printf("%d\n",wyn);
  }
  return 0;
}

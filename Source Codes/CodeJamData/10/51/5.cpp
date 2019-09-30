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
  v%=p; v+=p; v%=p;
  ll x,y; int z;
  euclid(v,p,x,y,z);
  return int(x%p+p)%p;
}

int ILE;

int tab[1000010];

void sito()
{
  FOR(i,2,1000000) tab[i]=1;
  FOR(i,2,1000000) if (tab[i])
  {
    int j=2*i;
    while (j<=1000000) { tab[j]=0; j+=i; }
  }
}

int d,k;
VI t;
int pot10[8];

void doit()
{
  if (k<=2)
  {
    if (k==2 && t[0]==t[1]) printf("%d\n",t[0]); else puts("I don't know.");
    return;
  }
  if (t[k-1]==t[k-2]) { printf("%d\n",t[k-1]); return; }
  int x=t[0],y=t[1],z=t[2];
  int mx=*max_element(ALL(t));
  int kand=-1;
  FOR(p,mx+1,pot10[d]) if (tab[p])
  {
    int pom=odwrotnosc(x-y,p);
    int A=int(((ll)(pom)*(y-z))%p); A+=p; A%=p;
    int B=int((y-(ll)A*x)%p); B+=p; B%=p;

    bool ok=1;
    REP(i,k-1) if (int(((ll)t[i]*A+B)%p)!=t[i+1]) { ok=0; break; }
    if (!ok) continue;

    int w=int(((ll)A*t[k-1]+B)%p);
//    printf("w=%d A=%d B=%d p=%d\n",w,A,B,p);
    if (kand==-1) kand=w;
    else if (kand>=0 && kand!=w) { puts("I don't know."); return; }
  }
  if (kand==-1) puts("I don't know."); else printf("%d\n",kand);
}

int main()
{
  sito();
  pot10[0]=1;
  FOR(i,1,7) pot10[i]=pot10[i-1]*10;
  scanf("%d",&ILE);
  FOR(iii,1,ILE)
  {
    printf("Case #%d: ",iii);
    fprintf(stderr,"Case #%d: \n",iii);
    scanf("%d%d",&d,&k); t.clear();
    REP(i,k)
    {
      int a; scanf("%d",&a); t.PB(a);
    }
    doit();
  }
  return 0;
}

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
ll t[32];
ll f;

#define M 18

vector<ll> u[M],v[M];


vector<ll> tab[2][M];

int licz(int ile,int poz,int kier)
{
//  printf("%d, %d %d\n",ile,poz,kier);
  int akt=0;
  REP(i,M) tab[akt][i].clear();
  tab[akt][1].PB(t[poz]);
  ile--;
  while (ile--)
  {
    poz+=kier;
    int nast=1-akt;
    REP(i,M) tab[nast][i].clear();
    REP(i,M) if (!tab[akt][i].empty())
    {
      REP(j,SIZE(tab[akt][i]))
      {
        ll x=tab[akt][i][j];
        FOR(k,-1,1) if (i+k>0) tab[nast][i+k].PB(x+(i+k)*t[poz]);
      }
    }
    akt=nast;
  }
  return akt;
}

void doit()
{
  if (n==1) { printf("%lld\n",2LL*t[0]); return; }
  ll wyn=-1LL;
  FOR(b,1,CEIL(n,2))
  {
    int akt=licz(n/2,0,1);
    REP(i,M) u[i]=tab[akt][i];
    akt=licz(CEIL(n,2),n-1,-1);
    REP(i,M) v[i]=tab[akt][i];

    REP(i,M) { sort(ALL(u[i])); u[i].erase(unique(ALL(u[i])),u[i].end());
      sort(ALL(v[i])); v[i].erase(unique(ALL(v[i])),v[i].end());
    }
    REP(i,M) if (!u[i].empty()) REP(j,SIZE(u[i]))
    {
      ll x=u[i][j];
      FOR(k,-1,1) if (i+k>0 && !v[i+k].empty())
      {
        int co=i+k;
        vector<ll>::iterator it=upper_bound(ALL(v[co]),f/2LL-x);
        if (it==v[co].begin()) continue;
        it--;
        wyn=max(wyn,x+*it);
      }
    }
  }

  printf("%lld\n",2LL*wyn);
}

int main()
{
  scanf("%d",&ILE);
  FOR(iii,1,ILE)
  {
    printf("Case #%d: ",iii);
    fprintf(stderr,"Case #%d: \n",iii);
    scanf("%d",&n);
    REP(i,n) scanf("%lld",t+i);
    scanf("%lld",&f);
    sort(t,t+n);
    FORD(i,n-1,0) t[i]=t[i]-t[i-1];
    REP(i,n-1) t[i]=t[i+1];
    ll s=0;
    n--;
    //REP(i,n) printf("%lld ",t[i]); puts("");
    REP(i,n) s+=t[i];
    if (2LL*s>f) { puts("NO SOLUTION"); continue; }
    doit();
  }
  return 0;
}

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

char aa[100],bb[100];
int n;

typedef pair<ll,pair<ll,ll> > PLLL;

PLLL wyn;

inline ll ABS(ll x)
{
  return x<0 ? -x : x;
}

inline void por(string a,string b,bool fl)
{
  ll a1=0,b1=0;
  REP(i,n) a1=10LL*a1+int(a[i]-'0');
  REP(i,n) b1=10LL*b1+int(b[i]-'0');
  if (fl) swap(a1,b1);
  wyn=min(wyn,MP(ABS(a1-b1),MP(a1,b1)));
}

void doitmn(string a,string b,int i,bool fl)
{
  if (i>=n)
  {
    por(a,b,fl);
    return;
  }
  if (a[i]=='?') a[i]='9';
  if (b[i]=='?') b[i]='0';
  doitmn(a,b,i+1,fl);
}

void doit(string a,string b,int i,bool fl)
{
  if (i>=n)
  {
    por(a,b,fl);
    return;
  }
  if (a[i]!='?' && b[i]!='?')
  {
    if (a[i]==b[i]) doit(a,b,i+1,fl); else if (a[i]<b[i]) doitmn(a,b,i+1,fl); else doitmn(b,a,i+1,!fl);
    return;
  }
  if (a[i]=='?' && b[i]=='?')
  {
    REP(x,2) REP(y,2)
    {
      if (x && y) continue;
      a[i]=char('0'+x); b[i]=char('0'+y);
      doit(a,b,i,fl);
    }
    return;
  }
  if (a[i]=='?')
  {
    REP(x,10)
    {
      a[i]=char('0'+x); doit(a,b,i,fl);
    }
  } else
  {
    doit(b,a,i,!fl);
  }
}

void tc()
{
  scanf("%s%s",aa,bb);
  string a=string(aa), b=string(bb);
  n=SIZE(a);
  wyn=MP(1000000000000000001LL,MP(1000000000000000000LL,1000000000000000000LL));
  doit(a,b,0,false);
  printf("%0*lld %0*lld\n",n,wyn.SE.FI,n,wyn.SE.SE);
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

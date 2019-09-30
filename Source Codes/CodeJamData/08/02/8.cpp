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
#include <cassert>
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
int delay,n,m;

int daj()
{
  char st[10];
  scanf("%s",st);
  int a,b;
  sscanf(st,"%d:%d",&a,&b);
  return 60*a+b;
}

PII p[110],q[110];
set<PII> pp,pk,qp,qk;

void buduj(PII a,int kto)
{
  // don't use a.FI
  int v=a.SE;
  if (!kto) { pp.erase(MP(p[v].FI,v)); pk.erase(MP(p[v].SE,v)); }
  else { qp.erase(MP(q[v].FI,v)); qk.erase(MP(q[v].SE,v)); }
  if (!kto)
  {
    set<PII>::iterator it=qp.lower_bound(MP(p[v].SE+delay,-1));
    if (it!=qp.end()) buduj(*it,1);
  } else
  {
    set<PII>::iterator it=pp.lower_bound(MP(q[v].SE+delay,-1));
    if (it!=pp.end()) buduj(*it,0);
  }
}

int main()
{
  scanf("%d",&ILE);
  FOR(LICZ,1,ILE)
  {
    scanf("%d%d%d",&delay,&n,&m);
    assert(n<=100);
    assert(m<=100);
    pp.clear(); pk.clear(); qp.clear(); qk.clear();
    REP(i,n)
    {
      int a=daj(),b=daj();
      p[i]=MP(a,b);
      pp.insert(MP(a,i)); pk.insert(MP(b,i));
    }
    REP(i,m)
    {
      int a=daj(),b=daj();
      q[i]=MP(a,b);
      qp.insert(MP(a,i)); qk.insert(MP(b,i));
    }
    int w1=0,w2=0;
    while (!pk.empty() || !qk.empty())
    {
      PII a=MP(100000,0),b=MP(100000,0);
      if (!pk.empty()) a=*(pk.begin());
      if (!qk.empty()) b=*(qk.begin());
      if (a<b) { w1++; buduj(a,0); } else { buduj(b,1); w2++; }
    }
    printf("Case #%d: %d %d\n",LICZ,w1,w2);
  }
  return 0;
}

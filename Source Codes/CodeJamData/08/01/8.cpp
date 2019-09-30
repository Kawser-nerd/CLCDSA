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
int n,m;
char st[1010];

map<string,int> mapa;
VI t;
int tab[1010][110];

int main()
{
  fgets(st,1000,stdin);
  sscanf(st,"%d",&ILE);
  FOR(LICZ,1,ILE)
  {
    t.clear();
    mapa.clear();
    fgets(st,1000,stdin);
    sscanf(st,"%d",&n);
    assert(n<=100);
    REP(i,n)
    {
      fgets(st,1000,stdin);
      mapa[string(st)]=i;
    }
    fgets(st,1000,stdin);
    sscanf(st,"%d",&m);
    assert(m<=1000);
    REP(i,m)
    {
      fgets(st,1000,stdin);
      t.PB(mapa[string(st)]);
    }
    REP(i,m) REP(j,n) tab[i][j]=INFTY;
    int wyn=INFTY;
    if (!m) wyn=0;
    else
    {
      REP(j,n) if (t[0]!=j) tab[0][j]=0;
      FOR(i,1,m-1) REP(j,n) if (t[i]!=j)
      {
        tab[i][j]=min(tab[i][j],tab[i-1][j]);
        REP(k,n) tab[i][j]=min(tab[i][j],tab[i-1][k]+1);
      }
      wyn=INFTY;
      REP(j,n) wyn=min(wyn,tab[m-1][j]);
    }
    printf("Case #%d: %d\n",LICZ,wyn);
  }
  return 0;
}

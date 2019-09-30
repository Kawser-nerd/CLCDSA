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

VS t;
int l,d,n;

VI doit(string s)
{
  VI w;
  int j=0;
  REP(i,l)
  {
    if (s[j]!='(') { w.PB(1<<(s[j]-'a')); j++; }
    else
    {
      j++;
      int pom=0;
      while (s[j]!=')') { pom |= (1<<(s[j]-'a')); j++; }
      w.PB(pom);
      j++;
    }
  }
  return w;
}

int main()
{
  scanf("%d%d%d",&l,&d,&n);
  REP(i,d)
  {
    char st[100];
    scanf("%s",st);
    t.PB(string(st));
  }
  FOR(LICZ,1,n)
  {
    printf("Case #%d: ",LICZ);
    char st[10000];
    scanf("%s",st);
    VI w=doit(string(st));
    int wyn=0;
    REP(i,d)
    {
      bool ok=1;
      REP(j,l) if (!(w[j] & (1<<(t[i][j]-'a')))) { ok=0; break; }
      if (ok) wyn++;
    }
    printf("%d\n",wyn);
  }
  return 0;
}

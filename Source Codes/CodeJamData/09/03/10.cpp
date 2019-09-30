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

string wlk="welcome to code jam";
#define MD 10000

int t[1000][30];

int main()
{
  char st[10000];
  fgets(st,10000,stdin);
  sscanf(st,"%d",&ILE);
  int k=SIZE(wlk);
  FOR(LICZ,1,ILE)
  {
    printf("Case #%d: ",LICZ);
    fgets(st,10000,stdin);
    int l=strlen(st);
    while (l>0 && st[l-1]=='\n') l--;
    REP(j,k+1) t[0][j]=0;
    t[0][0]=1;
    REP(i,l) REP(j,k+1)
    {
      t[i+1][j]=t[i][j];
      if (j==0) continue;
      if (st[i]!=wlk[j-1]) continue;
      t[i+1][j]+=t[i][j-1];
      t[i+1][j]%=MD;
    }
    printf("%04d\n",t[l][k]);
  }
  return 0;
}

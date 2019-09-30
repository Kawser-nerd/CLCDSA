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

#define M 110
#define KK 10000

char st[110];
string s;
int n;

int t[M][M][4];

void doit()
{
  REP(i,n) { REP(j,4) t[i][i][j]=2; t[i][i][s[i]-'A']=0; }
  FOR(len,1,n-1) REP(i,n)
  {
    int j=i+len;
    if (j>=n) break;
    REP(z,4)
    {
      if (z==3)
      {
        t[i][j][z]=INFTY;
        FOR(k,i,j-1) t[i][j][z]=min(t[i][j][z],t[i][k][z]+t[k+1][j][z]);
        t[i][j][z]=min(t[i][j][z], 2+t[i+1][j][s[i]-'A']);
      } else
      {
        if (s[i]-'A'==z) { t[i][j][z]=t[i+1][j][z]; continue; }
        t[i][j][z]=INFTY;
        FOR(k,i,j-1) t[i][j][z]=min(t[i][j][z],t[i][k][z]+t[k+1][j][z]);
        t[i][j][z]=min(t[i][j][z],2+t[i+1][j][s[i]-'A']);
      }
    }
  }
  printf("%d\n",t[0][n-1][3]+SIZE(s));
}

int main()
{
  scanf("%d",&ILE);
  FOR(iii,1,ILE)
  {
    printf("Case #%d: ",iii);
    fprintf(stderr,"Case #%d: \n",iii);
    scanf("%s",st);
    s=string(st); n=SIZE(s);
    doit();
  }
  return 0;
}

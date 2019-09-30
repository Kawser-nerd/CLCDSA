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
int n,m;
int t[500][500];

vector<PII> kraw[500][500];

int x[]={-1,0,0,1};
int y[]={0,-1,1,0};
inline bool ins(int g,int h) { return g>=0 && g<h; }

int c[500][500];

void dfs(int i,int j,int s)
{
  c[i][j]=s;
  REP(z,SIZE(kraw[i][j]))
  {
    PII p=kraw[i][j][z];
    if (!c[p.FI][p.SE]) dfs(p.FI,p.SE,s);
  }
}

char perm[40];
int indeg[500][500];

void doit()
{
  REP(i,n) REP(j,m) c[i][j]=0;
  int ile=0;
  REP(i,n) REP(j,m) if (!indeg[i][j]) dfs(i,j,++ile);

  FOR(i,1,ile) perm[i]='?';
  char znak='a';
  REP(i,n) REP(j,m) if (perm[c[i][j]]=='?') perm[c[i][j]]=znak++;

  REP(i,n) REP(j,m)
  {
    printf("%c",perm[c[i][j]]);
    if (j<m-1) putchar(' '); else puts("");
  }
}

int main()
{
  scanf("%d",&ILE);
  FOR(LICZ,1,ILE)
  {
    printf("Case #%d:\n",LICZ);
    scanf("%d%d",&n,&m);
    REP(i,n) REP(j,m) scanf("%d",t[i]+j);
    REP(i,n) REP(j,m) { indeg[i][j]=0; kraw[i][j].clear(); }
    REP(i,n) REP(j,m)
    {
      int best=t[i][j]+1;
      PII ba=MP(-1,-1);
      REP(z,4)
      {
        int a=i+x[z],b=j+y[z];
        if (ins(a,n) && ins(b,m))
        {
          if (t[a][b]<best) { best=t[a][b]; ba=MP(a,b); }
        }
      }
      if (best>=t[i][j]) continue; else
      {
        kraw[ba.FI][ba.SE].PB(MP(i,j));
        indeg[i][j]++;
      }
//      printf("(%d %d)  (%d %d)\n",i,j,ba.FI,ba.SE);
    }
    doit();
//    return 0;
  }
  return 0;
}

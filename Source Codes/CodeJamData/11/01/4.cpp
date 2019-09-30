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
char st[3];
int a;

vector<PII> t;

int main()
{
  scanf("%d",&ILE);
  FOR(iii,1,ILE)
  {
    printf("Case #%d: ",iii);
    fprintf(stderr,"Case #%d: \n",iii);
    scanf("%d",&n);
    t.clear();
    REP(i,n)
    {
      scanf("%s%d",st,&a);
      if (st[0]=='O') t.PB(MP(0,a)); else t.PB(MP(1,a));
    }
    int w=0;
    int p[2];
    p[0]=p[1]=1;
    vector<PII> nast;
    REP(i,n+1) nast.PB(MP(0,0));
    FORD(i,n-1,0)
    {
      if (t[i].FI==0) nast[i]=MP(t[i].SE,nast[i+1].SE); else nast[i]=MP(nast[i+1].FI,t[i].SE);
    }

    int i=0;
    while (i<n)
    {
      w++;
      int r=t[i].FI,pos=t[i].SE;
      int r1=1-r;
      int pos1;
      if (r1==0) pos1=nast[i].FI; else pos1=nast[i].SE;
      if (p[r1]<pos1) p[r1]++; else if (p[r1]>pos1) p[r1]--;

      if (p[r]==pos)
      {
        i++;
      } else
      {
        if (p[r]<pos) p[r]++; else p[r]--;
      }
    }
    printf("%d\n",w);
  }
  return 0;
}

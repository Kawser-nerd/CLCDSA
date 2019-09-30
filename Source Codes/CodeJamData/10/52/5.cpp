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


#define M 100010

int ILE;
ll s;
int n;
VI t;

ll d[M];

set<pair<ll,int> > zb;

int main()
{
  scanf("%d",&ILE);
  FOR(iii,1,ILE)
  {
    printf("Case #%d: ",iii);
    fprintf(stderr,"Case #%d: \n",iii);
    scanf("%lld%d",&s,&n);
    t.clear();
    REP(i,n)
    {
      int a; scanf("%d",&a); t.PB(a);
    }
    sort(ALL(t));
    int m=t.back();
    t.pop_back(); n--;
    REP(i,m) d[i]=1000000000000000000LL+10;
    d[0]=0LL; zb.clear();
    zb.insert(MP(d[0],0));

    while (!zb.empty())
    {
      pair<ll,int> p=*zb.begin(); zb.erase(zb.begin());
      int x=p.SE;
      REP(i,n)
      {
        int y=(x+t[i])%m;
        ll q=d[x]+1;
        if (x+t[i]>=m) q--;
        if (d[y]>q)
        {
          zb.erase(MP(d[y],y));
          d[y]=q;
          zb.insert(MP(d[y],y));
        }
      }
    }
    int poz=int(s%m);
    if (d[poz]>=1000000000000000000LL+10) puts("IMPOSSIBLE");
    else printf("%lld\n",s/m+d[poz]);
  }
  return 0;
}

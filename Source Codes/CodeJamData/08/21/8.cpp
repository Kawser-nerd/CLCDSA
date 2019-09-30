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

int s[3][3];

int main()
{
  scanf("%d",&ILE);
  FOR(LICZ,1,ILE)
  {
    memset(s,0,sizeof(s));
    vector<PII> t;
    printf("Case #%d:",LICZ);
    int n, A, B, C, D, x0, y0, M;
    scanf("%d%d%d%d%d%d%d%d",&n, &A, &B, &C, &D, &x0, &y0, &M);
    int X = x0, Y = y0;
    t.PB(MP(X,Y));
    FOR(i,1,n-1)
    {
      X = ((ll)A * X + B) % (ll)M;
      Y = ((ll)C * Y + D) % (ll)M;
      t.PB(MP(X,Y));
    }
    sort(ALL(t));
    t.erase(unique(ALL(t)),t.end());
//    REP(i,n) printf("%d %d\n",t[i].FI,t[i].SE);
    REP(i,SIZE(t)) s[t[i].FI%3][t[i].SE%3]++;
    ll licz=0LL;
    REP(i,9) FOR(j,i,8) FOR(k,j,8)
    {
      PII x=MP(i/3,i%3);
      PII y=MP(j/3,j%3);
      PII z=MP(k/3,k%3);
      if (!((x.FI+y.FI+z.FI)%3==0 && (x.SE+y.SE+z.SE)%3==0)) continue;
      vector<PII> tab;
      tab.PB(x); tab.PB(y); tab.PB(z);
      sort(ALL(tab));
      ll akt=1LL;
      int ii=0;
      while (ii<3)
      {
        int ii0=ii;
        while (ii0<3 && tab[ii0]==tab[ii]) ii0++;
        int X=tab[ii].FI,Y=tab[ii].SE;
        if (ii0-ii==1) akt*=(ll)s[X][Y];
        else if (ii0-ii==2) akt*=(ll)s[X][Y]*(ll)(s[X][Y]-1)/2LL;
        else akt*=(ll)s[X][Y]*(ll)(s[X][Y]-1)*(ll)(s[X][Y]-2)/6LL;
        ii=ii0;
      }
      licz+=akt;
    }
    printf(" %I64d\n",licz);
  }
  return 0;
}

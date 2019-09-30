/* Jakub Radoszewski (jakubr) */

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
int n;
int X[]={0,1,0,-1};
int Y[]={1,0,-1,0};

typedef unsigned int uint;
uint t[12010][(12010+31)/32];
uint il[12010][(12010+31)/32];
int sr=6006;

#define JEDEN(x) ((x)/32)
#define DWA(x) ((x)%32)

int main()
{
  scanf("%d",&ILE);
  FOR(LICZ,1,ILE)
  {
    memset(t,0,sizeof(t));
    memset(il,0,sizeof(il));
    printf("Case #%d: ",LICZ);
    scanf("%d",&n);
    int x=sr,y=sr;
    int kx=0,ky=1;
    int kn=0;
    int minx=13000,maxx=-13000,miny=13000,maxy=-13000;
    REP(i,n)
    {
      char st[1000]; int l,len;
      scanf("%s%d",st,&l); len=strlen(st);
      while (l--)
      {
        REP(i,len)
        {
          if (st[i]=='F')
          {
            t[x+kx][JEDEN(y+ky)] |= (1U<<DWA(y+ky));
            x+=2*kx; y+=2*ky;
            assert(x>=0 && x<12010);
            assert(y>=0 && y<12010);
            minx=min(minx,x); maxx=max(maxx,x);
            miny=min(miny,y); maxy=max(maxy,y);
          }
          else if (st[i]=='R') { kn=(kn+1)%4; kx=X[kn]; ky=Y[kn]; }
          else { kn=(kn+3)%4; kx=X[kn]; ky=Y[kn]; }
        }
      }
    }
    FOR(i,minx,maxx) if (i%2)
    {
      int ile=0;
      int j1=miny,j2=maxy;
      while (!(t[i][JEDEN(j2)] & (1U<<DWA(j2)))) j2--;
      while (!(t[i][JEDEN(j1)] & (1U<<DWA(j1)))) j1++;
      FOR(j,j1,j2)
      {
        ile^=(t[i][JEDEN(j)] >> (DWA(j))) & 1;
        if (i%2 && j%2 && !(t[i][JEDEN(j)] & (1U<<DWA(j))) && !ile)
        {
          il[i][JEDEN(j)] |= (1U<<DWA(j));
        }
      }
    }
    FOR(j,miny,maxy) if (j%2)
    {
      int ile=0;
      int i1=minx,i2=maxx;
      while (!(t[i2][JEDEN(j)] & (1U<<DWA(j)))) i2--;
      while (!(t[i1][JEDEN(j)] & (1U<<DWA(j)))) i1++;
      FOR(i,i1,i2)
      {
        ile^=(t[i][JEDEN(j)] >> (DWA(j))) & 1;
        if (i%2 && j%2 && !(t[i][JEDEN(j)] & (1U<<DWA(j))) && !ile)
        {
          il[i][JEDEN(j)] |= (1U<<DWA(j));
        }
      }
    }
    int s=0;
    FOR(i,minx,maxx) if (i%2) FOR(j,miny,maxy) s+=(il[i][JEDEN(j)] >> DWA(j)) & 1;
    printf("%d\n",s);
  }
  return 0;
}

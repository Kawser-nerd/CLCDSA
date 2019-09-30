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


#define MD 1000000007

inline void dodmod(int &a,int b)
{
  a+=b;
  a%=MD;
//  while (a>=MD) a-=MD;
}


int ILE;
ll n;
int b;

int t[100];
int len;


int d[71][71][71][71][2]; // (rozwazany gosc+1, liczba_uzytych, suma, przeniesienie)
int D[71][71][71][2]; // (liczba_uzytych, suma, przeniesienie)

void dp1()
{
  memset(d,0,sizeof(d));
//  REP(i,b+1) REP(j,b+1) REP(k,b+1) REP(l,b+1) d[i][j][k][l]=0;
  d[0][0][0][0][0]=1;

  REP(i,b) REP(j,b+1) REP(k,b+1) REP(l,b+1) REP(z,2) if (d[i][j][k][l][z])
  {
    dodmod(d[i+1][j][k][l][z], d[i][j][k][l][z]);
    dodmod(d[i+1][j+1][(k+i)%b][(k+i>=b) ? l+1 : l][(i==0) ? 1 : z], d[i][j][k][l][z]);
  }

  memset(D,0,sizeof(D));
  REP(j,b+1) REP(k,b+1) REP(l,b+1) REP(z,2) D[j][k][l][z]=d[b][j][k][l][z];
//  REP(j,b+1) REP(k,b+1) REP(l,b+1) REP(z,2) if (D[j][k][l][z]) printf("%d %d %d:  %d\n",j,k,l,D[j][k][l][z]);
}

int sil[200];

int dwum[200][200];

int tab[72][72][72][2]; // (poz,max_liczb,poprz_przen)

void dp2()
{
  memset(tab,0,sizeof(tab));
  tab[0][b][0][0]=1;
  REP(i,len) FOR(j,0,b) REP(k,b+1) REP(z,2) if (tab[i][j][k][z])
  {
    int cel=(t[i]-k+b)%b; // taka chce reszte
    FOR(use,0,j) // tylu uzywam
    {
      REP(przen1,b+1) REP(z1,2) if (D[use][cel][przen1][z1])
      {
        int wartosc=tab[i][j][k][z];
        wartosc=int(((ll)(wartosc)*D[use][cel][przen1][z1])%MD);
        if (i>0)
        {
          if (z==0)
          {
            wartosc=int(((ll)(wartosc)*dwum[j][use])%MD);
            wartosc=int(((ll)(wartosc)*sil[use])%MD);
          } else
          {
            // z==1
            wartosc=int(((ll)(wartosc)*dwum[j-1][use-1])%MD);
            wartosc=int(((ll)(wartosc)*sil[use])%MD);
          }
        }
        int new_przen=(cel+przen1*b+k)/b;
//        printf("tu: %d %d %d:  %d  (z %d %d %d)\n",i+1,use,new_przen,wartosc,i,j,k);
        dodmod(tab[i+1][use][new_przen][z1], wartosc);
      }
    }
  }
//  REP(i,len+1) FOR(j,0,b) REP(k,b+1) REP(z,2) if (tab[i][j][k][z]) printf("%d %d %d:  %d\n",i,j,k,tab[i][j][k][z]);
  ll wyn=0;
  FOR(mx,0,b) wyn+=tab[len][mx][0][0];
  wyn%=MD; wyn+=MD; wyn%=MD;
  printf("%lld\n",wyn);
}


int main()
{
  sil[0]=1;
  FOR(i,1,199) sil[i]=int(((ll)(sil[i-1])*i)%MD);
//  FOR(i,0,5) printf("%d ",sil[i]); puts("");
  dwum[0][0]=1;
  FOR(i,1,199)
  {
    dwum[i][0]=dwum[i][i]=1;
    FOR(j,1,199-1) dwum[i][j]=(dwum[i-1][j-1]+dwum[i-1][j])%MD;
  }
//  FOR(i,1,5) { FOR(j,0,i) printf("%d ",dwum[i][j]); puts(""); }

  scanf("%d",&ILE);
  FOR(iii,1,ILE)
  {
    printf("Case #%d: ",iii);
    fprintf(stderr,"Case #%d: \n",iii);
    scanf("%lld%d",&n,&b);
    len=0;
    while (n>0)
    {
      t[len]=n%b; n/=b; len++;
    }
//    REP(i,len) printf("%d",t[i]); puts("");
    dp1();
    dp2();
  }
  return 0;
}

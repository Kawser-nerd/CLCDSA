#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cmath>
using namespace std;

typedef vector <int > VI;
typedef vector < VI > VVI;
typedef long long LL;
typedef vector < LL > VLL;
typedef vector < double > VD;
typedef vector < string > VS;
typedef pair<int,int> PII;
typedef vector <PII> VPII;
typedef istringstream ISS;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(var,pocz,koniec) for (int var=(pocz); var<=(koniec); ++var)
#define FORD(var,pocz,koniec) for (int var=(pocz); var>=(koniec); --var)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)x.size()

typedef long double LD;

const LD EPS = 1e-9;
inline bool IsZero(LD x){ return x>=-EPS && x<=EPS; }
#define POINTT LD // Dla wspolrzednych punktu (int lub double)
#define POINTR LD // Dla wynikow operacji - pole, iloczyn wektorowy (LL lub double)
struct POINT {
    POINTT x,y;
    POINT(POINTT wx, POINTT wy) : x(wx), y(wy) {}
    POINT() {}
    bool operator ==(POINT& a) {return a.x==x && a.y==y;}
};
#define SQ(x) ((x)*(x))
vector<POINT> CirclesCross(POINT c1, POINTR c1r, POINT c2, POINTR c2r){
  vector<POINT> r;
  c2.x -= c1.x; c2.y-= c1.y;
  if (IsZero(c2.x) && IsZero(c2.y)) return r;
  LD A = (-SQ(c2r)+SQ(c1r)+SQ(c2.x)+SQ(c2.y))/2.0;
  if (IsZero(c2.y)){
    LD x = A/c2.x; LD y2=SQ(c1r)-SQ(x);
    if (y2 <-EPS) return r;
    if(IsZero(y2)) r.PB(POINT(c1.x+x,c1.y));
    else{
      r.PB(POINT(c1.x+x,c1.y+sqrtl(y2)));
      r.PB(POINT(c1.x+x,c1.y-sqrtl(y2)));
    }
    return r;
  }
  LD a = SQ(c2.x) + SQ(c2.y);
  LD b = -2.0 *A * c2.x;
  LD d = 4.0*((SQ(c2.x)+SQ(c2.y))*SQ(c1r)-A*A);
  if (d<-EPS) return r;
  LD x = -b/(2.0*a);
  if (IsZero(d)) r.PB(POINT(c1.x + x, c1.y+(A - c2.x*x)/c2.y));
  else{
    LD e = sqrtl(d)*c2.y/(2.0*a);
    r.PB(POINT(c1.x+x+e, c1.y+(A-c2.x*(x+e))/c2.y));
    r.PB(POINT(c1.x+x-e, c1.y+(A-c2.x*(x-e))/c2.y));
  }
  return r;
}

const int N = 210;
int x[N], y[N], r[N];

int dasie(int n,LD promien){
  vector<POINT> kand;
  REP(i,n){
    if (promien < r[i]) return 0;
    kand.PB(POINT(x[i]+promien-r[i],y[i]));
  }
  REP(i,n) REP(j,i){
    LD r1 = promien - r[i];
    LD r2 = promien - r[j];
    vector<POINT> v = CirclesCross(POINT(x[i],y[i]),r1,POINT(x[j],y[j]),r2);
    FOREACH(it,v) kand.PB(*it);
  }
  vector<LL> maski;
  REP(i,SIZE(kand)){
    LL maska = 0;
    REP(j,n){
      LD dist = sqrtl(SQ(kand[i].x-x[j])+SQ(kand[i].y-y[j]));
      if (dist <= promien - r[j] + EPS){
        maska |= 1LL << (LL)j;
      } 
    }
    maski.PB(maska);
  }
  REP(i,SIZE(maski)) REP(j,SIZE(maski)){
    int ok = 1;
    REP(k,n) if (!((1LL << k)&maski[i]) && !((1LL << k)&maski[j])){
      ok = 0;
      break;
    }
    if (ok) return 1;
  }
  return 0;
}

int main(){
  int testy;
  scanf("%d",&testy);
  REP(numer,testy){
    printf("Case #%d: ", numer+1);
    int n;
    scanf("%d",&n);
    REP(i,n) scanf("%d %d %d",x+i,y+i,r+i);
    LD lewo = 0.0, prawo = 10000.0;
    REP(foo,100){
      LD srodek = (lewo+prawo) / 2;
      if (dasie(n,srodek)) prawo = srodek;
      else lewo = srodek;
    }
    printf("%.9Lf\n",lewo);
  }
  return 0;
}

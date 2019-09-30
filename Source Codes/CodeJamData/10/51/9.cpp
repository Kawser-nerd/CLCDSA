#include <cassert>
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

LL NWDR(LL a, LL b, LL &xp, LL &yp) {
  if (a==0) { xp=0; yp=1; return b; }
  LL x,y;
  LL d = NWDR(b%a, a, x, y);
  yp = x;
  xp = y-(b/a)*x;
  return d;
}
LL RevMod(LL a, LL p){
  LL x, y;
  NWDR(a, p, x, y);
  if (x < 0LL) return (p - ((-x) % (LL)p)) % p;
  return x % (LL)p;
}

/* eliminacja Gaussa w Zp
   zwraca -1 - brak rozwiązań 
   wymiar przestrzeni rozwiazan (przykładowe w x)
   modyfikuje podane wektory*/
LL P;
int Gauss(vector< vector<int> >& a, vector<int>& b, vector<int>& x){
  int m = a.size(), n = a[0].size(), k, r;
  vector<int> q;
  for (k = 0; k < min(m, n); k++) {
    int i, j;
    for (j = k; j < n; j++)
      for (i = k; i < m; i++)
        if (a[i][j] != 0) goto found;
    break;
found:
    if (j != k) REP(t, m) swap(a[t][j], a[t][k]);
    q.push_back(j);
    if (i != k) {swap(a[i], a[k]); swap(b[i], b[k]);}
    FOR(j, k + 1, m - 1) if (a[j][k] != 0){
      LL l = (a[j][k] * RevMod(a[k][k],P)) % P;
      FOR(i, k + 1, n - 1) a[j][i] = (P + a[j][i] - (l * a[k][i]) % P) % P;
      b[j] = (P + b[j] - (l * b[k]) % P) % P;
    }
  }
  r = k; //r == rzad macierzy a
  x.clear(); x.resize(n, 0);
  FOR(k, r, m - 1) if (b[k] != 0) return -1;
  FORD(k, r - 1, 0) {
    LL s = b[k];
    FOR(j, k + 1, r - 1) s = (P + s - (a[k][j] * x[j]) % P) % P;
    x[k] = (s * RevMod(a[k][k], P)) % P;
  }
  FORD(k, r - 1, 0) swap(x[k], x[q[k]]);
  return n - r;
}


inline int between(LL a, LL b, LL c){
  return a >= b && a <= c;
}

int licz(int p, const VI &v, int &next){
  P = p;
  if (SIZE(v) <= 2) return 2;
  FOREACH(it, v) if (*it >= p) return 0;
  vector<vector<int> > a;
  VI b, x;
  REP(i,SIZE(v)-1){
    VI pom;
    pom.PB(v[i]);
    pom.PB(1);
    a.PB(pom);
    b.PB(v[i+1]);
  }
  int wym = Gauss(a,b,x);
  if (wym == -1) return 0;
  if (wym > 0) return 2;
  assert(wym == 0);
  int A = x[0], B = x[1];
  REP(i,SIZE(v)-1){
    LL x = (LL)v[i] * A + B;
    x %= p;
    assert(v[i+1] == x);
  }
  int kand = ((LL)v.back() * (LL)A + B)% p;
  if (kand != next){
    next = kand;
    return 1;
  }
  return 0;
}

const int N = 1100 * 1000;
int prime[N];

void init(){
  REP(i,N) prime[i] = 1;
  prime[0] = prime[1] = 0;
  FOR(i,2,N-1) if (prime[i]){
    for (int j = 2*i; j < N; j += i) prime[j] = 0;
  }
}

int main(){
  init();
  int testy;
  scanf("%d",&testy);
  int numer=0;
  while (testy--){
    printf("Case #%d: ",++numer);
    int d,n;
    scanf("%d %d",&d,&n);
    VI v;
    REP(i,n){
      int x;
      scanf("%d",&x);
      v.PB(x);
    }
    int done = 0;
    REP(i,SIZE(v)-1) if (v[i] == v.back()){
      done = 1;
      printf("%d\n", v[i+1]);
      goto hell;
    }
hell:
    if (done) continue;

    int ogr = 1;
    REP(foo,d) ogr *= 10;
    int next = -1;
    int mozliwosci = 0;
    FOR(p,2,ogr) if (prime[p]){
      mozliwosci += licz(p, v, next);
      //        printf("p = %d, a = %d, mozliwosci = %d, next = %d\n", p, a, mozliwosci, next);
      if (mozliwosci >= 2) goto hell2;
    }
hell2:
    assert(mozliwosci > 0 && (mozliwosci >= 2 || next >= 0));
    if (mozliwosci >= 2) puts("I don't know.");
    else printf("%d\n",next);
    fflush(stdout);
  }
  return 0;
}

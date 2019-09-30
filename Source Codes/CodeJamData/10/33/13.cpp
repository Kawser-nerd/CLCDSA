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
#include <cassert>
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

const int N=550;
char txt[N];

int plansza[N][N];
int max_kwadrat[N][N];
int n,m;

void licz_kwadraty(){
  FORD(i,n-1,0) FORD(j,m-1,0){
    max_kwadrat[i][j] = 1;
    int ok = 1;
    REP(dx,2) REP(dy,2) {
      if (i+dx >= n || j + dy >= m || plansza[i+dx][j+dy] != plansza[i][j]) ok = 0;
    }
    if (ok) max_kwadrat[i][j] = min(min(max_kwadrat[i+1][j], max_kwadrat[i][j+1]), max_kwadrat[i+1][j+1])+1;
  }
}

int rozmiary[N];

//sprawdzenie czy w danym przedziale domknietym cos jest w zbiorze
int pusty_przedzial(const set<int> &zbior, int a,int b){
  set<int>::iterator it=zbior.lower_bound(a);
  if (it == zbior.end()) return 1;
  return *it > b;
}

void symuluj(){
  set<int> kolumny[N], wiersze[N];
  priority_queue<pair<int,PII> > q; //para jest z minusami
  REP(i,n) REP(j,m) q.push(MP(max_kwadrat[i][j],MP(-i,-j)));
  FOR(i,0,max(n,m)) rozmiary[i] = 0;
  while (!q.empty()){
    pair<int,PII> p = q.top();
    q.pop();
    int i = -p.ND.ST;
    int j = -p.ND.ND;
    //sprawdzam czy rozmiar jest aktualny idąc od prawej i od dołu
    int r = max_kwadrat[i][j];
    int ok = 1;
    FORD(k,r-1,0){
      if (!pusty_przedzial(wiersze[i+k],j,j+k) || !pusty_przedzial(kolumny[j+k],i,i+k)){
        ok = 0;
        max_kwadrat[i][j] = k;
        q.push(MP(k,MP(-i,-j)));
        break;
      }
    }
    if (ok && r > 0){
      //printf("wycinam r=%d, i=%d, j=%d\n", r, i, j);
      //wycinamy
      rozmiary[r]++;
      REP(a,r) REP(b,r) {
        assert(wiersze[i+a].count(j+b) == 0);
        assert(kolumny[j+b].count(i+a) == 0);
        wiersze[i+a].insert(j+b);
        kolumny[j+b].insert(i+a);
      }
    }
  }
  VPII res;
  FOR(i,0,max(n,m)) if (rozmiary[i]) res.PB(MP(i,rozmiary[i]));
  reverse(ALL(res));
  printf("%d\n", SIZE(res));
  FOREACH(it, res) printf("%d %d\n", it->ST, it->ND);
}

int main(){
  int testy;
  scanf("%d",&testy);
  int numer=0;
  while (testy--){
    printf("Case #%d: ",++numer);
    scanf("%d %d",&n,&m);
    assert(n < N && m < N);
    REP(i,n){
      scanf("%s",txt);
      int pos = 0;
      REP(j,m/4){
        int x = isdigit(txt[j]) ? txt[j]-'0' : (tolower(txt[j]) - 'a') + 10;
        FORD(k,3,0) plansza[i][pos++] = !!(x & (1<<k));
      }
    }
    REP(i,n) REP(j,m) if ((i^j)&1) plansza[i][j]^=1;
    /*
    REP(i,n){
      REP(j,m) printf("%d",plansza[i][j]);
      puts("");
    }
    puts("");
    */

    licz_kwadraty();
    symuluj();
    fflush(stdout);
  }
  return 0;
}

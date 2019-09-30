#include <cstring>
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

inline int between(LL a, LL b, LL c){
  return a >= b && a <= c;
}

const int BASE = 4 * 1024 * 1024;
int drzewo[2*BASE];
int min_puste[2*BASE];
int max_puste[2*BASE];

set<int> duze; //co najmniej pary

void dodaj(int pos,int ile){
  assert(pos >= 0);
  assert(pos < BASE);
  pos += BASE;
  if (drzewo[pos] >= 2){
    assert(duze.count(pos));
    duze.erase(pos);
  }
  drzewo[pos] += ile;
  if (drzewo[pos] >= 2){
    duze.insert(pos);
  }
  assert(drzewo[pos] >= 0);
  if (drzewo[pos] == 0) min_puste[pos] = max_puste[pos] = pos-BASE;
  else min_puste[pos] = max_puste[pos] = -1;
  pos >>= 1;

  while (pos >= 1){
    drzewo[pos] = drzewo[2*pos] + drzewo[2*pos+1];
    assert(drzewo[pos] >= 0);
    int i = pos;
    min_puste[i] = (min_puste[2*i] != -1) ? min_puste[2*i] : min_puste[2*i+1];
    max_puste[i] = (max_puste[2*i+1] != -1) ? max_puste[2*i+1] : max_puste[2*i];
    pos >>= 1;
  }
}

int ile_na_lewo(int pos){
  assert(pos >= 0);
  assert(pos < BASE);
  int orig = pos;
  pos += BASE;
  while (pos > 1){
    if (pos % 2 == 1){
      int kand = max_puste[pos-1];
      if (kand != -1) return orig-kand-1;
    }
    pos >>= 1;
  }
  assert(0);
}

int ile_na_prawo(int pos){
  assert(pos >= 0);
  assert(pos < BASE);
  int orig = pos;
  pos += BASE;
  while (pos > 1){
    if (pos % 2 == 0){
      int kand = min_puste[pos+1];
      if (kand != -1) return kand-orig-1;
    }
    pos >>= 1;
  }
  assert(0);
}

void init(){
  duze.clear();
  memset(drzewo,0,sizeof(drzewo));
  REP(i,BASE) min_puste[i+BASE] = max_puste[i+BASE] = i;
  FORD(i,BASE-1,1){
    min_puste[i] = (min_puste[2*i] != -1) ? min_puste[2*i] : min_puste[2*i+1];
    max_puste[i] = (max_puste[2*i+1] != -1) ? max_puste[2*i+1] : max_puste[2*i];
  }
}

int main(){
  int testy;
  scanf("%d",&testy);
  int numer=0;
  while (testy--){
    printf("Case #%d: ",++numer);
    int zajete;
    scanf("%d",&zajete);
    init();
    REP(i,zajete){
      int a,b;
      scanf("%d %d",&a,&b);
      a += BASE/2;
      assert(BASE+a < 2 * BASE);
      assert(drzewo[BASE+a] == 0);
      dodaj(a, b);
    }
    LL res = 0;
    while (!duze.empty()){
      int pos = *duze.begin();
      assert(drzewo[pos] >= 2);
    //  printf("pos=%d val=%d\n", pos-BASE-BASE/2, drzewo[pos]);
      pos -= BASE;
      int a = ile_na_lewo(pos);
      int b = ile_na_prawo(pos);
      res += (LL)(a+1) * (LL)(b+1);
      dodaj(pos,-1);
      dodaj(pos-a-1,1);
      dodaj(pos+b+1,1);
      dodaj(pos-a+b,-1);
    }
    printf("%lld\n", res);
    fflush(stdout);
  }
  return 0;
}

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

const LL P = 1000000009;
const int N = 110;

struct Stan{
  int i; //numer wiersza
  int j; //numer kolumny
  PII przedzial_moj;
  PII przedzial_dol;
  int ile_spadlem;
  Stan(int _i, int _j, PII _przedzial_moj, PII _przedzial_dol, int _ile_spadlem){
    i = _i; j = _j;
    przedzial_moj = _przedzial_moj;
    przedzial_dol = _przedzial_dol;
    ile_spadlem = _ile_spadlem;
  }
  LL haszuj() const {
    LL res = 0;
    res = res * P + i;
    res = res * P + j;
    res = res * P + ile_spadlem;
    res = res * P + przedzial_moj.ST;
    res = res * P + przedzial_moj.ND;
    res = res * P + przedzial_dol.ST;
    res = res * P + przedzial_dol.ND;
    return res;
  }
};

map<LL,int> mapa_odleglosci;
set<LL> visited;
char plansza[N][N];
deque<Stan> q;

void ruszaj(int dist, const Stan &stan, int koszt){
  LL hasz = stan.haszuj();
  if (mapa_odleglosci.count(hasz) == 0 || mapa_odleglosci[hasz] > dist+koszt){
    mapa_odleglosci[hasz] = dist+koszt;
    if (koszt == 0) q.push_front(stan);
    else q.push_back(stan);
  }
}

int main(){
  int testy;
  scanf("%d",&testy);
  REP(numer,testy){
    printf("Case #%d: ", numer+1);
    int wiersze, kolumny, zasieg;
    scanf("%d %d %d",&wiersze,&kolumny,&zasieg);
    REP(i,wiersze) scanf("%s",plansza[i]);
    mapa_odleglosci.clear();
    visited.clear();
    while (!q.empty()) q.pop_back();
    Stan stan(0,0,MP(N,N),MP(N,N),0);
    ruszaj(0, stan, 0);
    LL hasz;
    int wynik = -1;
    while (!q.empty()){
      stan = q.front();
      q.pop_front();
      hasz = stan.haszuj();
      if (visited.count(hasz)) continue;
      visited.insert(hasz);
      int dist = mapa_odleglosci[hasz];
      if (stan.i == wiersze) {
        wynik = dist;
        break;
      }
      //Spadanie
      if (plansza[stan.i][stan.j] == '.' || (stan.przedzial_dol.ST <= stan.j && stan.j <= stan.przedzial_dol.ND)){
        if (stan.ile_spadlem+1 <= zasieg){
          Stan nowy(stan.i+1,stan.j,stan.przedzial_dol,MP(N,N),stan.ile_spadlem+1);
          ruszaj(dist,nowy,0);
        }
        continue;
      } 
      //Ruchy na boki
      FOR(dj,-1,1) if (dj != 0){
        int nj = stan.j+dj;
        if (nj >= 0 && nj < kolumny){
          //jestesmy na planszy
          if (stan.i == 0 || (plansza[stan.i-1][nj] == '.' || (stan.przedzial_moj.ST <= nj && nj <= stan.przedzial_moj.ND))){
            //mamy wolne pole
            Stan nowy(stan.i,nj,stan.przedzial_moj,stan.przedzial_dol,0);
            ruszaj(dist,nowy,0);
          }
        }
      }

      // Kopiemy w bok
      FOR(dj,-1,1) if (dj != 0){
        int kopj = stan.j+dj;
        if (kopj >= 0 && kopj < kolumny){
          if (plansza[stan.i][kopj] == '#'){
            if (stan.i==0 || plansza[stan.i-1][kopj] == '.' || (stan.przedzial_moj.ST <= kopj && kopj <= stan.przedzial_moj.ND)){
              int ok = 0;
              PII p;
              if (stan.przedzial_dol.ST == N){
                ok = 1;
                p = MP(kopj,kopj);
              } else if (stan.przedzial_dol.ST == kopj+1){
                ok = 1;
                p = MP(kopj,stan.przedzial_dol.ND);
              } else if (stan.przedzial_dol.ND == kopj-1){
                ok = 1;
                p = MP(stan.przedzial_dol.ST, kopj);
              }
              if (ok){
                Stan nowy(stan.i,stan.j,stan.przedzial_moj,p,0);
                ruszaj(dist,nowy,1);
              }
            }
          }
        }
      }
    }
    if (wynik == -1){
      printf("No\n");
    } else {
      printf("Yes %d\n", wynik);
    }
  }
  return 0;
}

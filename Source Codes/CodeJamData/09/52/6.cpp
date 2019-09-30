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
#include <cstring>
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

int k;
const int MOD = 10009;
map<string,int> mapa, nowa_mapa;

vector<string> rozdziel(string s){
  REP(i,SIZE(s)) if (s[i] == '+') s[i] = ' ';
  istringstream in(s);
  vector<string> res;
  while (in >> s){
    res.PB(s);
  }
  return res;
}

void wstaw_do_mapy(string s){
  int n = SIZE(s);
  int ile = 1<<n;
  REP(mask,ile) {
    string podciag;
    REP(i,n) if ((1<<i) & mask) podciag += s[i];
    mapa[podciag] = 0;
  }
}

void dopisz(string s){
  FOREACH(it, mapa){
    string term = it->ST;
    if (term == "") {
      nowa_mapa[term] = (nowa_mapa[term] + mapa[term]) % MOD;
    } else {
      VI nowe_litery;
      REP(i,SIZE(term)){
        char c = term[i];
        int acc = 0;
        REP(j,SIZE(s)) if (s[j] == c) acc++;
        nowe_litery.PB(acc);
      }
      int n = SIZE(term);
      int ile = 1<<n;
      REP(mask,ile){
        string podciag;
        int stala = 1 % MOD;
        REP(i,n) if ((1<<i) & mask){
          podciag += term[i];
        } else {
          stala = (LL)stala * nowe_litery[i] % MOD;
        }
        nowa_mapa[term] += (LL)stala * mapa[podciag] % MOD;
      }
    }
  }
}

char txt[1000];

int main(){
  int testy;
  scanf("%d",&testy);
  REP(numer,testy){
    printf("Case #%d:", numer+1);
    scanf("%s",txt);
    scanf("%d",&k);
    mapa.clear();
    vector<string> termy = rozdziel(txt);
//    FOREACH(it,termy) printf("term %s\n",it->c_str());
    FOREACH(it,termy) wstaw_do_mapy(*it);
    mapa[""] = 1;

    int slowa;
    scanf("%d",&slowa);
    vector<string> slownik;
    REP(i, slowa){
      scanf("%s",txt);
      slownik.PB(txt);
    }

    REP(foo,k){
      nowa_mapa.clear();
      FOREACH(it, slownik) dopisz(*it);
      mapa = nowa_mapa;
      int res = 0;
      FOREACH(it, termy) res = (res + mapa[*it]) % MOD;
      printf(" %d",res);
    }
    puts("");
  }
  return 0;
}

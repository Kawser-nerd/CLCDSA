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

int main(){
  int testy;
  scanf("%d",&testy);
  REP(numer,testy){
    printf("Case #%d: ", numer+1);
    int n;
    scanf("%d",&n);
    vector<string> plansza;
    REP(i,n){
      char txt[110];
      scanf("%s",txt);
      string s(txt);
      plansza.PB(s);
    }
    int res = 0;
    REP(pos,n){
      REP(i,SIZE(plansza)){
        int dobry = 1;
        FOR(j,pos+1,n-1) if (plansza[i][j]=='1'){
          dobry = 0;
          break;
        }
        if (dobry){
          FOR(j,i+1,SIZE(plansza)-1) plansza[j-1] = plansza[j];
          plansza.pop_back();
          break;
        } else res++;
      }
    }
    if (SIZE(plansza)>0) {
      printf("ERROR\n");
      exit(1);
    }
    printf("%d\n",res);
  }
  return 0;
}

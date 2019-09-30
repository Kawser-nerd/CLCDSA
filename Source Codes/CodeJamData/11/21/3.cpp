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
typedef long double LD;

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

int n; char t[200][200];
LD wp[200];
LD owp[200];
LD oowp[200];

int main(){
  int te; scanf("%d", &te);
  FOR(iii, 1, te){
    printf("Case #%d:\n", iii);
    scanf("%d", &n);
    REP(i, n) scanf("%s", t[i]);

    // wp
    REP(i, n){
      int a = 0, b = 0;
      REP(j, n){
        if (t[i][j] != '.') b++;
        if (t[i][j] == '1') a++;
      }
      wp[i] = (LD)a / (LD)b;
    }
    // owp
    REP(i, n){
      LD x = (LD)0; int c = 0;
      REP(j, n) if (t[i][j] != '.'){
        int a = 0, b = 0;
        REP(k, n) if (k != i){
          if (t[j][k] != '.') b++;
          if (t[j][k] == '1') a++;
        }
        x += (LD)a / (LD)b;
        c++;
      }
      x /= (LD)c;
      owp[i] = x;
    }
    // oowp
    REP(i, n){
      LD x = (LD)0; int c = 0;
      REP(j, n) if (t[i][j] != '.'){
        x += owp[j];
        c++;
      }
      x /= (LD)c;
      oowp[i] = x;
    }
    // out
    REP(i, n){
//      printf("WP = %.06Lf OWP = %.06Lf OOWP = %.06Lf\n", wp[i], owp[i], oowp[i]);
      printf("%.09Lf\n", (wp[i] + owp[i] + owp[i] + oowp[i])/(LD)4);
    }
  }
  return 0;
}

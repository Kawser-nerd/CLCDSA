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

const LL INF = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1100LL;
int d, c, p[300], v[300];

bool check(LL t){
  LL ost = -INF;
  REP(i, c){
    LL a = (LL)(v[i]-1) * (LL)d;
    if (a > t) return false;
    if (ost > (LL)p[i] + t - a - a) return false;
    if (ost < (LL)p[i] - t) ost = (LL)p[i] - t;
    ost += (LL)v[i] * (LL)d * 2LL;
  }
  return true;
}

int main(){
  int te; scanf("%d", &te);
  FOR(iii, 1, te){
    scanf("%d%d", &c, &d);
    REP(i, c) scanf("%d%d", &p[i], &v[i]);
    REP(i, c) p[i] *= 2;
    LL sta = 0LL, kon = INF;
    while (sta < kon){
      LL x = (sta + kon)/2LL;
      if (check(x)) kon = x;
      else sta = x+1LL;
    }
    printf("Case #%d: %lld.%d\n", iii, sta/2LL, ((int)(sta % 2LL))*5);
  }
  return 0;
}

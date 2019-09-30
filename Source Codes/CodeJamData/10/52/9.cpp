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

const int N = 110000;
const int INF = 1000000000;

int dist[N];

int main(){
  int testy;
  scanf("%d",&testy);
  int numer=0;
  while (testy--){
    printf("Case #%d: ",++numer);
    LL l;
    int n;
    scanf("%lld %d",&l,&n);
    int duzy = 0;
    VI v;
    REP(i,n){
      int x;
      scanf("%d",&x);
      duzy = max(duzy,x);
      v.PB(x);
      assert(x < N);
    }
    REP(i,duzy) dist[i] = INF;
    dist[0] = 0;
    priority_queue<PII> q;
    q.push(MP(0,0));
    while (!q.empty()){
      PII p = q.top();
      q.pop();
      p.ST = -p.ST;
      assert(dist[p.ND] <= p.ST);
      if (dist[p.ND] != p.ST) continue;
      int x = p.ND;
      assert(dist[x] < INF);
      FOREACH(it,v){
        int nowy = (x+*it) % duzy;
        int koszt = dist[x] + 1 - (x+*it >= duzy);
        if (dist[nowy] > koszt){
          dist[nowy] = koszt;
          q.push(MP(-koszt,nowy));
        }
      }
    }
    if (dist[l % duzy] == INF) puts("IMPOSSIBLE");
    else {
      printf("%lld\n", dist[l % duzy] + l / duzy);
    }
    fflush(stdout);
  }
  return 0;
}

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <complex>
#include <sstream>
#include <climits>
#include <cassert>
using namespace std;
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define SIZE(c) ((int)((c).size()))
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
#define ALL(v) (v).begin(), (v).end()
 
#define pb push_back
#define mp make_pair
#define st first
#define nd second

void scase(int CASEID) {
  int W,L,N;
  scanf("%d%d%d",&N,&W,&L);
  PII T[N];
  REP(i,N) {
    T[i].second = i;
    scanf("%d",&T[i].first);
  }
  
  sort(T, T+N);
  pair<double,double> position[N];
  
  double x = 0;
  int dir = 1;
  int i = 0;
  while (i < N) {
    position[i].first = x;
    position[i].second = 0;
    
    REP(j,i) {
      double r2 = (T[i].first + T[j].first) * (double)(T[i].first + T[j].first);
      double dy = sqrt(max(0.0, r2 - (position[j].first - position[i].first) * (position[j].first - position[i].first)));
      if (dy > 0) position[i].second = max(position[i].second, position[j].second + dy + 0.1);  
    }
    
    if (i == N-1) break;
    if (dir == 1) {
      x += T[i].first + T[i+1].first + 0.1;
      if (x > W) {
        x = W;
        dir = 0;
      }
    } else {
      x -= T[i].first + T[i+1].first + 0.1;
      if (x < 0) {
        x = 0;
        dir = 1;
      }        
    }
    ++i;
  }
  
  REP(i,N) {
    assert(0 <= position[i].first && position[i].first <= W);
    assert(0 <= position[i].second && position[i].second <= L);    
  }
  REP(i,N)REP(j,i) {
    double tmp = (position[i].first - position[j].first) * (position[i].first - position[j].first) + 
                 (position[i].second - position[j].second) * (position[i].second - position[j].second);
    assert(sqrt(tmp) >= T[i].first + T[j].first);
  }
  pair<double,double> out[N];
  REP(i,N) out[T[i].second] = position[i];
  printf("Case #%d:", CASEID);
  REP(i,N) printf(" %0.6lf %0.6lf", out[i].first, out[i].second);
  printf("\n");
  
}

int main() {
  int T;
  scanf("%d",&T);
  FOR(t,1,T+1)scase(t);
}

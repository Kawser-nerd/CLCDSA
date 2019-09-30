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
  int N;
  scanf("%d",&N);
  int D[N+1];
  int L[N];
  REP(i,N) scanf("%d%d",&D[i], &L[i]);
  scanf("%d",&D[N]);
  L[N] = 1;
  int W[N+1];
  W[0] = D[0];
  for (int i = 1; i <= N; ++i) W[i] = -1;
  REP(i,N) {
    if (W[i] < 0) continue;
    for (int j = i+1; j <= N; ++j) {
      if (D[j] - D[i] <= W[i])
        W[j] = max(W[j], D[j] - D[i]);
      W[j] = min(W[j], L[j]);
    }
  }
  
  printf("Case #%d: %s\n", CASEID, W[N] >= 0 ? "YES" : "NO");
}

int main() {
  int T;
  scanf("%d",&T);
  FOR(t,1,T+1)scase(t);
}

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

const int HMAX = 1000000000;
void scase(int CASEID) {
  printf("Case #%d:", CASEID);

  int N;
  scanf("%d",&N);
  int H[N];
  int T[N];
  REP(i,N-1) {
    scanf("%d",&T[i]);
    --T[i];
  }
  H[N-1] = HMAX;
  
  set<int> line;
  line.insert(N-1);
  FORD(i,N-1,0) {
    if (line.find(T[i]) == line.end()) goto fail;
    while (*line.begin() < T[i]) line.erase(line.begin());
    for (int k = T[i] - 1; k >= i + 1; --k) H[k] -= (T[i] - k); 
    H[i] = HMAX - (N-1 - i);    
    line.insert(i);
  }
  REP(i,N) printf(" %d", H[i]);
  printf("\n");
  return;
  fail:printf(" Impossible\n");
}

int main() {
  int T;
  scanf("%d",&T);
  FOR(t,1,T+1)scase(t);
}

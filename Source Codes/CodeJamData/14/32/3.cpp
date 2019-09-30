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

char cars[100][200];
int L[100];

const LL MOD = 1000000007;

int next[100];
int prev[100];
bool visited[100];

void scase() {
  int N;
  scanf("%d", &N);
  REP(i,N)scanf("%s",&cars[i]);
  REP(i,N)L[i] = strlen(cars[i]);
  REP(i,N)REP(a,L[i]) cars[i][a] -= 'a';

  LL result = 1;
  int comps = 0;
  
  REP(i,N) {
    int a = 0;
    while (a < L[i] && cars[i][a] == cars[i][0]) ++a;
    int b = L[i] - 1;
    while (b >= 0 && cars[i][b] == cars[i][L[i]-1]) --b;
    FOR(c,a,b+1) {
      char X = cars[i][c];
      REP(j,N) if (i != j) REP(d,L[j]) if (cars[j][d] == X) goto fail;
    }
  }
  
  REP(i,26) next[i] = prev[i] = -1;
  REP(i,N)REP(a,L[i]-1) {
    if (cars[i][a] != cars[i][a+1]) {
      if (next[cars[i][a]] != -1) goto fail;
      next[cars[i][a]] = cars[i][a+1];
      if (prev[cars[i][a+1]] != -1) goto fail;
      prev[cars[i][a+1]] = cars[i][a];
    }
  }

  REP(c,26) {
    int only = 0;
    int all = 0;
    REP(i,N) {
      only += (cars[i][0] == c && cars[i][L[i]-1] == c);
      all += (cars[i][0] == c || cars[i][L[i]-1] == c);
    }
    
    if (only == 0) continue;
    FOR(i,1,only + 1) result = (result * i) % MOD;
    if (only == all) ++comps;
  }

  REP(c,26) visited[c] = false;
  REP(c,26) {
    if (visited[c] || (prev[c] != -1)) continue;
    visited[c] = true;
    if (next[c] == -1) continue;
    comps++;
    int d = c;
    while (d != -1) {
      visited[d] = true;
      d = next[d];
    }
  }

  REP(c,26) if (!visited[c]) goto fail;
  FOR(i,1,comps+1) result = (result * i) % MOD;
  
  printf("%d\n", (int) result);
  
  return;
  fail:
    printf("0\n");
}

int main() {
  int Z;
  scanf("%d", &Z);
  REP(z,Z) {
    printf("Case #%d: ", z+1);
    scase();
  }
}    

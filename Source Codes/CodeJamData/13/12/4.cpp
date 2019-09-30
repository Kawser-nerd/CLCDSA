#include<cstdio>
#include<cassert>
#include<cstring>
#include<map>
#include<set>
#include<time.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<utility>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int n;
long long E, R, v[10000];
long long distributed[10000];

long long cache[100][1001];

long long go(int task, int energy) {
  if(task == n) return 0;
  long long& ret = cache[task][energy];
  if(ret != -1) return ret;
  ret = 0;
  for(int use = 0; use <= energy; ++use) {
    int nextEnergy = min(E, (energy - use) + R);
    long long cand = v[task] * use + go(task + 1, nextEnergy);
    ret = max(ret, cand);
  }
  return ret;
}

long long dp() {
  memset(cache, -1, sizeof(cache));
  return go(0, E);
}

long long solve() {
  long long ret = 0;

  distributed[0] = E;
  for(int i = 1; i < n; ++i) distributed[i] = min(R, E);

  for(int i = 1; i < n; ++i) {
    int j = i-1;
    while(j >= 0 && 
          distributed[i] < E && 
          v[j] < v[i]) {
      long long take = min(E - distributed[i], distributed[j]);
      distributed[j] -= take;
      distributed[i] += take;
      --j;
    }
  }

  for(int i = 0; i < n; ++i) 
    ret += distributed[i] * v[i];

  if(E <= 1000 && n <= 100) {
    assert(ret == dp());
    fprintf(stderr, "checked\n");
  }
  return ret;
}

int main() {
  int cases;
  cin >> cases;
  for(int cc = 0; cc < cases; ++cc) {
    cin >> E >> R >> n;
    for(int i = 0; i < n; ++i) cin >> v[i];
    printf("Case #%d: %Ld\n", cc+1, solve());
    // printf("Case #%d: %Ld\n", cc+1, dp());
  }
}


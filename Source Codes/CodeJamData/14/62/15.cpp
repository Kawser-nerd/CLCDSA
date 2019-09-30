/* Writen by Filip Hlasek 2014 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 22
int N, p[MAXN];

bool fine(vector<int> v) {
  int N = v.size();
  REP(i, N / 2) if (v[2 * i] + 1 != v[2 * i + 1]) return false;
  if (N % 2 && v[N - 1] != N - 1) return false;
  return true;
}

map<pair<vector<int>, int>, long long > dp;
long long solve (vector<int> v, int used) {
  // printf("v(used: %d, sz: %d): ", used, (int)v.size()); REP(i, v.size()) printf(" %d", v[i]); printf("\n");

  pair<vector<int>, int> state = make_pair(v, used);
  if (v.size() == 1) {
    long long ans = 1;
    REP(i, used) ans *= i + 1;
    return dp[state] = ans;
  }
  if (dp.count(state)) return dp[state];
  long long ans = 0;
  int N = v.size();
  REP(i, N) REP(j, i) {
    swap(v[i], v[j]);
    if (fine(v)) {
      vector<int> w;
      REP(i, (N + 1) / 2) w.push_back(v[2 * i] / 2);
      ans += solve(w, used + 1);
    }
    swap(v[i], v[j]);
  }
  if (fine(v)) {
    vector<int> w;
    REP(i, (N + 1) / 2) w.push_back(v[2 * i] / 2);
    ans += solve(w, used);
  }

  return dp[state] = ans;
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  FOR(testcase, 1, T) {
    scanf("%d", &N);
    REP(i, 1 << N) scanf("%d", p + i);
    printf("Case #%d: ", testcase);
    vector<int> v;
    REP(i, 1 << N) v.push_back(p[i] - 1);
    printf("%lld\n", solve(v, 0));
  }
 return 0;
}

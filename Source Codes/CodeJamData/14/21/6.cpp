#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>
#include <cmath>
#include <string> 
#include <ctime>

using namespace std;

#undef Fdg_Home

void solveTest(int CS) {
  printf("Case #%d: ", CS);
  int n;
  scanf("%d", &n);
  vector<string> v(n);
  vector<int> it(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  int ans = 0;
  while (it[0] < v[0].size()) {
    int p = it[0];
    vector<int> cnt;
    for (int i = 0; i < n; ++i) {
      if (it[i] == v[i].size() || v[i][it[i]] != v[0][p]) {
        printf("Fegla Won\n");
        return;
      }
      int c = 0;
      while (it[i] < v[i].size() && v[i][it[i]] == v[0][p]) {
        ++it[i];
        ++c;
      }
      cnt.push_back(c);
    }
    int add = 100000000;
    for (int i = 0; i < cnt.size(); ++i) {
      int cur = 0;
      for (int j = 0; j < cnt.size(); ++j) {
        cur += abs(cnt[i] - cnt[j]);
      }
      add = min(add, cur);
    }
    ans += add;
  }
  for (int i = 0; i < n; ++i) {
    if (it[i] != v[i].size()) {
      printf("Fegla Won\n");
      return;
    }
  }
  printf("%d\n", ans);
}

int main() {
#ifndef Fdg_Home
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  scanf("%d\n", &T);
  for (int test = 1; test <= T; ++test) {
    solveTest(test);
  }
  return 0;
}
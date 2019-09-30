#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

std::vector<int64_t> sftnum;

void bfs(int64_t n, bool seven, bool five, bool three) {
  if (n < std::pow(10, 9)) {
    bfs(n * 10 + 3, seven, five, true);
    bfs(n * 10 + 5, seven, true, three);
    bfs(n * 10 + 7, true, five, three);
  } else
    return;

  if (seven && five && three) {
    sftnum.push_back(n);
  }
  return;
}

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  int64_t n;
  cin >> n;

  bfs(0, false, false, false);
  std::sort(sftnum.begin(), sftnum.end());
  int i;
  for (i = 0; i < sftnum.size(); i++) {
    if (sftnum[i] > n) break;
  }
  cout << i << endl;

  return 0;
}
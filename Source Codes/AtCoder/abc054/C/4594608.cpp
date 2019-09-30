#include <algorithm>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

void OutputError(std::string s) {
  cerr << "\033[93m" << s << "\033[m" << endl;
  return;
}

std::vector<int> node_to[10];

int n, m;

int64_t result = 0;

void DFS(int node_now, int visited, int destination) {
  if (node_now == destination) {
    int complete = (1 << n) - 1;
    if (visited == complete) {
      result++;
    }
    return;
  } else {
    for (auto next : node_to[node_now]) {
      int mask = (1 << (next - 1));
      if ((mask & visited) == 0) {
        DFS(next, (visited | mask), destination);
      }
    }
    return;
  }
}

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    node_to[a].push_back(b);
    node_to[b].push_back(a);
  }

  for (int i = 2; i <= n; i++) {
    DFS(1, 1, i);
  }
  cout << result << endl;

  return 0;
}
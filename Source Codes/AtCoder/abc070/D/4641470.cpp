#include <algorithm>
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
struct Node {
  int64_t to, cost;
  Node(int b, int c) {
    to   = b;
    cost = c;
  }
};
int n;
int q, k;

std::vector<Node> tree[100001];
int64_t cost[100001];
bool visited[100001];

void dfs(int64_t now, int64_t cos) {
  visited[now] = true;
  cost[now]    = cos;
  for (auto next : tree[now]) {
    if (!visited[next.to]) {
      dfs(next.to, next.cost + cost[now]);
    }
  }
  return;
}

int main(void) {
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int m1, m2, m3;
    cin >> m1 >> m2 >> m3;
    tree[m1].push_back(Node(m2, m3));
    tree[m2].push_back(Node(m1, m3));
  }
  cin >> q >> k;
  dfs(k, 0);
  // cout << "----debug" << endl;
  // for (int i = 1; i <= n; i++) {
  //   cout << cost[i] << endl;
  // }
  // cout << "----debug" << endl;
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    cout << cost[x] + cost[y] << endl;
  }
  return 0;
}
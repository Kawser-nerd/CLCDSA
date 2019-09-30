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

// Manages Union-Find Forest.
class UnionFindForest {
  std::vector<int> parent_;
  std::vector<int> rank_;
  std::vector<int> size_;

 public:
  // Initialize forest.
  // parent[i]=i, rank[i]=0.
  UnionFindForest(int n);
  // Get the number of the root of the node q.
  int Root(int q);
  // Return true if the roots of x and y is same.
  bool IsSame(int x, int y);
  // Unite the tree x and tree y.
  void Unite(int x, int y);
  int Size(int q);
};
int UnionFindForest::Size(int q) {
  return size_[Root(q)];
}
UnionFindForest::UnionFindForest(int n) {
  for (int i = 0; i < n; i++) {
    parent_.push_back(i);
    rank_.push_back(0);
    size_.push_back(1);
  }
}
int UnionFindForest::Root(int q) {
  if (parent_[q] == q) {
    return q;
  } else {
    return parent_[q] = Root(parent_[q]);
  }
}

bool UnionFindForest::IsSame(int x, int y) {
  return Root(x) == Root(y);
}

void UnionFindForest::Unite(int x, int y) {
  x = Root(x);
  y = Root(y);
  if (x == y) return;
  if (rank_[x] < rank_[y]) {
    parent_[x] = y;
    size_[y] += size_[x];
    size_[x] = 0;

  } else {
    parent_[y] = x;
    size_[x] += size_[y];
    size_[y] = 0;
    if (rank_[x] == rank_[y]) rank_[x]++;
  }
}

struct Queue {
  int a, b;
  Queue(int x, int y) {
    a = x;
    b = y;
  }
};

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  int64_t n, m;
  cin >> n >> m;
  UnionFindForest UFF(n + 1);
  std::vector<Queue> q;
  std::vector<int64_t> result;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    q.push_back(Queue(x, y));
  }
  int64_t answer = n * (n - 1) / 2;
  result.push_back(answer);
  for (int i = m - 1; i >= 0; i--) {
    int a = q[i].a;
    int b = q[i].b;
    // cout << a << " " << b << endl;
    if (UFF.IsSame(a, b)) {
      result.push_back(answer);
    } else {
      // cerr << UFF.Size(a) << "\t" << UFF.Size(b) << endl;
      answer -= UFF.Size(a) * UFF.Size(b);
      result.push_back(answer);
      UFF.Unite(a, b);
    }
  }

  for (int i = m - 1; i >= 0; i--) {
    cout << result[i] << endl;
  }

  return 0;
}
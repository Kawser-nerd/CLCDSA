#include <algorithm>
#include <chrono>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

#define llong long long

using namespace std;
const int IINF = 2147483647;
const llong LLINF = 9223372036854775807;

// UnionFind
class UNF {
 private:
  int s;
  vector<int> tree, rank;
  int getP(int i) {
    if (tree[i] == -1)
      return i;
    else
      return tree[i] = getP(tree[i]);
  }

 public:
  UNF(int n) {
    s = n;
    tree.resize(s, -1);
    rank.resize(s, 1);
  }
  int size() { return s; }
  void connect(int a, int b) {
    a = getP(a);
    b = getP(b);
    if (a == b) return;
    if (rank[a] >= rank[b]) {
      tree[b] = a;
      rank[a] += rank[b];
    } else {
      tree[a] = b;
      rank[b] += rank[a];
    }
  }
  bool check(int a, int b) { return getP(a) == getP(b); }
};

int main(){
  UNF uf(13);
  uf.connect(1, 3);
  uf.connect(3, 5);
  uf.connect(5, 7);
  uf.connect(7, 8);
  uf.connect(8, 10);
  uf.connect(10, 12);
  uf.connect(4, 6);
  uf.connect(6, 9);
  uf.connect(9, 11);
  int x, y;
  cin >> x >> y;
  cout << (uf.check(x, y) ? "Yes" : "No");
  return 0;
}
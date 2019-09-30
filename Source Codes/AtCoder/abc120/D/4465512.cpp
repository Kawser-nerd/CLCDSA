#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>

class UnionFind {
public:
  std::vector<int> data;
  UnionFind(int size) { data.assign(size, -1); }
  int find(int x) {
    if (data[x] < 0) {
      return x;
    } else {
      data[x] = find(data[x]);
      return data[x];
    }
  }
  void unite(int x, int y) {
    int xpar = find(x);
    int ypar = find(y);
    if (xpar != ypar) {
      if (data[xpar] > data[ypar])
        std::swap(xpar, ypar);
      data[xpar] += data[ypar];
      data[ypar] = xpar;
    }
  }
  int size(int x) { return -1 * data[find(x)]; }
};

int main() {
  long long n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int, int>> bridges(m);
  for (int i = 0; i < m; i++) {
    std::cin >> bridges[i].first >> bridges[i].second;
    bridges[i].first--;
    bridges[i].second--;
  }

  UnionFind uf(n);
  std::vector<long long> answers(m);
  answers[m-1] = (long long) n * (n - 1) / 2;

  for (int i = m-2; i >= 0; i--) {
    int a = bridges[i+1].first;
    int b = bridges[i+1].second;
    if (uf.find(a) != uf.find(b)) {
      answers[i] = answers[i+1] - (long long)(uf.size(a) * uf.size(b));
      uf.unite(a, b);
    } else {
      answers[i] = answers[i+1];
    }
  }
  for (int i = 0; i < m; i++)
    std::cout << answers[i] << std::endl;
}
#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
  int _size;
  unique_ptr<int[]> _parent; // ?????????????????????

 public:
  // n?????
  explicit UnionFind(int n) : _size{n}, _parent{make_unique<int[]>(n)} {
    for (int i{}; i < n; ++i) {
      _parent[i] = -1;
    }
  }

  // ???????
  int find(int x) {
    if (x < 0 || x >= _size) {
      return x;
    }

    if (_parent[x] < 0) {
      return x;
    }

    return _parent[x] = find(_parent[x]);
  }

  // x?y???????????
  bool unite(int x, int y) {
    if (x < 0 || x >= _size || y < 0 || y >= _size) {
      return false;
    }

    x = find(x);
    y = find(y);
    if (x == y) {
      return false;
    }

    if (size(x) > size(y)) {
      _parent[x] += _parent[y];
      _parent[y] = x;
    } else {
      _parent[y] += _parent[x];
      _parent[x] = y;
    }

    return true;
  }

  // x?y??????????
  bool same(int x, int y) {
    return find(x) == find(y);
  }

  // x?????????????
  int size(int x) {
    return -_parent[find(x)];
  }

  // ?????????
  int size() {
    return _size;
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for (int i{}; i < M; ++i) {
    cin >> A[i] >> B[i];
    --A[i];
    --B[i];
  }

  UnionFind uni(N);

  vector<long long> ans(M);
  ans[M - 1] = (long long) N * (N - 1) / 2;

  for (int i{M - 1}; i >= 1; --i) {
    ans[i - 1] = ans[i];
    if (uni.find(A[i]) != uni.find(B[i])) {
      ans[i - 1] -= (long long) uni.size(A[i]) * uni.size(B[i]);
      uni.unite(A[i], B[i]);
    }
  }

  for (int i{}; i < M; ++i) {
    cout << ans[i] << endl;
  }
  return 0;
}
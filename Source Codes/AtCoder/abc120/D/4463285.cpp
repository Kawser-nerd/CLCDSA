#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class UnionFind {
 private:
  T _size;
  vector<T> _parent; // ????????????????????????

 public:
  // n?????
  explicit UnionFind(T n) : _size{n}, _parent{vector<T>(n, -1)} {}

  // ???????
  T find(T x) {
    if (x < 0 || x >= _size) {
      return x;
    }

    if (_parent[x] < 0) {
      return x;
    }

    return _parent[x] = find(_parent[x]);
  }

  // x?y???????????
  bool unite(T x, T y) {
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
  bool same(T x, T y) {
    return find(x) == find(y);
  }

  // x?????????????
  T size(T x) {
    if (x < 0 || x >= _size) {
      return 1;
    }

    return -_parent[find(x)];
  }

  // ?????????
  T size() {
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

  UnionFind<int> uni(N);

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
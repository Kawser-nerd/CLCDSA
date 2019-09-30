#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

class DisjointSet {
 public:
  std::vector<unsigned> parent;
  std::vector<unsigned> rank;
  DisjointSet(unsigned size)
      : parent(size),
        rank(size, 0u) {
    for (unsigned i = 0; i < size; ++i) { parent[i] = i; }
  }
  unsigned find(unsigned index) {
    if (parent[index] != index) { return parent[index] = find(parent[index]); }
    else { return index; }
  }
  void merge(unsigned index_a, unsigned index_b) {
    auto parent_a = find(index_a);
    auto parent_b = find(index_b);
    if (parent_a == parent_b) { return; }
    if (rank[parent_a] < rank[parent_b]) { parent[parent_a] = parent_b; }
    else if (rank[parent_b] < rank[parent_b]) { parent[parent_b] = parent_a; }
    else {
      ++rank[parent_a];
      parent[parent_b] = parent_a;
    }
  }
};

template<class T>
class FenwickTree {
 public:
  std::vector<T> data;
  FenwickTree<T>(unsigned size) : data(size + 1u, 0) {}
  T sum(unsigned index) {
    ++index;
    T ret = 0;
    while (index) {
      ret += data[index];
      index &= index - 1u;
    }
    return ret;
  }
  void add(unsigned index, T x) {
    ++index;
    while (index < data.size()) {
      data[index] += x;
      index += index & (~index + 1u);
    }
  }
};

int main() {
  unsigned N, a, b;
  std::cin >> N >> a >> b;
  --a;
  --b;
  std::vector<std::pair<std::pair<int, int>, unsigned>> hole(N);
  for (unsigned i = 0; i < N; ++i) {
    unsigned x, y;
    std::cin >> x >> y;
    hole[i].first.first = x + y;
    hole[i].first.second = x - y;
    hole[i].second = i;
  }
  auto D = std::max(std::abs(hole[a].first.first - hole[b].first.first),
                    std::abs(hole[a].first.second - hole[b].first.second));
  auto cmp_first = [](std::pair<std::pair<int, int>, unsigned> i,
                      std::pair<std::pair<int, int>, unsigned> j) -> bool {
    return (i.first.first < j.first.first) || (i.first.first == j.first.first && i.first.second < j.first.second);
  };
  auto cmp_second = [](std::pair<std::pair<int, int>, unsigned> i,
                       std::pair<std::pair<int, int>, unsigned> j) -> bool {
    return (i.first.second < j.first.second) || (i.first.second == j.first.second && i.first.first < j.first.first);
  };
  std::sort(hole.begin(), hole.end(), cmp_first);
  //count??????????union find???????????????????????????
  //add????dfs???fenwick tree?add????????
  FenwickTree<long long> fenwickTree0(N+1);
  FenwickTree<long long> fenwickTree1(N+1);
  DisjointSet disjointSet(N+1);
  std::vector<long long> degree(N, 0);
  auto prev_p = hole.begin();
  for (unsigned i = 0; i < N; ++i) {
    auto key = std::make_pair(std::make_pair(hole[i].first.first + D, hole[i].first.second - D), 0);
    auto pl = std::lower_bound(hole.begin(), hole.end(), key, cmp_first);
    key.first.second += 2 * D - 1;
    auto pu = std::upper_bound(hole.begin(), hole.end(), key, cmp_first);
    fenwickTree0.add((unsigned int) (pl - hole.begin()), 1);
    fenwickTree0.add((unsigned int) (pu - hole.begin()), -1);
    for (auto p = std::max(prev_p, pl); p < pu; ++p) {
      disjointSet.merge(hole[i].second, p->second);
    }
    prev_p = pu - pl > 0 ? pu - 1 : pu;
  }
  for (unsigned i = 0; i < N; ++i) {
    degree[hole[i].second] += fenwickTree0.sum(i);
  }
  std::sort(hole.begin(), hole.end(), cmp_second);
  prev_p = hole.begin();
  //(0,2) or (2,0)???
  for (unsigned i = 0; i < N; ++i) {
    auto key = std::make_pair(std::make_pair(hole[i].first.first - D + 1, hole[i].first.second + D), 0);
    auto pl = std::lower_bound(hole.begin(), hole.end(), key, cmp_second);
    key.first.first += 2 * D;
    auto pu = std::upper_bound(hole.begin(), hole.end(), key, cmp_second);
    fenwickTree1.add((unsigned int) (pl - hole.begin()), 1);
    fenwickTree1.add((unsigned int) (pu - hole.begin()), -1);
    for (auto p = std::max(prev_p, pl); p < pu; ++p) {
      disjointSet.merge(hole[i].second, p->second);
    }
    prev_p = pu - pl > 0 ? pu - 1 : pu;
  }
  for (unsigned i = 0; i < N; ++i) {
    degree[hole[i].second] += fenwickTree1.sum(i);
  }
  auto k = disjointSet.find(a);
  long long ans = 0;
  for (unsigned i = 0; i < N; ++i) {
    if (k == disjointSet.find(i)) {
      ans += degree[i];
    }
  }
  std::cout << ans;
  return 0;
}
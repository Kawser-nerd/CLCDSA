#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <utility>
using namespace std;

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

int main(int argc, char const *argv[]) {
  int N,K,L;
  cin >> N >> K >> L;
  struct UnionFind road(N);//??
  struct UnionFind rail(N);//??
  //??????
  for(int i = 0; i < K; i++){
    int p,q;
    cin >> p >> q;
    p -= 1;
    q -= 1;
    road.unionSet(p,q);
  }
  //????
  for(int i = 0; i < L; i++){
    int p,q;
    cin >> p >> q;
    p -= 1;
    q -= 1;
    rail.unionSet(p,q);
  }
  std::vector<struct pair<int,int>> root(N);//first?road?second?rail
  for(int i = 0; i < N; i++){
    root[i].first = road.root(i);
    root[i].second = rail.root(i);
  }
  sort(root.begin(), root.end());
  //????
  for(int i = 0; i < N; i++){
    struct pair<int,int> g(road.root(i),rail.root(i));
    vector<struct pair<int,int>>::iterator up_b = upper_bound(root.begin(),root.end(),g);
    vector<struct pair<int,int>>::iterator lo_b = lower_bound(root.begin(),root.end(),g);
    cout << distance(lo_b, up_b) << " ";
  }
}
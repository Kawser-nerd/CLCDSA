#include <iostream>
#include <vector>
using namespace std;
// http://www.prefield.com/algorithm/container/union_find.html
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


int main(){
    int N, M, x, y;
    cin >> N;
    cin >> M;
    UnionFind G = UnionFind(N);
    vector<int> p(N, -1);
    for(int i=0; i<N; ++i){
        cin >> p[i];
    }
    for(int i=0; i<M; ++i){
        cin >> x;
        cin >> y;
        G.unionSet(x-1, y-1);
    }
    int cnt = 0;
    for(int i=0; i<N; ++i)
        cnt += G.findSet(p[i]-1, i);
    cout << cnt;
}
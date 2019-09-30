#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

class UnionFindTree{
  public:
    int size;
    vector< int > parent;
    vector< int > rank;
    vector< int > sizes;

    UnionFindTree(int n):
      size(n), parent(n, -1), rank(n, 0), sizes(n, 1){}

    int root(int x){
      return ((parent[x] < 0) ?
          x : parent[x] = root(parent[x]));
    }

    int get_size(int v){
      return sizes[root(v)];
    }

    bool unite(int x, int y){
      int rx = root(x), ry = root(y);
      if(rx == ry){
        return false;
      }
      if(rank[rx] < rank[ry]){
        parent[rx] = ry;
        sizes[ry] += sizes[rx];
      }
      else{
        parent[ry] = rx;
        sizes[rx] += sizes[ry];
      }
      if(rank[rx] == rank[ry]){
        ++rank[rx];
      }
      --size;
      return true;
    }

    bool same(int x, int y){
      return root(x) == root(y);
    }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  int a[m], b[m];
  for(int i = 0; i < m; i++){
    cin >> a[i] >> b[i];
    --a[i]; --b[i];
  }

  ll ans[m];
  UnionFindTree uft(n);
  ll sum = (ll)n * (n - 1) / 2;
  for(int i = m - 1; i >= 0; i--){
    ans[i] = sum;
    if(!uft.same(a[i], b[i])){
      ll ca = uft.get_size(a[i]);
      ll cb = uft.get_size(b[i]);
      uft.unite(a[i], b[i]);
      sum -= ca * cb;
    }
  }

  string buf;
  for(int i = 0; i < m; i++){
    buf += to_string(ans[i]) + "\n";
  }

  cout << buf;

  return 0;
}
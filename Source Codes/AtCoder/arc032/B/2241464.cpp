#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

class UnionFindTree {
  private: 
    vector<int> v; // parent
    vector<int> rank; // ??
  public:
    UnionFindTree(int max) {
      v = vector<int>(max);
      rank = vector<int>(max);
      for (int i=0; i<max; i++) v[i] = i;
    }

    int find(int x) {
      if(v[x] == x) return x;
      else return v[x] = find(v[x]);
    }

    // x?y????
    void unite(int x, int y) {
      x = find(x);
      y = find(y);
      if (x == y) return;


      if (rank[x] < rank[y]) v[x] = y;
      else {
        v[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
      }
    }

    bool same(int x, int y) {
      return find(x) == find(y);
    }

    int types() {
      for (int i=0; i<v.size(); i++) find(i);

      vector<int> a = v;
      sort(a.begin(), a.end());
      a.erase(unique(a.begin(), a.end()), a.end());
      return (int)a.size();
    }

    void display() {
      for (int i=0; i<v.size(); i++) cout << i << ":" << v[i] << endl;
    }
};

int main(){
  int N, M, tmpa, tmpb;
  cin >> N >> M;
  UnionFindTree ut(N);

  for (int i=0; i<M; i++) {
    cin >> tmpa >> tmpb;
    ut.unite(tmpa-1, tmpb-1);
  }

  cout << ut.types()-1 << endl;
}
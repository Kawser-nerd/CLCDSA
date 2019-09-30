#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define ll long long
#define INF 1000000000000000000

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <ios>
#include <iomanip>

using namespace std;

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }

  bool unionSet(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y];
      data[y] = x;
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
    ll N,M;
    cin >> N >> M;
    ll ans[M];
    vector<pair<ll,ll>> bridge(M);
    UnionFind u = UnionFind(N);

    REP(i, M){
        cin >> bridge[i].first >> bridge[i].second;
        ans[i] = 0;
    }

    ans[M-1] = N*(N-1)/2;
    for(int i=M-2 ; i>=0 ; i--){
        if(u.findSet(bridge[i+1].first-1, bridge[i+1].second-1)){
            ans[i] = ans[i+1];
        }else{
            ans[i] = ans[i+1]-u.size(bridge[i+1].first-1)*u.size(bridge[i+1].second-1);
        }
        u.unionSet(bridge[i+1].first-1, bridge[i+1].second-1);
    }

    REP(i, M){
        cout << ans[i] << endl;
    }

    return 0;
}
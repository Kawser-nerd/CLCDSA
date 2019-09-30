#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <cstring>
#include <iomanip>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;
#define inf 280201280201280201
#define mn 2005
#define FLN "test"
#define int long long
#define MOD 1000000007
typedef pair<int, int> ii;
//constance

//common data structures and templates
struct dsu{
  vector<int> p, rank;
  void init(int n){
    p.assign(n, -1);
    for(int i=0; i< n; ++i) p[i] = i;
    rank.assign(n, 1);
  }
  int root(int i){
    return p[i] == i ? i : p[i] = root(p[i]);
  }
  bool isSameSet(int i, int j){
    return root(i)== root(j);
  }
  void unify(int i, int j){
    if(!isSameSet(i, j)){
      int x = root(i), y = root(j);
      if(rank[x] > rank[y]){
        p[y] = x;
        rank[x] += rank[y];
      }    
      else{
        p[x] = y;
        rank[y] += rank[x];
      }
    }
  }
};
//gb
int n, m, X;
dsu uf;
pair<int, ii> e[mn];
int check[mn], PW[mn];
vector<vector<ii> > mst;
int s;
//functions here
void input(){
  cin >> n >> m >> X; 
  mst.assign(n, vector<ii>());
  for(int i=0; i< m; ++i){
    int x,y, w; cin >> x >> y >> w;
    e[i] = {w, {--x, --y}};
  }
}
int dfs(int v, int p, int des){
  int ret = -1;
  for(ii u : mst[v]){
    if(u.first!= p){
      if(u.first== des) return u.second;
      else{
        int w = dfs(u.first, v, des);
        if(w > 0) ret = max(u.second, w); 
      }
    }
  }
  return ret;
}
void prep(){
  PW[0] = 1;
  for(int i=1; i< mn; ++i) PW[i] = (PW[i-1]*2)%MOD;
}
void solve(){
  prep();
  s= 0;
  uf.init(n);
  sort(e, e+m);
  memset(check, 0, sizeof check);
  for(int i=0; i< m; ++i){
    if(!uf.isSameSet(e[i].second.first, e[i].second.second)){
      check[i] = 1;
      uf.unify(e[i].second.first, e[i].second.second);
      s += e[i].first;
      mst[e[i].second.first].push_back({e[i].second.second, e[i].first});
      mst[e[i].second.second].push_back({e[i].second.first, e[i].first});
    }
  }
  int cnt = 0, cntt= 0, cnttt = 0;
  for(int i=0; i< m; ++i){
    if(check[i] == 0){
      int w = dfs(e[i].second.second,-1, e[i].second.first);
      if(s-w + e[i].first > X) check[i] = -1;
      if(s-w + e[i].first < X) check[i] = 1;
    }
    else if(check[i]== 1){
      if(s==X) check[i] = 0;
      if(s > X) check[i] = -1;
    }
    if(check[i] == 0) ++cnt;
    if(check[i] == 1) ++cntt;
    if(check[i] == -1) ++cnttt;
    cerr << e[i].second.first+1 << " " << e[i].second.second+1 << " "<< check[i] << "\n";
  }
  cnt += (cntt >0);
  if(cnttt == m){
    cout << 0;
    return;
  }
  cout << ((PW[cnt]+ MOD-2)%MOD*PW[cnttt])%MOD;
}

//#define LOCAL 1

signed main(signed argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifdef LOCAL
	   freopen(FLN".inp", "r", stdin);
	   freopen(FLN".out", "w", stdout);
#endif
  input();
  solve();
	return 0;
}
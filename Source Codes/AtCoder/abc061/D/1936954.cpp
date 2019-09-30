#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
#include <climits>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define RFOR(i,a,b) for (int i=(a)-1;i>=(b);i--)
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int INF = 1e9;
const ll LL_INF = 1e18;
const int MOD = 1e9 + 7;

using namespace std;

struct Edge{
  int from, to, cost;
};


const int MAXV = 1002;
const int MAXE = 2002;
Edge edges[MAXE];
bool is_pass[MAXV];
ll d[MAXV];
int V, E;

bool berm(){
  fill(d, d + V, -LL_INF);
  d[0] = 0;
  is_pass[0] = true;
  for(int ct=0;ct<V - 1;ct++){
    for(int i=0;i<E;i++){
      int v = edges[i].to;
      int u = edges[i].from;
      int c = edges[i].cost;
      if(!is_pass[u]) continue;
      is_pass[v] |= is_pass[u];
      if(d[u] + c > d[v]){
        d[v] = d[u] + c;
      }
    }
  }
  ll pv = d[V-1];
  for(int ct=0;ct<V - 1;ct++){
    for(int i=0;i<E;i++){
      int v = edges[i].to;
      int u = edges[i].from;
      int c = edges[i].cost;
      if(!is_pass[u]) continue;
      is_pass[v] |= is_pass[u];
      if(d[u] + c > d[v]){
        d[v] = d[u] + c;
        /*        if(ct == V-1&&is_pass[u]){
          return false;
          }*/
      }
    }
  }
  if(pv != d[V - 1]) return false;
  return true;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> V >> E;
  REP(i,E){
    int u, v, c;
    cin >> u >> v >> c;
    --u;
    --v;
    edges[i] = {u, v, c};
  }
  if(not berm()){
    cout << "inf" << endl;
  }else{
    cout << d[V-1] << endl;
  }
  return 0;
}
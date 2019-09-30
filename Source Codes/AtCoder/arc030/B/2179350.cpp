#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#define INF_INT (INT_MAX / 2)
#define INF_LONG (LONG_MAX / 2)
//#define DEBUG true
#define DEBUG false
#define MAX_N 100
using namespace std;

vector< int > graph[MAX_N];
int h[MAX_N];

int dfs(int v, int p){
  int sum = 0;
  for(int w: graph[v]){
    if(w != p){
      int t = dfs(w, v);
      if(t > 0 || h[w]) sum += t + 2;
    }
  }
  return sum;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, x;
  cin >> n >> x;
  for(int i = 0; i < n; i++){
    cin >> h[i];
  }
  for(int i = 0; i < n - 1; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  int ans = dfs(x - 1, -1);

  cout << ans << endl;

  return 0;
}
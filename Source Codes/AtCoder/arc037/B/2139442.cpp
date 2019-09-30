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

void dfs(int v, vector< int >& compo, bool visited[]){
  if(visited[v]) return;
  visited[v] = true;
  compo.push_back(v);
  for(int w: graph[v]){
    dfs(w, compo, visited);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    graph[u - 1].push_back(v - 1);
    graph[v - 1].push_back(u - 1);
  }

  bool visited[n];
  fill(visited, visited + n, false);
  int count = 0;
  for(int s = 0; s < n; s++){
    if(!visited[s]){
      vector< int > compo;
      dfs(s, compo, visited);
      int sum = 0;
      for(int w: compo){
        sum += graph[w].size();
      }
      if(sum / 2 == compo.size() - 1) ++count;
    }
  }

  cout << count << endl;

  return 0;
}
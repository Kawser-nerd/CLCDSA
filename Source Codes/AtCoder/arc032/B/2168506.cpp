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
#define MAX_N 100000
using namespace std;

vector< int > graph[MAX_N];

void dfs(int v, bool visited[]){
  if(visited[v]) return;
  visited[v] = true;
  for(int w: graph[v]){
    dfs(w, visited);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    --a; --b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  bool visited[n];
  fill(visited, visited + n, false);
  int count = 0;
  for(int s = 0; s < n; s++){
    if(!visited[s]){
      dfs(s, visited);
      ++count;
    }
  }

  cout << (count - 1) << endl;

  return 0;
}
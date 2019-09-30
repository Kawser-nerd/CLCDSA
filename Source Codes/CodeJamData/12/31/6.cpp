#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

int T,N;

vector<int> adj[1001];
bool v[1001];

bool has_cycle(int node) {
  stack<int> s;
  memset(v, 0, sizeof v);
  s.push(node);
  v[node] = true;
  while (!s.empty()) {
    int node = s.top();
    s.pop();
    
    for (int i=0; i<adj[node].size(); i++) {
      int neigh = adj[node][i];
      if (v[neigh])
	return true;
      v[neigh] = true;
      s.push(neigh);
    }
  }
  return false;
}

int main() {
  scanf("%d", &T);
  for (int ttt=1; ttt<=T; ttt++) {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
      int m;
      scanf("%d", &m);
      adj[i].resize(m);
      for (int j=0; j<m; j++){
	int tmp;
	scanf("%d", &tmp);
	adj[i][j] = tmp - 1;
      }
    }
    
    int c = false;
    for (int i=0; i<N; i++)
      c |= has_cycle(i);
    
    printf("Case #%d: ", ttt);
    if (c)
      printf("Yes\n");
    else
      printf("No\n");
  }
}
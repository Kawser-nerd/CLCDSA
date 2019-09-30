/* GCJ'08
 * Author: Per Austrin
 */
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
#define dprintf debug && printf
bool debug = false;

void init() {
}

typedef int Flow;

struct flow_edge {
  int dest, back;// back is index of back-edge in graph[dest]
  Flow c, f; // capacity and flow
  Flow r() { return c - f; } // used by ford fulkerson
  flow_edge() {}
  flow_edge(int _dest, int _back, Flow _c, Flow _f = 0)
    : dest(_dest), back(_back), c(_c), f(_f) { }
};

typedef vector<flow_edge> adj_list;
typedef adj_list::iterator adj_iter;

void flow_add_edge(adj_list *g, int s, int t, // add s -> t
		   Flow c, Flow back_c = 0) {
  g[s].push_back(flow_edge(t, g[t].size(), c));
  g[t].push_back(flow_edge(s, g[s].size() - 1, back_c));
}

#define MAXNODES 6000

int mark[MAXNODES];

Flow inc_flow_dfs(adj_list *g, int s, int t, Flow maxf) {
  if (s == t) return maxf;
  Flow inc;   mark[s] = 0;
  for (adj_iter it = g[s].begin(); it != g[s].end(); ++it)
    if (mark[it->dest] && it->r() && 
	(inc=inc_flow_dfs(g,it->dest,t,min(maxf, it->r()))))
      return it->f+=inc, g[it->dest][it->back].f -= inc, inc;
  return 0;
}

Flow max_flow(adj_list *graph, int n, int s, int t) {
  Flow flow = 0, inc = 0;
  do flow += inc, memset(mark, 255, sizeof(int)*n);
  while ((inc = inc_flow_dfs(graph, s, t, 1<<28)));
  return flow;
}

const int di[] = {-1, 0, -1, 0};
const int dj[] = {-1, -1, 1, 1};


void solve(int P) {
  int M, N, tot = 0;
  char broken[100][100];
  scanf("%d%d", &M, &N);
  
  for (int i = 0; i < M; ++i) {
    scanf("%s", broken[i]);
    for (int j = 0; j < N; ++j)
      tot += broken[i][j] == '.';
  }

  int s = M*N, t = s+1;
  
  adj_list G[100*100];

  for (int i = 0; i < M; ++i) {
    for (int j = 1; j < N; j += 2)
      if (broken[i][j] == '.') flow_add_edge(G, i*N+j, t, 1);
    for (int j = 0; j < N; j += 2) {
      if (broken[i][j] == '.')
	flow_add_edge(G, s, i*N+j, 1);
    }
    for (int j = 0; j < N; ++j) {
      for (int d = 0; d < 4; ++d) {
	int ni = i + di[d], nj = j + dj[d];
	if (ni >= 0 && ni < M && nj >= 0 && nj < N && broken[ni][nj] == '.') {
	  if (j % 2 == 0)
	    flow_add_edge(G, i*N+j, ni*N+nj, 1);	
	  else
	    flow_add_edge(G, ni*N+nj, i*N+j, 1);
	}
      }
    }
  }
  printf("Case #%d: %d\n", P, tot-max_flow(G, t+1, s, t));
}

int main() {
  int n;
  scanf("%d", &n);
  init();
  for (int i = 1; i <= n; ++i) solve(i);
  return 0;
}

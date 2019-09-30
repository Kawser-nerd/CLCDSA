#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef struct directed_edge {
  int32_t vertex;
  int32_t next;
} graph_edge;

typedef struct directedGraph {
  graph_edge *edge;
  int32_t *start;
  int32_t pointer;
  int32_t vertex_num;
  int32_t max_size;
} graph;

graph* newGraph (const int vertex_num) {
  graph *g = (graph *) calloc (1, sizeof (graph));
  g->edge = (graph_edge *) calloc (1, sizeof (graph_edge));
  g->start = (int32_t *) calloc (vertex_num, sizeof (int32_t));
  g->pointer = 0;
  g->vertex_num = vertex_num;
  g->max_size = 1;
  for (int32_t i = 0; i < vertex_num; ++i) {
    g->start[i] = -1;
  }
  return g;
}

void addEdge (graph *g, int32_t from, int32_t to) {
  if (g->pointer == g->max_size) {
    g->max_size *= 2;
    g->edge = (graph_edge *) realloc (g->edge, sizeof (graph_edge) * g->max_size);
  }
  g->edge[g->pointer] = (graph_edge) {to, g->start[from]};
  g->start[from] = g->pointer++;
}

typedef int32_t i32;

void dfs (i32 v, uint8_t *used, graph *g) {
  for (i32 p = g->start[v]; p != -1; p= g->edge[p].next) {
    i32 u = g->edge[p].vertex;
    if (used[u]) continue;
    used[u] = 1;
    dfs (u, used, g);
  }
}

void run (void) {
  i32 n, m;
  scanf ("%" SCNi32 "%" SCNi32, &n, &m);
  i32 *cnt = (i32 *) calloc (n, sizeof (i32));
  graph *g = newGraph (n);
  for (i32 i = 0; i < m; ++i) {
    i32 a, b;
    scanf ("%" SCNi32 "%" SCNi32, &a, &b);
    a--;b--;
    addEdge (g, a, b);
    addEdge (g, b, a);
    cnt[a]++;
    cnt[b]++;
  }
  for (i32 i = 0; i < n; ++i) {
    if (cnt[i] & 1) {
      puts ("No");
      return;
    }
  }
  i32 d = 0;
  for (i32 i = 0; i < n; ++i) {
    if (cnt[i] >= 6) {
      puts ("Yes");
      return;
    }
    if (cnt[i] == 4) {
      d++;
    }
  }
  if (d != 2) {
    puts(d >= 3 ? "Yes" : "No");
    return;
  }
  i32 k;
  for (k = 0; cnt[k] != 4; ++k);
  uint8_t *used = (uint8_t *) calloc (m, sizeof (uint8_t));
  used[k] = 1;
  dfs (k == 0 ? 1 : 0, used, g);
  for (k = 0; k < n && used[k]; ++k);
  puts (k < n ? "Yes" : "No");
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:54:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32 "%" SCNi32, &n, &m);
   ^
./Main.c:59:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi32 "%" SCNi32, &a, &b);
     ^
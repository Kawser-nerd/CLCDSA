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
  int32_t edge_max_size;
} graph;

graph* new_graph (const int vertex_num) {
  graph *g = (graph *) calloc (1, sizeof (graph));
  g->edge = (graph_edge *) calloc (1, sizeof (graph_edge));
  g->start = (int32_t *) calloc (vertex_num, sizeof (int32_t));
  g->pointer = 0;
  g->vertex_num = vertex_num;
  g->edge_max_size = 1;
  for (int32_t i = 0; i < vertex_num; ++i) {
    g->start[i] = -1;
  }
  return g;
}

void add_edge (graph *g, int32_t from, int32_t to) {
  if (g->pointer == g->edge_max_size) {
    g->edge_max_size *= 2;
    g->edge = (graph_edge *) realloc (g->edge, sizeof (graph_edge) * g->edge_max_size);
  }
  g->edge[g->pointer] = (graph_edge) {to, g->start[from]};
  g->start[from] = g->pointer++;
}

typedef int32_t i32;

void run (void) {
  i32 n, m;
  scanf ("%" SCNi32 "%" SCNi32, &n, &m);
  char *s = (char *) calloc (n + 1, sizeof (char));
  scanf ("%s", s);
  graph *g = new_graph (n);
  while (m--) {
    i32 a, b;
    scanf ("%" SCNi32 "%" SCNi32, &a, &b);
    a--;
    b--;
    add_edge (g, a, b);
    add_edge (g, b, a);
  }
  i32 *cnt = (i32 *) calloc (2 * n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    i32 d = s[i] == 'A' ? 0 : n;
    for (i32 p = g->start[i]; p != -1; p = g->edge[p].next) {
      i32 u = g->edge[p].vertex;
      cnt[u + d]++;
    }
  }
  i32 *q = (i32 *) calloc (n, sizeof (i32));
  uint8_t *used = (uint8_t *) calloc (n, sizeof (uint8_t));
  i32 front = 0;
  i32 last = 0;
  for (i32 i = 0; i < n; ++i) {
    if (cnt[i] == 0 || cnt[i + n] == 0) {
      q[last++] = i;
      used[i] = 1;
    }
  }
  while (front < last) {
    const i32 v = q[front++];
    const i32 d = s[v] == 'A' ? 0 : n;
    for (i32 p = g->start[v]; p != -1; p = g->edge[p].next) {
      i32 u = g->edge[p].vertex;
      cnt[u + d]--;
      if (!used[u] && cnt[u + d] == 0) {
	q[last++] = u;
	used[u] = 1;
      }
    }
  }
  puts (last < n ? "Yes" : "No");
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:45:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32 "%" SCNi32, &n, &m);
   ^
./Main.c:47:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%s", s);
   ^
./Main.c:51:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi32 "%" SCNi32, &a, &b);
     ^
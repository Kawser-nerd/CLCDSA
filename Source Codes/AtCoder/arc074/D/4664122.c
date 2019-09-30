#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

typedef int32_t flow_type;

const flow_type flow_inf = 200;

typedef struct flow_edge {
  int32_t vertex;
  int32_t next;
  flow_type capacity;
} flow_edge;

typedef struct maxFlowGraph {
  flow_edge *edge;
  int32_t *start;
  int32_t vertex_num;
  int32_t pointer;
  int32_t edge_length;
} graph;

graph* new_graph (const int32_t vertex_num) {
  graph *g = (graph *) calloc (1, sizeof (graph));
  g->vertex_num = vertex_num;
  const int32_t initial_length = 4;
  g->edge = (flow_edge *) calloc (initial_length, sizeof (flow_edge));
  g->start = (int32_t *) calloc (vertex_num, sizeof (int32_t));
  g->pointer = 0;
  g->edge_length = initial_length;
  for (int32_t i = 0; i < vertex_num; ++i) {
    g->start[i] = -1;
  }
  return g;
}

void free_graph (graph * const g) {
  free (g->edge);
  free (g->start);
  free (g);
}

void add_edge (graph * const g, const int32_t from, const int32_t to, const flow_type capa) {
  if (g->pointer == g->edge_length) {
    g->edge_length *= 2;
    g->edge = (flow_edge *) realloc (g->edge, sizeof (flow_edge) * g->edge_length);
  }
  const int32_t p = g->pointer;
  g->edge[p] = (flow_edge) {to, g->start[from], capa};
  g->start[from] = p;
  g->edge[p + 1] = (flow_edge) {from, g->start[to], 0};
  g->start[to] = p + 1;
  g->pointer += 2;
}

flow_type dinic_dfs (const int32_t v, graph * const g, const int32_t dst, const int32_t * const level, int32_t * const iter, flow_type e) {
  if (v == dst) return e;
  flow_type sum = 0;
  for (int32_t p = iter[v]; p != -1; p = g->edge[p].next, iter[v] = p) {
    const int32_t u = g->edge[p].vertex;
    const flow_type capa = g->edge[p].capacity;
    if (level[u] <= level[v] || capa <= 0) continue;
    const flow_type f = dinic_dfs (u, g, dst, level, iter, capa < e ? capa : e);
    if (f > 0) {
      g->edge[p].capacity -= f;
      g->edge[p ^ 1].capacity += f;
      sum += f;
      e -= f;
      if (e <= 0) return sum;
    }
  }
  return sum;
}

flow_type dinic (graph * const g, const int32_t src, const int32_t dst) {
  const int32_t vertex_num = g->vertex_num;
  int32_t * const level = (int32_t *) calloc (vertex_num, sizeof (int32_t));
  int32_t * const queue = (int32_t *) calloc (vertex_num, sizeof (int32_t));
  int32_t * const iter  = (int32_t *) calloc (vertex_num, sizeof (int32_t));
  flow_type flow = 0;
  while (1) {
    memset (level, 0, sizeof (int32_t) * vertex_num);
    level[dst] = vertex_num;
    int32_t front = 0;
    int32_t last = 0;
    queue[last++] = dst;
    while (front < last && level[src] == 0) {
      const int32_t v = queue[front++];
      for (int32_t p = g->start[v]; p != -1; p = g->edge[p].next) {
	const int32_t u = g->edge[p].vertex;
	if (g->edge[p^1].capacity > 0 && level[u] == 0) {
	  level[u] = level[v] - 1;
	  queue[last++] = u;
	}
      }
    }
    if (level[src] == 0) break;
    memcpy (iter, g->start, sizeof (int32_t) * vertex_num);
    while (1) {
      flow_type f = dinic_dfs (src, g, dst, level, iter, flow_inf);
      if (f <= 0) break;
      flow += f;
    }
  }
  free (level);
  free (queue);
  free (iter);
  return flow;
}

typedef int32_t i32;

void run (void) {
  i32 h, w;
  scanf ("%" SCNi32 "%" SCNi32, &h, &w);
  char *a = (char *) calloc (h * w + 1, sizeof (char));
  for (i32 i = 0; i < h; ++i) {
    scanf ("%s", a + i * w);
  }
  graph *g = new_graph (2 * h * w);
  i32 src = -1;
  i32 dst = -1;
  for (i32 i = 0; i < h; ++i) {
    for (i32 j = 0; j < w; ++j) {
      if (a[i * w + j] == '.') continue;
      if (a[i * w + j] == 'S') {
        src = i * w + j;
	add_edge (g, h * w + i * w + j, i * w + j, flow_inf);
      } else if (a[i * w + j] == 'T') {
        dst = i * w + j;
	add_edge (g, h * w + i * w + j, i * w + j, flow_inf);
      } else {
	add_edge (g, h * w + i * w + j, i * w + j, 1);
      }
      for (i32 k = 0; k < h; ++k) {
	if (k == i || a[k * w + j] == '.') continue;
	add_edge (g, i * w + j, h * w + k * w + j, flow_inf);
      }
      for (i32 k = 0; k < w; ++k) {
	if (k == j || a[i * w + k] == '.') continue;
	add_edge (g, i * w + j, h * w + i * w + k, flow_inf);
      }
    }
  }
  i32 ans = dinic (g, src, dst);
  if (ans >= flow_inf) {
    puts("-1");
  } else {
    printf ("%" PRIi32 "\n",ans);
  }
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:117:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32 "%" SCNi32, &h, &w);
   ^
./Main.c:120:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%s", a + i * w);
     ^
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <queue>
#include <cassert>
#include <complex>
using namespace std;
#define PI 3.14159265358979323846264338327950288
int T, N, M;
int graph[405][405];
int dist[405];
int mark[405];
int ans[405][405];
int que[405];
int front, back;
int bfs(int x) {
   int i, j;
   front = 1;
   back = 0;
   que[0] = x;
   memset(mark, 0, sizeof(mark));
   mark[x] = 1;
   dist[x] = 0;
   while (front > back) {
      for (i = 0; i < N; i ++)
	 if (!mark[i] && graph[que[back]][i]) {
	    que[front ++] = i;
	    mark[i] = 1;
	    dist[i] = dist[que[back]] + 1;
	 }
      back ++;
   }
   return 0;
}
int main() {
   int i, j, k, l, Case = 1;
   scanf("%d", &T);
   while (T --) {
      scanf("%d%d", &N, &M);
      memset(graph, 0, sizeof(graph));
      for (i = 0; i < M; i ++) {
	 char tmp[25];
	 int tmp1, tmp2;
	 scanf("%s", tmp);
	 sscanf(tmp, "%d,%d", &tmp1, &tmp2);
	 graph[tmp1][tmp2] = graph[tmp2][tmp1] = 1;
      }
      bfs(0);
      printf("Case #%d: %d ", Case ++, dist[1] - 1);
      memset(ans, -1, sizeof(ans));
      for (i = 0; i < front; i ++)
	 for (j = i + 1; j < front; j ++)
	    if (dist[que[i]] + 1 == dist[que[j]] && graph[que[i]][que[j]])
	       if (dist[que[i]] == 0) {
		  if (que[j] != 1)
		     ans[que[i]][que[j]] = 0;
		  else {
		     ans[que[i]][que[j]] = 0;
		     for (l = 0; l < front; l ++)
			if (dist[que[l]] >= dist[que[i]] && graph[que[l]][que[i]] && l != i)
			   ans[que[i]][que[j]] ++;
		  }
	       }
	       else
		  for (k = 0; k < i; k ++)
		     if (dist[que[k]] + 1 == dist[que[i]] && graph[que[k]][que[i]]) {
			int tmp = ans[que[k]][que[i]];
			if (que[j] != 1) {
			   for (l = 0; l < front; l ++)
			      if (dist[que[l]] == dist[que[i]] && (graph[que[l]][que[i]] || graph[que[l]][que[j]] || graph[que[l]][que[k]]) && l != i)
				 tmp ++;
			}
			else {
			   for (l = 0; l < front; l ++)                    
			      if (dist[que[l]] >= dist[que[i]] && (graph[que[l]][que[i]] || graph[que[l]][que[k]]) && l != i)
				 tmp ++;
			}
			if (tmp > ans[que[i]][que[j]])
			   ans[que[i]][que[j]] = tmp;
		     }
      int out = -1;
      for (i = 0; i < front; i ++)
	 out = max(out, ans[que[i]][1]);
      printf("%d\n", out);
   }
   return 0;
}


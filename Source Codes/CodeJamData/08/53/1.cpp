#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
#define PI 3.14159265358979323846264338327950288
int T;
int N, M;
char mat[100][100];
int id[100][100];
int n[2];
int graph[4000][20];
int num[4000];
int o2[4000], o1[4000], mark[4000];
#define ok(a, b) ((a) >= 0 && (a) < N && (b) >= 0 && (b) < M && mat[a][b] == '.')
int add(int a, int b, int c, int d) {
   if (b % 2) {
      swap(a, c);
      swap(b, d);
   }
   if (ok(a, b) && ok(c, d))
      graph[id[a][b]][num[id[a][b]] ++] = id[c][d];
   return 0;
}
int search(int x) {
   int i;
   mark[x] = 1;
   for (i = 0; i < num[x]; i ++)
      if (o2[graph[x][i]] == -1 || !mark[o2[graph[x][i]]] && search(o2[graph[x][i]])) {
	 o2[graph[x][i]] = x;
	 return 1;
      }
   return 0;
}
int main() {
   int i, j, Case = 1;
   scanf("%d", &T);
   while (T --) {
      scanf("%d%d", &N, &M);
      for (i = 0; i < N; i ++)
	 scanf("%s", mat[i]);
      n[0] = n[1] = 0;
      for (i = 0; i < N; i ++)
	 for (j = 0; j < M; j ++)
	    if (ok(i, j))
	       id[i][j] = n[j % 2] ++;
      memset(num, 0, sizeof(num));
      for (i = 0; i < N; i ++)
	 for (j = 0; j < M; j ++) {
	    add(i, j, i - 1, j - 1);
	    add(i, j, i - 1, j + 1);
	    add(i, j, i, j - 1);
	    add(i, j, i, j + 1);
	 }
      int ret = n[0] + n[1];
      memset(o1, -1, sizeof(o1));
      memset(o2, -1, sizeof(o2));
      for (i = 0; i < n[0]; i ++)
	 for (j = 0; j < num[i]; j ++)
	    if (o2[graph[i][j]] == -1) {
	       ret --;
	       o1[i] = graph[i][j];
	       o2[graph[i][j]] = i;
	       break;
	    }
      for (i = 0; i < n[0]; i ++)
	 if (o1[i] == -1) {
	    memset(mark, 0, sizeof(mark));
	    if (search(i))
	       ret --;
	 }
      printf("Case #%d: %d\n", Case ++, ret);
   }
   return 0;
}


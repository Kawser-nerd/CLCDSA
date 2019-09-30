#include <stdio.h>
#define NMAX 100000
#define MMAX 200000

int main(void)
{
  int i, j, l, n, m, d, ind = 0;
  int next[NMAX], parent[NMAX], offset[NMAX], depth[NMAX], permu[NMAX], comb[NMAX], a[MMAX];
  scanf("%d %d %d", &n, &m, &d);
  for (i = 0; i < n; i++) {
    next[i] = i;
    parent[i] = depth[i] = -1;
  }
  for (i = 0; i < m; i++) scanf("%d", &a[i]);
  for (i = m - 1; i >= 0; i--) {
    int temp = next[a[i]-1];
    next[a[i]-1] = next[a[i]];
    next[a[i]] = temp;
  }
  for (i = 0; i < n; i++) {
    l = 0;
    comb[i] = ind;
    for (l = 0, j = i; parent[j] == -1; l++, j = next[j]) {
      parent[j] = i;
      offset[j] = l;
      permu[comb[i]+l] = j;
    }
    ind += l;
    depth[i] = l;
    printf("%d\n", permu[comb[parent[i]]+(d+offset[i])%depth[parent[i]]] + 1);
  }
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &n, &m, &d);
   ^
./Main.c:14:27: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for (i = 0; i < m; i++) scanf("%d", &a[i]);
                           ^
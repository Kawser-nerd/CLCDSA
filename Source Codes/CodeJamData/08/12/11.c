#include <stdio.h>
#include <string.h>

#define MAXN 2123
#define MAXM 2123

int cust[MAXM][MAXN][4], marked[MAXM];

int main() {
  int t, cases = 1;
  int n, m;
  int i, j, k;

  int res, resnmal;

  scanf("%d", &t);
  while (t--) {
    memset(cust, 0, sizeof(cust));
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++) {
      scanf("%d", &k);
      for (j = 0; j < k; j++) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--;
	cust[i][x][y] = 1;
      }
    }

    resnmal = MAXN;
    for (i = 0; i < 1<<n; i++) {
      int nmal = 0, sat = 0;
      memset(marked, 0, sizeof(marked));
      for (j = 0; j < n; j++) {
	int ism = (i&(1<<j)) ? 1 : 0;
	nmal += ism;
	for (k = 0; k < m; k++)
	  if (cust[k][j][ism] && !marked[k]) {
	    marked[k] = 1;
	    sat++;
	  }
      }
      if (sat == m && nmal <= resnmal) {
	res = i;
	resnmal = nmal;
      }
    }
    if (resnmal == MAXN)
      printf("Case #%d: IMPOSSIBLE\n", cases++);
    else {
      printf("Case #%d:", cases++);
      for (j = 0; j < n; j++)
	printf(" %d", (res&(1<<j)) ? 1 : 0);
      printf("\n");
    }
  }
  
  return 0;
}

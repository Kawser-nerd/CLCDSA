#include <stdio.h>

#define MAXLEN 100
#define MAXN 11

int n, m, t[MAXLEN], x[MAXLEN][MAXN], y[MAXLEN][MAXN];
int batch[MAXN], minb[MAXN], cnt1 = 0, min;

void try(int depth)
{
     if (depth > n) {
	  int i, j, s = 0;
	  for (i = 0; i < m; i++)
	       for (j = 0; j < t[i]; j++)
		    if (batch[x[i][j]] == y[i][j]) {
			 s++;
			 break;
		    }
	  if ((s == m) && (cnt1 < min)) {
	       min = cnt1;
	       for (i = 1; i <= n; i++)
		    minb[i] = batch[i];
	  }
     } else {
	  batch[depth] = 0;
	  try(depth+1);
	  batch[depth] = 1;
	  cnt1++;
	  try(depth+1);
	  cnt1--;
     }
}

int main()
{
     int c, i;
     scanf("%d", &c);
     for (i = 1; i <= c; i++) {
	  scanf("%d%d", &n, &m);
	  int j, k;
	  for (j = 0; j < m; j++) {
	       scanf("%d", &t[j]);
	       for (k = 0; k < t[j]; k++)
		    scanf("%d %d", &x[j][k], &y[j][k]);
	       }
	  min = 101;
	  try(1);
	  if (min == 101)
	       printf("Case #%d: IMPOSSIBLE\n", i);
	  else {
	       printf("Case #%d:", i);
	       for (k = 1; k <= n; k++)
		    printf(" %d", minb[k]);
	       printf("\n");
	  }
     }
     
     return 0;
}

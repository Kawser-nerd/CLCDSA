#include <stdio.h>

#define MAX 2002

int n, np;
int pnum[MAX];
int p1[MAX][MAX];
int p2[MAX][MAX];
int total[MAX];
int sol[MAX], best_sol[MAX], best_malt;

void verify(int count) {
  int i, j;

  for (i=0; i<np; i++) {
    for (j=0; j<pnum[i]; j++)
      if (sol[p1[i][j]] == p2[i][j]) break;
    if (j==pnum[i]) break;
  }
  if (i<np) return;

  if (count<best_malt) {
    best_malt = count;
    for (i=0; i<n; i++) best_sol[i] = sol[i];
  }
}

void go(int pos, int count) {
  if (pos==n)  verify(count);
  else {
    sol[pos]=0; go(pos+1, count);
    sol[pos]=1; go(pos+1, count+1);
  }
}

int main() {
  int i, j, k, ncases;

  scanf("%d",&ncases);
  for (i=1; i<=ncases; i++) {
    scanf("%d",&n);
    scanf("%d",&np);
    for (j=0; j<np; j++) {
      scanf("%d",&pnum[j]);
      for (k=0; k<pnum[j]; k++) {
	scanf("%d %d",&p1[j][k], &p2[j][k]);
	p1[j][k]--;
      }
    }

    best_malt = n+1;
    go(0, 0);

    printf("Case #%d:",i);

    if (best_malt>n) printf(" IMPOSSIBLE\n");
    else {
      for (j=0; j<n; j++) printf(" %d",best_sol[j]);
      putchar('\n');
    }    
  }

  return 0;
}

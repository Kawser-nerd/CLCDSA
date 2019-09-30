// Just trying to guarantee 35 points. Now I'll sleep :)

#include <stdio.h>
#include <string.h>

#define MAX 205
#define POS 1050000

typedef struct {
  int t, nk, k[MAX], open;
} Chest;

int n, nk, k[MAX], sol[MAX], can, cur;
Chest c[MAX];
char p[POS];

void try(int pos) {
  int i, j;

  if (can || p[cur]) return;

  /*printf("[%d] try:", cur);
  for (i=0; i<pos; i++)
    printf(" %d", sol[i]);
    putchar('\n');*/

  p[cur]=1;


  if (pos==n) {
    for (i=0; i<n; i++) printf(" %d", sol[i]);
    putchar('\n');
    can = 1;
  } else {
    for (i=0; i<n; i++)
      if (!c[i].open && k[c[i].t]>0) {
	c[i].open = 1;
	k[c[i].t]--;
	for (j=0; j<c[i].nk; j++) k[c[i].k[j]]++;
	sol[pos]=i+1;
	cur |= (1<<i);
	try(pos+1);
	cur &= ~(1<<i);
	for (j=0; j<c[i].nk; j++) k[c[i].k[j]]--;
	k[c[i].t]++;
	c[i].open = 0;
      }
  }
}

int main() {
  int t, cc, i, j, aux;

  scanf("%d", &t);
  for (cc=1; cc<=t; cc++) {
    scanf("%d %d", &nk, &n);
    memset(k, 0, sizeof(k));
    for (i=0; i<nk; i++) {
      scanf("%d", &aux);
      k[aux]++;
    }
    for (i=0; i<n; i++) {
      scanf("%d %d", &c[i].t, &c[i].nk);
      //printf("!!%d %d\n", c[i].t, c[i].nk);
      for (j=0; j<c[i].nk; j++) scanf("%d", &c[i].k[j]);
      c[i].open = 0;
    }

    printf("Case #%d:", cc);

    memset(p, 0, sizeof(p));
    can = cur = 0;
    try(0);
    if (!can) puts(" IMPOSSIBLE");

  }

  return 0;
}
 

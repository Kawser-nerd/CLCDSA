#include <stdio.h>

#define MAX 15

int n, bff[MAX], perm[MAX], used[MAX], ok;

void go(int pos, int max) {
  int i;
  if (pos>2 && perm[pos-3] != bff[perm[pos-2]] && perm[pos-1] != bff[perm[pos-2]])
    return;
  if (ok) return;
  if (pos==max) {
    for (i=0; i<max; i++)
      if (perm[(i-1+max)%max] != bff[perm[i]] && perm[(i+1)%max] != bff[perm[i]])
	return;
    ok=1;
  } else {
    for (i=1; i<=n; i++)
      if (!used[i]) {
	perm[pos] = i;
	used[i] = 1;
	go(pos+1, max);
	used[i] = 0;
      }
  }
}

int main() {
  int t, i, j, k;

  scanf("%d", &t);
  for (i=1; i<=t; i++) {
    scanf("%d", &n);
    for (j=1; j<=n; j++) scanf("%d", &bff[j]);
    
    for (k=n, ok=0; k>0; k--) {
      go(0, k);
      if (ok) break;
    }

    printf("Case #%d: %d\n", i, k);
  }
  
  return 0;
}

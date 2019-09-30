// Brute force for small case

#include <stdio.h>

#define MAX 10005

int e, r, n, v[MAX], mymax;

void go(int pos, int gain, int cur) {
  int i;
  if (pos==n) {
    if (gain>mymax) mymax=gain;
  } else {
    if (cur>e) cur=e;
    for (i=0; i<=cur; i++)
      go(pos+1, gain+v[pos]*i, cur-i+r);
  }
}

int main() {
  int i, c, ncases;

  scanf("%d", &ncases);
  for (c=1; c<=ncases; c++) {
    scanf("%d %d %d", &e, &r, &n);
    for (i=0; i<n; i++) scanf("%d", &v[i]);
    mymax = 0;
    go(0, 0, e);
    printf("Case #%d: %d\n", c, mymax);
  }


  return 0;
}

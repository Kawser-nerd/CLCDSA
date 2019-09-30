
#include <stdio.h>
#include <math.h>

#define imax(a,b) (((a)>(b))?(a):(b))

int main() {
  int T = 0;
  int C;
  int n;
  int x[2];
  int t[2];
  int p[1000];
  char c[1000];
  int i;
  int diff;

  scanf("%d", &T);
  for(C=1;C<=T;C++) {
    scanf("%d", &n);
    x[0] = x[1] = 1;
    t[0] = t[1] = 0;
    for(i=0;i<n;i++) {
      while(1) {
        scanf("%c", &c[i]);
        if(c[i] == 'O' || c[i] == 'B') break;
      }
      if(c[i] == 'O') c[i] = 0;
      if(c[i] == 'B') c[i] = 1;
      scanf("%d", &p[i]);
    }

    for(i=0;i<n;i++) {
      diff = abs(x[c[i]] - p[i]);
      x[c[i]] = p[i];
      t[c[i]] += diff;
      if(t[c[i]] < t[c[i]^1]) t[c[i]] = t[c[i]^1];
      t[c[i]]++;
    }

    printf("Case #%d: %d\n", C, imax(t[0],t[1]));
  }

  return 0;
}

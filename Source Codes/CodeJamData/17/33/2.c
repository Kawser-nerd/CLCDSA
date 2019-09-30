#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void) {
  int T;
  scanf("%i", &T);
  
  for (int t = 1; t <= T; t++) {
    int n, k;
    scanf("%i %i", &n, &k);
    
    double u;
    scanf("%lf", &u);
    
    double p[n+1];
    for (int i = 0; i < n; i++) {
      scanf("%lf", &p[i]);
    }
    
    double lo = 0.0, hi = 1.0, best = -1.0;
    
    int count = 500;
    while (count--) {
      double min = (lo + hi) / 2.0;      
      double tmp = u;
      
      int can = 1;
      for (int i = 0; i < n; i++) {
        if (p[i] < min) {
          double req = min - p[i];
          if (req > tmp) {
            can = 0;
          } else {
            tmp -= req;
          }
        }
      }
      
      if (can) {
        best = min;
        lo = min;
      } else {
        hi = min;
      }      
    }
        
    double ans = 1.0;
    for (int i = 0; i < n; i++) {
      ans *= MAX(p[i], best);
    }
    
    printf("Case #%i: %.8f\n", t, ans);
  }
  
  return 0;
}
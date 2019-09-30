#include <stdio.h>

int main(void) {
  int n, l, r;
  scanf("%i %i %i", &n, &l, &r);
  
  unsigned long long a[n];
  for (int i = 0; i < n; i++) {
    scanf("%llu", &a[i]);
  }
  
  for (int i = 0; i < n ; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (a[min_idx] > a[j]) {
        min_idx = j;
      }
    }
    
    unsigned long long tmp = a[i];
    a[i] = a[min_idx];
    a[min_idx] = tmp;
  }
    
  unsigned long long f[51][51];
  for (int i = 0; i <= 50; i++) {
    f[i][0] = f[i][i] = 1;
    for (int j = 1; j < i; j++) {
      f[i][j] = f[i-1][j] + f[i-1][j-1];
    }
  }
  
  unsigned long long p = 0, q = 1;
  for (int j = l; j <= r; j++) {
    unsigned long long sum = 0;
    for (int i = n-j; i < n; i++) {
      sum += a[i];
    }
    if (sum * q > p * j) {
      p = sum;
      q = j;
    }
  }
  
  unsigned long long tot = 0;
  for (int j = l; j <= r; j++) {
    unsigned long long sum = 0;
    for (int i = n-j; i < n; i++) {
      sum += a[i];
    }
    
    if (sum * q == p * j) {
      int count = 0;
      for (int i = 0; i < n; i++) {
        if (a[n-j] == a[i]) {
          count++;
        }
      }
      
      int m = 1;
      for (int i = n-j+1; i < n && a[i] == a[i-1]; i++) {
        m++;
      }
      
      tot += f[count][m];
    }
  }
  
  printf("%.7f\n%llu\n", (double)p / q, tot);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%i %i %i", &n, &l, &r);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%llu", &a[i]);
     ^
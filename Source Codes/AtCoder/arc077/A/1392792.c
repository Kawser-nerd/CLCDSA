#include<stdio.h>

int main() {
  int n;
  int i;
  int a[200010];
  int ans[200010];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  if (n % 2 == 0) {
    for (i = 0; i < (n/2); i++) {
      ans[i] = a[n - 2*i - 1];
    }
    for (i = 0; i < (n/2); i++) {
      ans[(n/2)+i] = a[2*i];
    }
  }
  if (n % 2 == 1) {
    for (i = 0; i < (n/2)+1; i++) {
      ans[i] = a[n - 2*i - 1];
    }
    for (i = 0; i < (n/2); i++) {
      ans[(n/2)+1+i] = a[2*i+1];
    }
  }
  for (i = 0; i < n; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a[i]);
     ^
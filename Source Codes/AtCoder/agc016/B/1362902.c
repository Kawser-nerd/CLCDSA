#include<stdio.h>

int main() {
  int n;
  int a[100010] = {};
  int max = 0;
  int num_unique = 0;
  int flag = 0;
  int i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (max <= a[i]) {
      max = a[i];
    }
  }

  for (i = 0; i < n; i++) {
    if (max - 1 == a[i]) {
      num_unique += 1;
    }
    if (max - 1 > a[i]) {
      flag = 1;
    }
  }
  /*
  printf("max: %d\n", max);
  printf("num_unique: %d\n", num_unique);
  */
  if (num_unique == 0) {
    if (max != n-1 && max > n/2) {
      flag = 1;
    }
  }
  if (num_unique > 0) {
    if (max <= num_unique) {
      flag = 1;
    }
    
    if (n + num_unique < max * 2) {
      flag = 1;
    }
  }
  
  if (flag == 0) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a[i]);
     ^
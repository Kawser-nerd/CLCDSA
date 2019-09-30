#include<stdio.h>
#include<stdlib.h>

int compare_int(const void *a, const void *b) {
  return *(int*)a - *(int*)b;
}

int main() {
  int n, k;
  int a[100010];
  int i;
  int flag = 1;
  scanf("%d %d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == k) {
      flag += 100;
    }
  }
  qsort(a, n, sizeof(int), compare_int);
  int min = 1000000010;
  for (i = 0; i < n-1; i++) {
    if (min >= a[i+1] - a[i] && a[i+1] != a[i]) {
      min = a[i+1] - a[i];
    }
  }
  int min_a = a[0];
  /*printf("%d\n", min_a);*/
  int max_a = a[n-1];
  /*printf("%d\n", max_a);*/
  if (max_a < k) {
    flag -= 100;
  }
  if ((k - min_a) % min == 0) {
    flag += 10;
  } else {
    flag -= 10;
  }
  if (flag > 0) {
    printf("POSSIBLE\n");
  } else {
    printf("IMPOSSIBLE\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &n, &k);
   ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a[i]);
     ^
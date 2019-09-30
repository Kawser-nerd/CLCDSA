#include <stdio.h>
int main() {
  int N;
  scanf("%d", &N);
  int L[10];
  int i,j; /* ?????? */
  for (i = 0; i < N; ++i) {
    scanf("%d",&L[i]);
  }

  int temp;
  for (i = 0; i < N ; ++i) {
    for	(j = i + 1; j < N; ++j) {
      if (L[i] < L[j]) {
        temp = L[i];
        L[i] = L[j];
        L[j] = temp;
      }
    }
  }

  int sum = 0;
  for (i = 1; i < N; ++i) {
    sum += L[i];
  }

  if (L[0] >= sum) {
    printf("No\n");
  } else {
    printf("Yes\n");
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&L[i]);
     ^
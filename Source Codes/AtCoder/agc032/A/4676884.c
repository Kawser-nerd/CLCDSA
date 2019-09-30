#include <stdio.h>

static int N;
static int B[100];

int search(int i, int *data) {
  if(i == 0) {
    return 1;
  }

  int idx = 0;
  for(int j = i - 1; j >= 0; j--) {
    if(data[j] == (j+1)) {
      idx = j+1;
      break;
    }
  }
  if(idx == 0)
    return 0;

  int newdata[100];
  int dst = 0;
  for(int k = 0; k < i; k++) {
    if(k != (idx-1))
       newdata[dst++] = data[k];
  }
  if(search(i-1, newdata) == 1) {
    printf("%d\n", idx);
    return 1;
  }
  return 0;
}

int main(void) {
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &B[i]);
  }
  if(search(N, B) == 0) {
    printf("-1\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:35:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:37:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &B[i]);
     ^
#include<stdio.h>
#include<stdlib.h>

#define MAX(A, B) (((A) > (B)) ? (A) : (B))
#define MIN(A, B) (((A) < (B)) ? (A) : (B))
#define ABS(A) (MAX(A, 0-A))

int bisearch(int* ac, int size, int a) {
  if (size == 1) {
    return 0;
  }
  int r = size % 2;
  size /= 2;
  if (*(ac + size - 1) < a) {
    return size + bisearch(ac + size, size + r, a);
  }
  else {
    return bisearch(ac, size, a);
  }
}


int main() {
  int N;
  scanf("%d", &N);
  int num = 2 * N;
  
  int* list = malloc(N * sizeof(int));
  int* temp = malloc(N * sizeof(int));
  for (int i=0; i<N; i++) {
    *(temp + i) = num;
  }
  
  int a;
  for (int i=0; i<N; i++) {
    scanf("%d", &a);
    *(temp + bisearch(temp, N, a)) = a;
  }
  
  int ans;
  for (int i=N; i>0; i--) {
    if (*(temp + i - 1) != num) {
      ans = i;
      break;
    }
  }
  
  ans = N - ans;
  printf("%d", ans);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:36:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a);
     ^
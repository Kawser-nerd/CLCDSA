#include<stdio.h>
#include<stdlib.h>

#define MAX(A, B) (((A) > (B)) ? (A) : (B))
#define MIN(A, B) (((A) < (B)) ? (A) : (B))
#define ABS(A) (MAX(A, 0-A))

int main() {
  int N;
  scanf("%d", &N);
  
  int** list = malloc(N * sizeof(int*));
  
  *(list) = malloc(2 * sizeof(int));
  scanf("%d", *(list));
  *(*(list) + 1) = 1;
  
  int temp;
  int max = 1;
  
  for (int i=1; i<N; i++) {
    *(list + i) = malloc(2 * sizeof(int));
    scanf("%d", *(list + i));
    
    temp = 0;
    for (int j=0; j<i; j++) {
      if (**(list + j) < **(list + i)) {
        temp = MAX(temp, (*(*(list + j) + 1)));
      }
    }
    *(*(list + i) + 1) = temp + 1;
    max = MAX(max, temp + 1);
  }
  
  int ans = N - max;
  printf("%d", ans);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", *(list));
   ^
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", *(list + i));
     ^
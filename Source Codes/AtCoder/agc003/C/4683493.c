#include<stdio.h>
#include<stdlib.h>

#define MAX(A, B) (((A) < (B)) ? (B) : (A))
#define ABS(A) MAX((A), (0-(A)))

int main() {
  int N;
  scanf("%d", &N);
  int** list = malloc (N * sizeof(int*));
  
  for (int i=0; i<N; i++) {
    *(list + i) = malloc(3 * sizeof(int));
    scanf("%ld", *(list + i));
    *(*(list + i) + 1) = i;
  }
  
  int cmp(const void* a, const void* b) {
    return (**(int**) a - **(int**) b);
  }
  
  qsort (list, N, sizeof(int*), cmp);
  int c=0;
  
  for (int i=0; i<N; i++) {
    c += ABS((i - *(*(list + i) + 1))) % 2;
  }
  
  c /= 2;
  printf("%d\n", c);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘int *’ [-Wformat=]
     scanf("%ld", *(list + i));
           ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld", *(list + i));
     ^
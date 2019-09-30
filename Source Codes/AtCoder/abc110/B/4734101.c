#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}


int main() {
  int N,M,X,Y;
  scanf("%d %d %d %d",&N,&M,&X,&Y);
  int x[N+1],y[M+1];
  for (int i = 0; i < N; i++) {
    scanf("%d",&x[i]);
  }
  for (int i = 0; i < M; i++) {
    scanf("%d",&y[i]);
  }
  x[N] = X;
  y[M] = Y;
  qsort(x,N+1,sizeof(int),compare_int);
  qsort(y,M+1,sizeof(int),compare_int);
  int Z = x[N]+1;
  for (;;) {
    if (Z <= X) {
      Z++;
    }
    else break;
  }
  if (Z <= y[0]) printf("No War\n");
  else printf("War\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d",&N,&M,&X,&Y);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x[i]);
     ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&y[i]);
     ^
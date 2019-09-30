#include<stdio.h>
#include<math.h>

int main(){
  int N, M, a[50], b[50], c[50], d[50], i, j, min, p;
  
  scanf("%d %d", &N, &M);
  
  for (i = 0; i < N; i++){
    scanf("%d %d", &a[i], &b[i]);
  }
  for (i = 0; i < M; i++){
    scanf("%d %d", &c[i], &d[i]);
  }
  
  for (i = 0; i < N; i++){
    min = 300000000;
    for (j = 0; j < M; j++){
      if(min > fabs(a[i] - c[j]) + fabs(b[i] - d[j])){
        min = fabs(a[i] - c[j]) + fabs(b[i] - d[j]);
        p = j + 1;
      }
    }
    printf("%d\n", p);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &M);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &a[i], &b[i]);
     ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &c[i], &d[i]);
     ^
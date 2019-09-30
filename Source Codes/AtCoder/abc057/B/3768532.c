#include <stdio.h>
#include <stdlib.h>

int main(){
  int N, M;
  int a[60] = {}, b[60] = {}, c[60] = {}, d[60] = {};

  scanf("%d%d", &N, &M);
  for(int i = 1; i <= N; i++){
    scanf("%d%d", &a[i], &b[i]);
  }
  for(int i = 1; i <= M; i++){
    scanf("%d%d", &c[i], &d[i]);
  }

  for(int i = 1; i <= N; i++){

    int min = 1000000000;
    for(int j = 1; j <= M; j++){
      int dist = abs(a[i]-c[j]) + abs(b[i]-d[j]);
      if(dist < min){
        min = dist;
      }
    }

    for(int j = 1; j <= M; j++){
      int dist = abs(a[i]-c[j]) + abs(b[i]-d[j]);
      if(dist == min){
        printf("%d\n", j);
        break;
      }
    }

  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &N, &M);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &a[i], &b[i]);
     ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &c[i], &d[i]);
     ^
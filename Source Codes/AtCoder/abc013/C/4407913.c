#include<stdio.h>

int main(){
  long N, A, B, C, D, E, i, H, cost,  min;
  float y;
  
  scanf("%ld %ld", &N, &H);
  scanf("%ld %ld %ld %ld %ld", &A, &B, &C, &D, &E);
  
  min = N*C;
  for (i = 0; i <= N; i++){
    y = ((((float)N - (float)i)*(float)E - (float)H - (float)B*(float)i)/((float)D + (float)E) + 1);
    if((long)y < N - i){
      if(y < 0){
        y = 0;
      }
      if(min > i*A + (long)y*C){
        min = i*A + (long)y*C;
      }
    }
  }
  printf("%ld\n", min);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld", &N, &H);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld %ld %ld %ld", &A, &B, &C, &D, &E);
   ^
#include<stdio.h>
#include<math.h>

int main(){
  float txa, tya, txb, tyb, x, y, pos, p, q, T, V;
  int N, flag = 0;
  
  scanf("%f %f %f %f %f %f", &txa, &tya, &txb, &tyb, &T, &V);
  pos  = T*V;
  scanf("%d", &N);
  
  for (int i = 0; i < N; i++){
    scanf("%f %f", &x, &y);
    p = sqrt((txa - x)*(txa - x) + (tya - y)*(tya - y));
    q = sqrt((txb - x)*(txb - x) + (tyb - y)*(tyb - y));
    if(p + q <= pos){
      flag = 1;
    }
  }
  
  if(flag == 1){
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%f %f %f %f %f %f", &txa, &tya, &txb, &tyb, &T, &V);
   ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%f %f", &x, &y);
     ^
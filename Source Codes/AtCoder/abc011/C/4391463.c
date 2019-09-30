#include<stdio.h>

int main(){
  int N, NG1, NG2, NG3, p, q, r;
  
  scanf("%d", &N);
  scanf("%d %d %d", &NG1, &NG2, &NG3);
  
  if(N != NG1 && N != NG2 && N != NG3){
    for (int i = 0; i < 100; i++){
      p = N - 3;
      q = N - 2;
      r = N - 1;
      if(p >= 0 && p != NG1 && p != NG2 && p != NG3){
        N = p;
        if(N == 0){
          printf("YES\n");
          return 0;
        }
      } else if(q >= 0 && q != NG1 && q != NG2 && q != NG3){
        N = q;
        if(N == 0){
          printf("YES\n");
          return 0;
        }
      } else if(r >= 0 && r != NG1 && r != NG2 && r != NG3){
        N = r;
        if(N == 0){
          printf("YES\n");
          return 0;
        }
      }
    }
  }
  
  printf("NO\n");
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &NG1, &NG2, &NG3);
   ^
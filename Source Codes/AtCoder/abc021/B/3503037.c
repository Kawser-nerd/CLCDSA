#include <stdio.h>

int p[110];

int main(void){
  int n, i;
  scanf("%d", &n);
  int a, b;
  scanf("%d %d", &a, &b);
  
  for(i = 0; i < 110; i++){
    p[i] = 0;
  }
  
  p[a] = 1;
  p[b] = 1;
  
  int k;
  scanf("%d", &k);
  
  for(i = 0; i < k; i++){
    int x;
    scanf("%d", &x);
    if(p[x] == 1){
      printf("NO\n");
      return 0;
    }
    p[x] = 1;
  }
  
  printf("YES\n");
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &a, &b);
   ^
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &k);
   ^
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &x);
     ^
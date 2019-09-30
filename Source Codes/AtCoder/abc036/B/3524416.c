#include <stdio.h>
 
int main(void){
  int n;
  scanf("%d", &n);
  char c[50][51];
  
  for(int i = 0; i < n; i++){
    scanf("%s", c[i]);
  }
  
  for(int j = 0; j < n; j++){
    for(int i = n - 1; i >= 0; i--){
      printf("%c", c[i][j]);
    }
    printf("\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", c[i]);
     ^
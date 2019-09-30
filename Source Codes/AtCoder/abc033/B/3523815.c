#include <stdio.h>

int main(void){
  int n, a[1001];
  int sum = 0;
  char s[1001][21];
  scanf("%d", &n);
  
  for(int i = 0; i < n; i++){
    scanf("%s %d", s[i], &a[i]);
    sum += a[i];
  }
  
  for(int i = 0; i < n; i++){
    if(sum / 2 < a[i]){
      printf("%s\n", s[i]);
      return 0;
    }
  }
  
  printf("atcoder\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s %d", s[i], &a[i]);
     ^
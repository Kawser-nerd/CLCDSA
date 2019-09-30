#include <stdio.h>

int main(){
  int N, T, ans = 100, i;
  scanf("%d", &N);
  for(i = 0; i < N; i++){
	scanf("%d", &T);
    if(T < ans){
      ans = T;
    }
  }
  printf("%d\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &T);
  ^
#include <stdio.h>

int is_prime(int x){
  if(x%2 == 0) return 0;
  for(int j = 3;j*j < x;j += 2){
    if(x%j == 0) return 0;
  }
  return 1;
}

int main(void){
  int N;
  scanf("%d",&N);
  int cnt = 0;

  for(int i = 7;cnt < N;i += 5){
    if(is_prime(i)){
      printf("%d",i);
      cnt++;
      if(cnt != N) printf(" ");
      else printf("\n");
    }
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
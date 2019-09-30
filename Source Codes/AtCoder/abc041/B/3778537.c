#include <stdio.h>

int main(){
  long int A, B, C;
  long int volume;
  scanf("%ld %ld %ld", &A, &B, &C);
  volume = ((A*B)%1000000007)*C%1000000007;
  if(volume < 0){
    volume += 1000000007;
  }
  printf("%ld\n", volume);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld %ld", &A, &B, &C);
   ^
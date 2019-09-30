#include <stdio.h>
#include <math.h>

int main(void){
  long N,bit[40];
  long long A,K;
  long long ans = 0,X = 0;
  int flag[40];
  int counter;
  scanf("%ld%lld",&N,&K);

  for(int i = 0;i < 40;i++){
    bit[i] = 0;
    flag[i] = 0;
  }

  for(int i = 0;i < N;i++){
    scanf("%lld",&A);
    counter = 0;
    while(A > 0){
      flag[counter] = 1;
      if(A%2 != 0){
        bit[counter]++;
      }
      counter++;
      A /= 2;
    }
  }
  counter = 0;
  long sample = K;
  while(sample > 0){
    flag[counter] = 1;
    counter++;
    sample /= 2;
  }

  for(int i = 39;i >= 0;i--){
    if(flag[i]){
      if(bit[i] > N-bit[i] || X+(long)pow(2,i) > K){
        ans += (long)pow(2,i)*bit[i];
      }else{
        ans += (long)pow(2,i)*(N-bit[i]);
        X += pow(2,i);
      }
    }
  }

  printf("%lld\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%lld",&N,&K);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&A);
     ^
#include <stdio.h>

long max(long a,long b){
  if(a > b){
    return a;
  }
  return b;
}

int main(void){
  long N,K;
  scanf("%ld%ld",&N,&K);

  long s[N+1];
  int flag = 0;
  for(int i = 0;i < N;i++){
    scanf("%ld",&s[i]);
    if(s[i] == 0) flag = 1;
  }
  s[N] = 1 << 30;

  long ans = 0;
  if(flag){
    printf("%ld\n",N);
    return 0;
  }

  int left = 0,right = 0;
  long sum = 1;
  while(left < N){
    if(sum*s[right] <= K){
      sum *= s[right];
      if(ans < right-left+1) ans = right-left+1;
      right++;
    }else{
      sum /= s[left];
      left++;
    }
    if(left == right){
      right++;
      sum = s[left];
      if(sum <= K){
        if(!ans) ans = 1;
      }
    }
  }


  printf("%ld\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%ld",&N,&K);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",&s[i]);
     ^
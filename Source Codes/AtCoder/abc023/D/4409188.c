#include <stdio.h>

long long min(long long a,long long b){
  if(a < b){
    return a;
  }
  return b;
}

int main(void){
  int N;
  scanf("%d",&N);

  long long H[N],S[N];
  int time[N+1],flag;
  for(int i = 0;i < N;i++){
    scanf("%lld%lld",&H[i],&S[i]);
  }

  long long ok = 9000000000000000000;
  long long ng = 0;
  long long mid;
  while(ok-ng > 1){
    mid = (ok+ng)/2;
    flag = 0;
    for(int i = 0;i <= N;i++) time[i] = 0;
    for(int i = 0;i < N;i++){
      if(mid < H[i]){
        flag = 1;
        break;
      }
      time[min(N,(mid-H[i])/S[i])]++;
    }
    if(flag){
      ng = mid;
      continue;
    }
    int cnt = 0;
    for(int i = 0;i < N;i++){
      cnt++;
      cnt -= time[i];
      if(cnt < 0){
        ng = mid;
        break;
      }
      if(i == N-1) ok = mid;
    }
  }

  printf("%lld\n",ok);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&H[i],&S[i]);
     ^
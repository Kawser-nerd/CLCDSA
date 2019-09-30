#include <stdio.h>

long long max(long long a,long long b){
  if(b < a){
    return a;
  }
  return b;
}

int main(void){
  int N;
  scanf("%d",&N);

  long long H[N],S[N];
  int time[N+2],tmax;
  for(int i = 0;i < N;i++){
    scanf("%lld%lld",&H[i],&S[i]);
  }

  long long ok = 9000000000000000000;
  long long ng = 0;
  long long mid;
  while(ok-ng > 1){
    mid = (ok+ng)/2;
    for(int i = 0;i <= N+1;i++) time[i] = 0;
    for(int i = 0;i < N;i++){
      if(mid < H[i]){
        time[N+1] = 1;
        break;
      }
      if((mid-H[i])/S[i] > N){
        tmax = N;
      }else{
        tmax = (mid-H[i])/S[i];
      }
      time[tmax]++;
    }
    if(time[N+1]){
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
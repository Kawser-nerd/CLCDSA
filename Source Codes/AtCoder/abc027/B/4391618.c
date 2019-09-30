#include <stdio.h>

int main(void){
  int N;
  scanf("%d",&N);

  int a;
  int cnt = 0;
  int sum[N];
  for(int i = 0;i < N;i++) sum[i] = 0;
  for(int i = 0;i < N;i++){
    scanf("%d",&a);
    cnt += a;
    if(i == 0){
      sum[i] = a;
      continue;
    }
    sum[i] += sum[i-1]+a;
  }
  if(cnt%N != 0){
    printf("-1\n");
    return 0;
  }

  int ans = 0;
  int num = cnt/N;
  for(int i = 1;i < N;i++){
   if(sum[i-1] != num*i || sum[N-1]-sum[i-1] != num*(N-i)) ans++;
  }

  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^
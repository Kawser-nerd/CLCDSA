#include <stdio.h>

int main(void){
  int N;
  long long ans = -9223372036854775807;
  scanf("%d",&N);

  int F[N][10];
  long long P[N][11];

  for(int i = 0;i < N;i++){
    for(int j = 0;j < 10;j++){
      scanf("%d",&F[i][j]);
    }
  }

  for(int i = 0;i < N;i++){
    for(int j = 0;j < 11;j++){
      scanf("%lld",&P[i][j]);
    }
  }

  for(int i = 1;i < 1024;i++){
    int date = 0;
    int sample = i;
    int count[N];
    long long point = 0;

    for(int i = 0;i < N;i++){
      count[i] = 0;
    }
    while(date < 10){
      if(sample%2 != 0){   //date no hiniti eigyousuru
        for(int j = 0;j < N;j++){
          if(F[j][date] == 1) count[j]++;
        }
      }
      sample /= 2;
      date++;
    }

    for(int j = 0;j < N;j++){
      point += P[j][count[j]];
    }
    if(ans < point){
      ans = point;
    }
  }

  printf("%lld\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:13:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&F[i][j]);
       ^
./Main.c:19:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%lld",&P[i][j]);
       ^
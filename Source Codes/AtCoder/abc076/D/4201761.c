#include <stdio.h>

int main(void){
  int N;
  scanf("%d",&N);

  int t[N],v[N];
  int endtime = 0,time = 0;

  for(int i = 0;i < N;i++) scanf("%d",&t[i]);
  for(int i = 0;i < N;i++) scanf("%d",&v[i]);
  for(int i = 0;i < N;i++) endtime += t[i];

  double speed[2*endtime];
  double ans = 0;

  for(int i = 0;i < 2*endtime;i++) speed[i] = 60000;
  for(double i = 0;i < endtime;i += 0.5){
    double sample[N+2];
    sample[N] = i;
    sample[N+1] = endtime-i;
    time = 0;
    for(int j = 0;j < N;j++){
      if(i < time) sample[j] = v[j]+(time-i);
      else if(time+t[j] < i) sample[j] = v[j]+(i-(time+t[j]));
      else sample[j] = v[j];
    time += t[j];
    }
    for(int j = 0;j < N+2;j++){
      if(speed[(int)(i*2)] > sample[j])
        speed[(int)(i*2)] = sample[j];
    }
  }

  for(int i = 0;i < 2*endtime;i++){
    ans += 0.25*(speed[i]+speed[i+1]);
  }

  printf("%lf\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:10:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0;i < N;i++) scanf("%d",&t[i]);
                            ^
./Main.c:11:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0;i < N;i++) scanf("%d",&v[i]);
                            ^
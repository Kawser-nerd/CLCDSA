#include <stdio.h>
#define INF 1 << 29

int main(void){
  int N,M;
  long X,Y;
  scanf("%d%d%ld%ld",&N,&M,&X,&Y);

  long a[N+2],b[M+2];
  for(int i = 1;i <= N;i++) scanf("%ld",&a[i]);
  for(int i = 1;i <= M;i++) scanf("%ld",&b[i]);

  a[0] = -1; b[0] = -1;
  a[N+1] = INF; b[M+1] = INF;

  int ans = 0;
  long time = 0;

  int ri,le,mid;
  while(1){
    le = 0; ri = N+1; mid = (le+ri)/2;
    while(ri-le > 1){
      mid = (le+ri)/2;
      if(a[mid] >= time) ri = mid;
      else le = mid;
    }
    if(a[ri] == INF){
      printf("%d\n",ans);
      return 0;
    }else{
      time = a[ri]+X;
    }

    le = 0; ri = M+1; mid = (le+ri)/2;
    while(ri-le > 1){
      mid = (le+ri)/2;
      if(b[mid] >= time) ri = mid;
      else le = mid;
    }
    if(b[ri] == INF){
      printf("%d\n",ans);
      return 0;
    }else{
      time = b[ri]+Y;
      ans++;
    }
  }
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%ld%ld",&N,&M,&X,&Y);
   ^
./Main.c:10:29: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 1;i <= N;i++) scanf("%ld",&a[i]);
                             ^
./Main.c:11:29: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 1;i <= M;i++) scanf("%ld",&b[i]);
                             ^
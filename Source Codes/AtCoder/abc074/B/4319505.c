#include <stdio.h>
#include <math.h>
int main(void){
  int i,n,k,sum=0;
  int dis;
  int x[100];
  scanf("%d%d",&n,&k);
  for(i=0;i<n;i++){
    scanf("%d",&x[i]);
    dis=fmin(x[i],abs(x[i]-k));
    sum+=dis;
  }
  printf("%d",sum*2);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:19: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
     dis=fmin(x[i],abs(x[i]-k));
                   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x[i]);
     ^
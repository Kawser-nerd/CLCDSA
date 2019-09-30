#include <stdio.h>
 
int main(){
  double i,N,sum=0;
	scanf("%lf",&N);
  for(i=1;i<=N;i++){
  	sum += 1/N*i*10000; 
  }
  printf("%.0f\n",sum);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf",&N);
  ^
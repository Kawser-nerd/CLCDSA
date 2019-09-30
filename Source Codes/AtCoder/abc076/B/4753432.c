#include <stdio.h>
#include <math.h>

int main(){
	int N,K,i;
  double min = 100000000000000,result=0;
  scanf("%d %d",&N,&K);
  
  for(i=0;i<=N;i++){
  	result =  pow(2,(double)(N-i));
    result = result + i*K;
    if(result <min) min = result;
    result = 0;
  }
  printf("%.0f\n",min);
  return 0;

} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&N,&K);
   ^
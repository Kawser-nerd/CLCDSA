#include<stdio.h>

int main(void){
  int n,i;
  scanf("%d",&n);
	double sum=0;
  for(i=1;i<n+1;i++){
      sum=sum+i*10000.0/n;
  }
    printf("%lf",sum);
	printf("\n");
  return 0;
 } ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
#include<stdio.h>

double prob(int n,int k){
  return 3.0*k/n*k/n*(n-k)/n+1.0*k/n*k/n*k/n;
}

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  double p=prob(n,k)-prob(n,k-1);
  printf("%.9lf\n",p);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
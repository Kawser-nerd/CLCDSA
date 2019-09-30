#include<stdio.h>

int main(void)
{
  int n,m,a=0,b=0,c=0;
  int i,j,k;
  int sum_n=0,sum_m=0;
  int x;
  
  scanf("%d%d",&n,&m);

  for(i=0;i<=n;i++){
    sum_n=n-i;
    sum_m=m-i*2;
    k=sum_m-sum_n*3;
    j=sum_n-k;
    
    if(k>=0&&k<=n){
      printf("%d %d %d\n",i,j,k);
      return 0;
    }
  }

  printf("-1 -1 -1\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
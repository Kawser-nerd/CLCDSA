#include <stdio.h>
#include <math.h>
int main(void){
  int n,k,i;
  scanf("%d %d",&n,&k);
  int sum=1;
  for(i=0;i<n;i++){
    if(sum*2<sum+k) sum*=2;
    else sum+=k;
  }
  printf("%d\n",sum);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&k);
   ^
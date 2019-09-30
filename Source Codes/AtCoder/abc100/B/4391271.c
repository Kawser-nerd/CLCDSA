#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int calc(int x){
  int y=0;
  while(x%100==0){  
    x/=100;
    y++;
  }
  return y;  
}
int main(void){
  int d,n;
  scanf("%d%d",&d,&n);
  int cnt,x=0,ans=0,j=0;
  while(j<n){
    x++;
    if(calc(x)==d) {j++;}
  }
  printf("%d",x);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&d,&n);
   ^
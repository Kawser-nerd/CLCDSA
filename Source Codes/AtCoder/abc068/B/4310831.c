#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int main(void){
  int count,n,i,r,max=0,maxnum=1;
  scanf("%d",&n);
  for(i=n;i>=1;i--){
    count=0;
    r=i;
    while(r>=1){
      if(r%2==1) break;
      count++;r=r/2;
    }
    if(count>max) {max=count;maxnum=i;}
  }
  printf("%d",maxnum);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
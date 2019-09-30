#include <stdio.h>
#include <string.h>
#include <math.h>
int main(void){
  int k,s,x,y,cnt=0;
  scanf("%d%d",&k,&s);
  for(x=0;x<=k;x++){
    for(y=0;y<=k;y++){
      int z=s-x-y;
      if(z>=0&&z<=k) cnt++;
    }
  }
  printf("%d",cnt);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&k,&s);
   ^
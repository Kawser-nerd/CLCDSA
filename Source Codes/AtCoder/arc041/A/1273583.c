#include<stdio.h>
int main(void){
  int x,y,z,k;
  scanf("%d %d",&x,&y);
  scanf("%d",&k);
  if(y<k){
    z=x+2*y-k;
  }
  else{
    z=x+k;
  }
  printf("%d\n",z);
      return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&x,&y);
   ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&k);
   ^
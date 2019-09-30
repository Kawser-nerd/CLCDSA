#include<stdio.h>

int main(void){
  long int i,x,y,z;
  scanf("%ld%ld%ld",&x,&y,&z);
  for(i=0;;i++){
    if(x<y*i+z*(i+1)) break;
  }
  printf("%ld\n",i-1);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%ld%ld",&x,&y,&z);
   ^
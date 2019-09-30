#include<stdio.h>
int main(){
  int i;
  scanf("%d",&i);
  if(i%2==1) printf("%d\n",i/2+1);
  else{
      printf("%d\n",i/2);
  } 
    return 0;
  } ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&i);
   ^
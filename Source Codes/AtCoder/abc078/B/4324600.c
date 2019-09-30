#include<stdio.h>

int main(){
  int i=1,j,k;
  int X,Y,Z;
  
  scanf("%d %d %d",&X,&Y,&Z);
  
  while(1){
    if(X < Y*i+(i+1)*Z){
      printf("%d\n",i-1);
      return 0;
    }
    i++;
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&X,&Y,&Z);
   ^
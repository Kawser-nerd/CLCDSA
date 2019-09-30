#include<stdio.h>

int main(){
  int i,j=0,k=0;
  
  int a,b;
  
  scanf("%d %d",&a,&b);
  
  k = b-a;
  
  for(i=1;i<k;i++)
    j += i;
  
  printf("%d\n",j-a);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^
#include<stdio.h>

int main(void){
  int a,b,c,k,s,t;
  int bill;
  
  scanf("%d %d %d %d",&a,&b,&c,&k);
  scanf("%d %d",&s,&t);
  
  bill = (a*s) + (b*t);
  
  if((s+t)>=k){
    bill = bill - (s+t)*c;
  }
  
  printf("%d\n",bill);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d",&a,&b,&c,&k);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&s,&t);
   ^
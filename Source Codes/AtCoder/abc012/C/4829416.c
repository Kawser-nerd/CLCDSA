#include<stdio.h>

int main(void){
  int n,i,j,sum=0,sub;
  scanf("%d",&n);
  for(i=1;i<10;i++){
    for(j=1;j<10;j++){
      sum += i*j;
    }
  }
  sub = sum-n;
  for(i=1;i<10;i++){
    for(j=1;j<10;j++){
      if(sub==i*j) printf("%d x %d\n",i,j);
    }
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
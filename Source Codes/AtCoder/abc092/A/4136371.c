#include<stdio.h>

int main(void){
  int a,b,c,d;
  scanf("%d %d %d %d",&a,&b,&c,&d);
  
  if(a<=b){
    if(c<=d){
      printf("%d\n",a+c);
    }else{
      printf("%d\n",a+d);
    }
  }else{
    if(c<=d){
      printf("%d\n",b+c);
    }else{
      printf("%d\n",b+d);
    }
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d",&a,&b,&c,&d);
   ^
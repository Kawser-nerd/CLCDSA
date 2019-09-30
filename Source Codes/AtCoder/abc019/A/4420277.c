#include <stdio.h>

int min(int a,int b){
  if(a < b){
    return a;
  }
  return b;
}

int max(int a,int b){
  if(a > b){
    return a;
  }
  return b;
}

int main(void){
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  printf("%d\n",a+b+c-max(a,max(b,c))-min(a,min(b,c)));

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^
#include <stdio.h>

int max(int a,int b){
  if(a > b){
    return a;
  }
  return b;
}

int main(void){
  int a,b,c,d,e;
  scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);

  printf("%d\n",max(a+d+e,b+c+e));
    
  return 0;
} ./Main.c: In function �main�:
./Main.c:12:3: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
   ^
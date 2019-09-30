#include<stdio.h>
int max(int a,int b){
  if(a>b) return a;
  else return b;
}
int main(void){
  int a,b,c,d;
  scanf("%d%d%d%d",&a,&b,&c,&d);
  printf("%d\n",max(a*b,c*d));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&a,&b,&c,&d);
   ^
#include<stdio.h>
int main(){
  int a,b,c,d,i,s=0;
  scanf("%d%d%d%d",&a,&b,&c,&d);
  for(i=0;i<101;i++){
    if(a<=i&&i<=b&&c<=i&&i<=d) s++;
  }
  printf("%d",s-1*(s>0));
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&a,&b,&c,&d);
   ^
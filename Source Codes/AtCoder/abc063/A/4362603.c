# include <stdio.h>

int main(){
  int a,b;
  scanf("%d %d",&a,&b);
  if(a+b>=10) puts("error");
  else printf("%d\n",a+b);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^
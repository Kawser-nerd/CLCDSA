#include<stdio.h>
int main(){
  int a,b,i;
  scanf("%d %d",&a,&b);
  if(1<b&&b<2*a-1){
    printf("Yes\n");
    for(i=0;i<2*a-1;i++)printf("%d\n",(i+b+a-1)%(2*a-1)+1);
  }
  else printf("No\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^
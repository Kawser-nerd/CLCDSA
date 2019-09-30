#include <stdio.h>
#include <math.h>
int main(void){
  int i,n,t,a,h,p,ans=1,min=999999;
  scanf("%d%d%d",&n,&t,&a);
  for(i=1;i<=n;i++){
    scanf("%d",&h);
    p=abs((t*1000-h*6)-a*1000);
    if(min>p) {ans=i;min=p;}
  }
  printf("%d",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:7: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
     p=abs((t*1000-h*6)-a*1000);
       ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&t,&a);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&h);
     ^
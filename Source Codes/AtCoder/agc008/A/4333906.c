#include<stdio.h>
#include<stdlib.h>

int main(){
  int x,y,ans=0;
  scanf("%d%d",&x,&y);
  if(x==y){
    puts("0");
    return 0;
  }
  else if(abs(x)<abs(y)){
    if(x<0) ans++;
    ans+=abs(y)-abs(x);
    if(y<0) ans++;
  }
  else {
    if(x>0) ans++;
    ans+=abs(x)-abs(y);
    if(y>0) ans++;
  }
  printf("%d",ans);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&x,&y);
   ^
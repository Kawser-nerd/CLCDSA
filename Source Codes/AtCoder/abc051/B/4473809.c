#include<stdio.h>

int main(void){
  int s,k,x,y,z,ans=0;
  scanf("%d %d",&k,&s);
  for(x=0;x<=k;x++){
    for(y=0;y<=k;y++){
      if((0<=s-(x+y)) && (s-(x+y)<=k)) ans++;
    }
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&k,&s);
   ^
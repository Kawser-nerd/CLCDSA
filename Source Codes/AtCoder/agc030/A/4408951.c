#include<stdio.h>

int main(void){
  int a,b,c,ans;
  ans=0;
  while(scanf("%d%d%d",&a,&b,&c)!=3);
  if(c<a+b+1){
	ans+=c+b;
  }else{
    ans+=a+b+1+b;
  }
  printf("%d",ans);
  return 0;
}
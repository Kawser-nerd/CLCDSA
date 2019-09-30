#include<stdio.h>
int main(){
  int h,w,i,j,t=0;
  char c;
  scanf("%d%d",&h,&w);
  for(i=0;i<h;i++){
    for(j=0;j<=w;j++){
      scanf("%c",&c);
      if(c=='#') t++;
    }
  }
  puts(t==h+w-1?"Possible":"Impossible");
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&h,&w);
   ^
./Main.c:8:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%c",&c);
       ^
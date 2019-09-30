#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void){
  int h,w,i,j,sharp=0;
  char s[10][10];
  scanf("%d%d",&h,&w);
  for(i=1;i<=h;i++){
    for(j=1;j<=w;j++){
      scanf(" %c",&s[i][j]);
    }
  }
  for(i=1;i<=h;i++){
    for(j=1;j<=w;j++){
      if(s[i][j]=='#') sharp++;
    }
  }
  if(h+w-1==sharp) printf("Possible");
  else printf("Impossible");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&h,&w);
   ^
./Main.c:10:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf(" %c",&s[i][j]);
       ^
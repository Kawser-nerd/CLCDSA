#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main(void){
  char s[100][100];
  int t[101]={},y[101]={};
  int h,w,i,j;
  scanf("%d%d",&h,&w);
  for(i=0;i<h;i++)scanf("%s",s[i]);
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(s[i][j]=='#'){t[i]=1;y[j]=1;}
    }
  }
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(t[i]==1&&y[j]==1) printf("%c",s[i][j]);
    }
    if(t[i]==1)putchar('\n');
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&h,&w);
   ^
./Main.c:10:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<h;i++)scanf("%s",s[i]);
                   ^
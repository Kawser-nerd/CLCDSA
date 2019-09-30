#include <stdio.h>
int main(void){
  int h,w;
  scanf("%d%d",&h,&w);
  int i,j;
  char s[51][51];
  for(i=0;i<h;i++){
    scanf("%s",s[i]);
  }
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(s[i][j]=='#') printf("#");
      else{
        int count=0;
        if(s[i-1][j-1]=='#') count++;
        if(s[i-1][j]=='#') count++;
        if(s[i][j-1]=='#') count++;
        if(s[i+1][j-1]=='#') count++;
        if(s[i+1][j]=='#') count++;
        if(s[i+1][j+1]=='#') count++;
        if(s[i][j+1]=='#') count++;
        if(s[i-1][j+1]=='#') count++;
        printf("%d",count);
      }
    }
    puts("");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&h,&w);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s[i]);
     ^
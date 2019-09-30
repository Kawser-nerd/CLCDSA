#include <stdio.h>

int main(){
  int H,W;
  scanf("%d%d",&H,&W);
  int i,j;
  char s[H][W];
  for(i=0;i<H;i++){
    scanf("%s",s[i]);
  }
  int flag=0;
  for(i=1;i<H-1;i++){
    for(j=1;j<W-1;j++){
      if(s[i][j]=='#'&& s[i-1][j]=='.' && s[i+1][j]=='.' && s[i][j+1]=='.' && s[i][j-1]=='.'){
	flag=1;
      }
    }
  }
  
  for(j=1;j<W-1;j++){
    if(s[0][j]=='#' && s[1][j]=='.' && s[0][j+1]=='.' && s[0][j-1]=='.'){
      flag=1;
    }
  }
  for(j=1;j<W-1;j++){
    if(s[H-1][j]=='#' && s[H-2][j]=='.' && s[H-1][j+1]=='.' && s[H-1][j-1]=='.'){
      flag=1;
    }
  }
  for(i=1;i<H-1;i++){
    if(s[i][0]=='#' && s[i+1][0]=='.' && s[i-1][0]=='.' && s[i][1]=='.'){
      flag=1;
    }
  }
  for(i=1;i<H-1;i++){
    if(s[i][W-1]=='#' && s[i+1][W-1]=='.' && s[i-1][W-1]=='.' && s[i][W-2]=='.'){
      flag=1;
    }
  }
  if(s[0][0]=='#' && s[1][0]=='.' && s[0][1]=='.'){flag=1;}
  if(s[0][W-1]=='#' && s[1][W-1]=='.' && s[0][W-2]=='.'){flag=1;}
  if(s[H-1][0]=='#' && s[H-1][1]=='.' && s[H-2][0]=='.'){flag=1;}
  if(s[H-1][W-1]=='#' && s[H-1][W-2]=='.' && s[H-2][W-1]=='.'){flag=1;}

  if(flag==0){
    printf("Yes");
  }else{
    printf("No");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&H,&W);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s[i]);
     ^
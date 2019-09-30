#include <stdio.h>

#define MAX_LEN 52

int main(){
  
  int H,W,i,j;
  scanf("%d%d",&H,&W);
  char s[MAX_LEN][MAX_LEN];
  for(i = 1; i <= H; i++){
    scanf("%s",&s[i]);
  }
              
  
  int ans = 1;
  for(i = 1; i <= H; i++){
    for(j = 1; j <= W; j++){
      if(s[i][j] == '#'&&s[i-1][j] != '#'&&s[i+1][j] != '#'&&s[i][j-1] != '#'&&s[i][j+1] != '#')
        ans = 0;
    }
  }
  
  if(ans == 0) printf("No");
  else printf("Yes");
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[52]’ [-Wformat=]
     scanf("%s",&s[i]);
           ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&H,&W);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",&s[i]);
     ^
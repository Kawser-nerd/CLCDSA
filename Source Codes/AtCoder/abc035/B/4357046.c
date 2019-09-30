#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  char S[100000];
  scanf("%s",S);

  int x = 0,y = 0,cnt = 0;
  for(int i = 0;i < strlen(S);i++){
    switch(S[i]){
      case 'L':
        x--;
        break;
      case 'R':
        x++;
        break;
      case 'U':
        y++;
        break;
      case 'D':
        y--;
        break;
      case '?':
        cnt++;
        break;
    }
  }

  int t;
  scanf("%d",&t);

  if(t == 1){
    printf("%d\n",abs(x)+abs(y)+cnt);
  }else{
    if(cnt >= abs(x)+abs(y)){
      cnt -= abs(x)+abs(y);
      if(cnt%2 == 0) printf("0\n");
      else printf("1\n");
    }else{
      printf("%d\n",abs(x)+abs(y)-cnt);
    }
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&t);
   ^
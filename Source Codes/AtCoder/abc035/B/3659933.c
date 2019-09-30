#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  char s[100001];
  int t,x=0,y=0,cnt=0;
  scanf("%s%d",s,&t);
  for(int i=0; i<strlen(s); i++) {
    if(s[i]=='U') y++;
    else if(s[i]=='D') y--;
    else if(s[i]=='R') x++;
    else if(s[i]=='L') x--;
    else cnt++;
  }
  for(int i=0; i<cnt; i++) {
    if(t==1) {
      if(x>=0) x++;
      else x--;
    }else{
      if(x>0) x--;
      else if(x<0) x++;
      else if(y>0) y--;
      else if(y<0) y++;
      else x++;
    }
  }
  printf("%d\n",abs(x)+abs(y));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%d",s,&t);
   ^
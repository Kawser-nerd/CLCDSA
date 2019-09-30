#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main(void){
  char s[100001];
  scanf("%s", s);
  int a;
  scanf("%d", &a);
  int x = 0;
  int y = 0;
  int count = 0;
  int ans;
  
  for(int i = 0; i < strlen(s); i++){
    if(s[i] == 'R') x++;
    else if(s[i] == 'L') x--;
    else if(s[i] == 'U') y++;
    else if(s[i] == 'D') y--;
    else count++;
  }
  
  if(a == 1){
    ans = abs(x) + abs(y) + count;
  }else{
    if(abs(x) + abs(y) < count){
      if((count - abs(x) - abs(y)) % 2 == 0){
        ans = 0;
      }else{
        ans = 1;
      }
    }else{
      ans = abs(x) + abs(y) - count;
    }
  }
  
  printf("%d\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a);
   ^
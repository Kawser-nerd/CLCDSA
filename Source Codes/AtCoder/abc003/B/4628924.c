#include <stdio.h>
#include <string.h>

int main(void){
  char s[10];
  char t[10];
  char data[7] = {'a','t','c','o','d','e','r'};

  scanf("%s%s",s,t);

  int ans = 1;
  for(int i = 0;i < strlen(s);i++){
    if(s[i] == t[i]) continue;
    if(s[i] == '@'){
      for(int j = 0;j < 7;j++){
        if(t[i] == data[j]) break;
        if(j == 6){
          ans = 0;
          break;
        }
      }
    }else if(t[i] == '@'){
      for(int j = 0;j < 7;j++){
        if(s[i] == data[j]) break;
        if(j == 6){
          ans = 0;
          break;
        }
      }
    }else{
      ans = 0;
      break;
    }
  }

  if(ans) printf("You can win\n");
  else printf("You will lose\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%s",s,t);
   ^
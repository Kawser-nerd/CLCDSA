#include <stdio.h>
#include <string.h>

int main(){
  char s[100010] = {};
  int flag[30] = {};//'a'+i?s[]??????s[i]==1????????s[i]==0

  scanf("%s", s);

  for(int i = 0; i < strlen(s); i++){
    flag[s[i] - 'a'] = 1;
  }

  for(int i = 0; i < 26; i++){
    if(flag[i] == 0){
      printf("%c\n", 'a' + i);
      return 0;
    }
  }

  printf("None\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^
#include <stdio.h>
#include <string.h>

int main(void){
  char s[15];
  scanf("%s",s);

  for(int i = 0;i <strlen(s);i++){
    if(i == 0){
      if('a' <= s[i] && s[i] <= 'z')
        s[i] += 'A'-'a';
    }else if('A' <= s[i] && s[i] <= 'Z'){
      s[i] += 'a'-'A';
    }
    printf("%c",s[i]);
  }
  printf("\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
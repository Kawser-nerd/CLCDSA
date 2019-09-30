#include <stdio.h>
#include <string.h>

int main(void){
  char s[4] = {'\0'};
  char cmp[4] = "abc";
  char temp;
  scanf("%3s", s);
  for(int i = 0; i < 3; i++){
    for(int j = i + 1; j < 3; j++){
      if(s[i] > s[j]){
	temp = s[i];
	s[i] = s[j];
	s[j] = temp;
      }
    }
  }

  if(strcmp(s, cmp) == 0) printf("Yes\n");
  else printf("No\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%3s", s);
   ^
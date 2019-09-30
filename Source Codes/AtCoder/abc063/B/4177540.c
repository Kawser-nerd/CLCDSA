#include <stdio.h>

int main(void){
  char s[27] = { '\0' };
  scanf("%s", s);
  int i = 0;
  while(s[i] != '\0') i++;
  char temp;
  int j, k;
  for(j = 0; j < i; j++){
    for(k = j + 1; k < i; k++){
      if(s[j] < s[k]){
	temp = s[j];
	s[j] = s[k];
	s[k] = temp;
      }
    }
  }
  int flag = 1;
  for(j = 0; j < i - 1; j++){
    if(s[j] == s[j + 1]){
      flag = 0;
      break;
    }
  }
  if(flag) printf("yes\n");
  else printf("no\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^
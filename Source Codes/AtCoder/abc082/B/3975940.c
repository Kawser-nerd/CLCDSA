#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
  char s[101], t[101];
  scanf("%s", s);
  scanf("%s", t);
  int i, j;
  char tmp;
  int flag;
  
  for(i = 0; i < strlen(s) - 1; i++){
    for(j = i + 1; j < strlen(s); j++){
      if(s[i] > s[j]){
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
      }
    }
  }
  for(i = 0; i < strlen(t) - 1; i++){
    for(j = i + 1; j < strlen(t); j++){
      if(t[i] < t[j]){
        tmp = t[i];
        t[i] = t[j];
        t[j] = tmp;
      }
    }
  }
  
  if(strcmp(s, t) < 0){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", t);
   ^
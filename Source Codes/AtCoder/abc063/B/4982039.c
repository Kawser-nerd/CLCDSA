#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[])
{
  char s[27];
  scanf("%s", s);
  
  int n = strlen(s);
  int flag = 0;
  
  for(int i = 1; i < n; i++){
    for(int j = 0; j < i; j++){
      if(s[i] == s[j]){
        flag++;
        break;
      }
    }
    if(flag > 0){
      break;
    }
  }
  
  if(flag > 0){
    printf("no\n");
  }
  else{
    printf("yes\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^
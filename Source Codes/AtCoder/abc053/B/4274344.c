#include <stdio.h>
#include <string.h>

int main(void){
  char str[200000];
  scanf("%s",str);

  int start,end;
  for(int i = 0;;i++){
    if(str[i] == 'A'){
      start = i;
      break;
    }
  }
  for(int i = strlen(str);;i--){
    if(str[i] == 'Z'){
      end = i;
      break;
    }
  }
  printf("%d\n",end-start+1);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",str);
   ^
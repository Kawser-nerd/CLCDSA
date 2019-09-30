#include <stdio.h>
#include <string.h>
int main(){
  char s[20];

  scanf("%s", s);

  for(int cnt = 0; cnt < 19; cnt++){
    if(s[cnt] != ','){
      printf("%c", s[cnt]);
    }else{
      printf(" ");
    }

  }
  printf("\n");
  
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^
#include<stdio.h>

int main(){
  char s[200001];
  int i = 0, len = 0;
  
  scanf("%s", s);
  while(s[len]){
    len++;
  }
  while(1){
    if(s[i++] == 'A'){
      break;
    }
  }
  
  while(1){
    if(s[len--] == 'Z'){
      break;
    }
  }
  
  printf("%d\n", len - i + 3);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^
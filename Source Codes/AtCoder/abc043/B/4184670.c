#include<stdio.h>

int main(){
  int len = 0, i = 0, j;
  char s[11], t[11];
  
  scanf("%s", s);
  while(s[len]){
    if(s[len] == '0'){
      t[i++] = '0';
      t[i] = '\0';
    } else if(s[len] == '1'){
      t[i++] = '1';
      t[i] = '\0';
    } else if(s[len] == 'B'){
      if(i > 0){
        t[--i] = '\0';
      }
    }
    len++;
  }
  
  printf("%s\n", t);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^
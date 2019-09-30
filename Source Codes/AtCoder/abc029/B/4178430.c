#include<stdio.h>

int main(){
  int len, i, count = 0;
  char s[12][11];
  
  for (i = 0; i < 12; i++){
    scanf("%s", s[i]);
  }
  
  for (i = 0; i < 12; i++){
    len = 0;
    while(s[i][len]){
      if(s[i][len] == 'r'){
        count++;
        len++;
        break;
      }
      len++;
    }
  }
  
  printf("%d\n", count);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s[i]);
     ^
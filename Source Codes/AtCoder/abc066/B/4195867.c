#include<stdio.h>
 
int main(){
  int len = 0, i, j, count = 0;
  char s[201];
  
  scanf("%s", s);
  while(s[len]){
    len++;
  }
  
  for (i = len - 2; i >= 0; i -= 2){
    count++;
    s[i] = '\0';
    for (j = 0; j < i/2; j++){
      if(s[j] != s[j + i/2]){
        break;
      }
    }
    if(i/2 == j){
      printf("%d\n", len - count*2);
      return 0;
    }
  }
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^
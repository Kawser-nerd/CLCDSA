#include <stdio.h>

int main(){
  char s[1001];
  scanf("%s", s);
  int i = 0;
  int n;
  char a;
  
  while(1){
    if(s[i] == '\0') break;
    a = s[i];
    n = 0;
    while(1){
      if(a == s[i]){
        n++;
      }else{
        printf("%c%d", a, n);
        break;
      }
      i++;
    }
  }
  printf("\n");
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^
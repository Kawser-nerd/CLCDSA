#include<stdio.h>

int main(){
  int len = 0, i = 0;
  char s[100001], t[50001];
  
  scanf("%s", s);
  while(s[len]){
    if(len%2 == 0){
      t[i++] = s[len];
    }
    len++;
  }
  t[i] = '\0';
  
  printf("%s\n", t);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^
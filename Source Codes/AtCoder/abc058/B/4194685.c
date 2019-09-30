#include<stdio.h>

int main(){
  char O[51], E[51], p[101], i;
  int len = 0;
  
  scanf("%s %s", O, E);
  
  while(O[len]){
    len++;
  }
  
  for (i = 0; i < len; i++){
    p[2*i] = O[i];
    p[2*i + 1] = E[i];
  }
  p[2*i] = '\0';
  
  printf("%s\n", p);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %s", O, E);
   ^
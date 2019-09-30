#include<stdio.h>
#include<string.h>
int main(void){
  int i,l;
  char AA;
  char x[50];

  scanf("%c %s" ,&AA,x);
  l = strlen(x);

  for(i = 0; i < l; i++){
    if(x[i] != AA){
      printf("%c",x[i]);
    }
  }
  printf("\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c %s" ,&AA,x);
   ^
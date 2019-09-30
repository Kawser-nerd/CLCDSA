#include<stdio.h>
#include<string.h>

int main(){
char s[1000000];
  int i,j,k;
  
  scanf("%s",s);
  for(i=0;i<strlen(s);i++){
    if(i%2 == 0)
      printf("%c",s[i]);
  }
  puts("");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
#include<stdio.h>
#include<string.h>

int main(){
  char s[10];
  int i,a;
  for(i=0;i<12;i++){
    scanf("%s",s);
    if(strchr(s,'r')) a++;
  }
  printf("%d\n",a);
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^
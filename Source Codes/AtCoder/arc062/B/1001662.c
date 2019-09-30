#include<stdio.h>

int main(){
  int i,pCount=0;
  char s[100001];

  scanf("%s",s);
  for(i=1;s[i]!='\0';++i){
    if(s[i]=='p') ++pCount;
  }
  i=i/2;
  printf("%d\n",i-pCount);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
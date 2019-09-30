#include <stdio.h>
int main(void){
char s[100005];
  int count;
  scanf("%s",s);
  for(count=0;;){
  printf("%c",s[count]);
    if(s[count+1]=='\0'||s[count+2]=='\0'){break;}
    count=count+2;
  }
  
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
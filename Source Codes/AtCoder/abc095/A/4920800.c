#include <stdio.h>
int main(){
  char s[4];
  int f=700;
  scanf("%s",s);
  for(int i=0;i<3;i++){
    if(s[i]=='o'){
      f+=100;
    }
  }
  printf("%d",f);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
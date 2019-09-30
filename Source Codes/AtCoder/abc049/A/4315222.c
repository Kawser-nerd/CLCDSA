#include <stdio.h>
int main(void){
char a[2];
  scanf("%s",a);
  if(a[0]=='a'||a[0]=='i'||a[0]=='u'||a[0]=='o'||a[0]=='e'){
  printf("vowel");
  }
  else{
  printf("consonant");
  }
  
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",a);
   ^
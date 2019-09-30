#include <stdio.h>
int main(void){
  char s[100];
  int t[100]={0},i;
 scanf("%s",s);
  for(i=0;s[i]!=0;i++){
    t[s[i]-'a']++;
  }
  for(i=0;i<27;i++){
    if(t[i]%2!=0) {printf("No");return 0;}
  }
  printf("Yes");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^
#include<stdio.h>
int main(){
  char s[100010]={0};
  int i;
  scanf("%s",s);
  for(i=0;s[i+1];i++){
    if(s[i]==s[i+1]){
      printf("%d %d\n",i+1,i+2);
      return 0;
    }
    if(s[i]==s[i+2]){
      printf("%d %d\n",i+1,i+3);
      return 0;
    }
  }
  printf("-1 -1\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
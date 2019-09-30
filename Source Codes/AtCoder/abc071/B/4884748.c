#include <stdio.h>
#include <string.h>

int main(void){
  char s[100000];
  scanf("%s",s);
  int j[100]={0};
  int n=strlen(s);
  for(int i=0;i<n;i++){
    int num=s[i]-'a';
    j[num]=1;
  }
  for(int i=0;i<26;i++){
    if(j[i]==0){
      printf("%c",i+'a');
      return 0;
    }
  }
  printf("None");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
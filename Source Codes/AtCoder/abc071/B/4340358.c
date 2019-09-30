#include<stdio.h>
#include<string.h>

int main(){
  int i,j,k;
  
  char S[1000000];
  scanf("%s",S);
  int flg[26];
  for(i=0;i<strlen(S);i++){
    flg[(int)S[i]-97]=1;
  }
  
  for(i=0;i<26;i++){
    if(flg[i]==0){
      printf("%c\n",i+97);
      return 0;
    }
  }
  
  puts("None");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^
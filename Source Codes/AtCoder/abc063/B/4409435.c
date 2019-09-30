#include<stdio.h>
#include<string.h>

int main(){
  int i,j,k;
  
  char S[100];
  
  scanf("%s",S);
  
  for(i=0;i<strlen(S);i++){
    for(j=0;j<i;j++){
      if(S[j] == S[i]){
        puts("no");
        return 0;
      }
    }
  }
  
  puts("yes");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^
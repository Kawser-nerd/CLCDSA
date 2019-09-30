#include <stdio.h>
#include <string.h>
int main(){
  char w[31];
  scanf("%s",w);
  for (int i=0;i<strlen(w);i++){
    if (w[i]=='a' || w[i]=='e' || w[i]=='i' || w[i]=='o' || w[i]=='u');
    else printf("%c",w[i]);
  }
  printf("\n");
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",w);
   ^
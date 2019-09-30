#include <stdio.h>
#include <string.h>

int main(){
  char S[30] = {};
  scanf("%s", S);

  for(int i = 0; i < strlen(S); i++){
    for(int j = i + 1; j < strlen(S); j++){

      if(S[i] == S[j]){
        printf("no\n");
        return 0;
      }

    }
  }

  printf("yes\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S);
   ^
#include <stdio.h>
#include <stdlib.h>

int main(void){
  
  char *S;
  int len = 0;
  int i;
  int j = 0;

  S = malloc(256);

  scanf("%s", S);

  while(S[len]){
    len++;
  }

  if(len % 2 == 1){
    S[len - 1] = '\0';
    len = len - 1;
  }else{
    S[len - 1] = '\0';
    S[len - 2] = '\0';
    len = len - 2;
  }

  int n[len];

  while(len > 0){
    n[j] = 0;
    for(i = 0; i < (len / 2); i++){
      if(S[i] == S[i + len / 2]){
	n[j]++;
      }else{
	break;
      }
    }

    if(n[j] == len / 2){
      printf("%d\n", len);
      break;
    }else{
      S[len - 1] = '\0';
      S[len - 2] = '\0';
      len = len - 2;
      j++;
    }
  }

  free(S);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S);
   ^
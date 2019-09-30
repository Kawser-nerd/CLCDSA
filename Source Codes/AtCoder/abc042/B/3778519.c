#include <stdio.h>
#include <string.h>

//s<t ???-1?s==t???0?s>t???1?????
int compare_string(char s[], char t[]){
  int ls = strlen(s), lt = strlen(t);

  for(int i = 0; i < ls && i < lt; i++){
    if(s[i] < t[i]){
      return -1;
    }else if(s[i] > t[i]){
      return 1;
    }
  }

  if(ls < lt){
    return -1;
  }else if(ls == lt){
    return 0;
  }else{
    return 1;
  }

}

int main(){
  int N, L;
  char S[110][110] = {};

  scanf("%d %d", &N, &L);
  for(int i = 0; i < N; i++){
    scanf("%s", S[i]);
  }

  for(int i = 0; i < N; i++){
    for(int j = i + 1; j < N; j++){

      if(compare_string(S[i], S[j]) == 1){
        char tmp[110] = {};
        for(int k = 0; k < L; k++){
          tmp[k] = S[i][k];
          S[i][k] = S[j][k];
          S[j][k] = tmp[k];
        }
      }

    }
  }

  for(int i = 0; i < N; i++){
    printf("%s", S[i]);
  }
  printf("\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:30:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &L);
   ^
./Main.c:32:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S[i]);
     ^
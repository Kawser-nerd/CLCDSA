#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[])
{
  int N;
  char word[100][11];
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%s", word[i]);
  }
  
  int l = 0; int k = 0;
  
  for(int i = 0; i < N; i++){
    if(i > 0){
      for(int j = 0; j < i; j++){
        if(strcmp(word[i], word[j]) == 0){
          l += 1;
        }
      }
      
      if(word[i - 1][strlen(word[i - 1]) - 1] == word[i][0]){
        k += 1;
      }
    }
  }
  
  if(l == 0 && k == N - 1){
    printf("%s\n", "Yes");
  }
  else{
    printf("%s\n", "No");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", word[i]);
     ^
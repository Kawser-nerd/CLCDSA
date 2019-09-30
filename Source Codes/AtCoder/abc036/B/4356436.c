#include <stdio.h>

int main(void){
  int N;
  scanf("%d",&N);

  char s[N][N];
  for(int i = 0;i < N;i++){
    scanf("%s",s[i]);
  }


  for(int i = 0;i < N;i++){
    for(int j = N-1;j >= 0;j--){
      printf("%c",s[j][i]);
    }
    printf("\n");
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s[i]);
     ^
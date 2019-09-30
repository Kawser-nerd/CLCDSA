#include<stdio.h>

int main(){
  int N, flag = 0;
  char s[100];
  
  scanf("%d", &N);
  for (int i = 0; i < N; i++){
    scanf("%c", &s[i]);
    if(s[i] == 'Y'){
      flag = 1;
    }
  }
  if(flag == 0){
    printf("Three\n");
  } else {
    printf("Four\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c", &s[i]);
     ^
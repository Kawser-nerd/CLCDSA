#include<stdio.h>

int main(){
  int a_i = 0, b_i = 0, c_i = 0, i, next = 0, flag;
  char s[3][101];
  for (i = 0; i < 3; i++){
    scanf("%s", s[i]);
  }
  
  while(1){
    if(next == 0){
      if(s[0][a_i] == '\0'){
        flag = 0;
        break;
      }
      next = s[0][a_i++] - 'a';
    } else if(next == 1){
      if(s[1][b_i] == '\0'){
        flag = 1;
        break;
      }
      next = s[1][b_i++] - 'a';
    } else if(next == 2){
      if(s[2][c_i] == '\0'){
        flag = 2;
        break;
      }
      next = s[2][c_i++] - 'a';
    }
  }
  
  if(flag == 0){
    printf("A\n");
  } else if(flag == 1){
    printf("B\n");
  } else {
    printf("C\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s[i]);
     ^
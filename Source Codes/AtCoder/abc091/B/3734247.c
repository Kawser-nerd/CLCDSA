#include <stdio.h>

int main(void){
  int N, M;
  char s[100][10] = {};//?????
  char t[100][10] = {};//?????
  int i, j, k;
  int max = -1000;
  int count;
  int flag;

  scanf("%d", &N);
  for(i = 0; i < N; i++){
    scanf("%s", &s[i][0]);
  }
  scanf("%d", &M);
  for(i = 0; i < M; i++){
    scanf("%s", &t[i][0]);
  }

  for(i = 0; i < N; i++){
    //???????????s[i][]???
    count = 0;
    for(j = 0; j < N; j++){
      //s[i][]?s[j][]?????????
      flag = 1;
      for(k = 0; k < 10; k++){
        if(s[i][k] != s[j][k]){
          flag = 0;
          break;
        }
      }
      //???flag == 1????s[i][]?s[j][]???
      if(flag == 1){
        count++;
      }
    }
    for(j = 0; j < M; j++){
      //s[i][]?t[j][]?????????
      flag = 1;
      for(k = 0; k < 10; k++){
        if(s[i][k] != t[j][k]){
          flag = 0;
          break;
        }
      }
      //???flag == 1????s[i][]?t[j][]???
      if(flag == 1){
        count--;
      }
    }
    if(count > max){
      max = count;
    }
  }

  for(i = 0; i < M; i++){
    //???????????t[i][]???
    count = 0;
    for(j = 0; j < N; j++){
      //t[i][]?s[j][]?????????
      flag = 1;
      for(k = 0; k < 10; k++){
        if(t[i][k] != s[j][k]){
          flag = 0;
          break;
        }
      }
      //???flag == 1????t[i][]?s[j][]???
      if(flag == 1){
        count++;
      }
    }
    for(j = 0; j < M; j++){
      //t[i][]?t[j][]?????????
      flag = 1;
      for(k = 0; k < 10; k++){
        if(t[i][k] != t[j][k]){
          flag = 0;
          break;
        }
      }
      //???flag == 1????t[i][]?t[j][]???
      if(flag == 1){
        count--;
      }
    }
    if(count > max){
      max = count;
    }
  }

  if(max < 0){
    max = 0;
  }

  printf("%d\n", max);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", &s[i][0]);
     ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &M);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", &t[i][0]);
     ^
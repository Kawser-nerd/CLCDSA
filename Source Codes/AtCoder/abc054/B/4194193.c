#include<stdio.h>

int main(){
  int N, M, i, j , k , l, flag;
  char A[50][51], B[50][51];
  
  scanf("%d %d", &N, &M);
  for (i = 0; i < N; i++){
    scanf("%s", A[i]);
  }
  for (i = 0; i < M; i++){
    scanf("%s", B[i]);
  }
  
  for (i = 0; i <= N - M; i++){
    for (j = 0; j <= N - M; j++){
      flag = 1;
      for (k = i; k < i + M; k++){
        for (l = j; l < j + M; l++){
          if(A[k][l] != B[k - i][l - j]){
            printf("\n");
            flag = 0;
            break;
          }
        }
        if(flag == 0){
          break;
        }
      }
      if(k == i + M && l == j + M){
        break;
      }
    }
    if(k == i + M && l == j + M){
      break;
    }
  }
  
  if(k == i + M && l == j + M){
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &M);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", A[i]);
     ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", B[i]);
     ^
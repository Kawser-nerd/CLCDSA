#include<stdio.h>
#include<string.h>

char list[100][11], p = 0; 
int check(char*s){
  int i;
  for (i = 0; i < p; i++){
    if(strcmp(s, list[i]) == 0){
      return 0;
    }
  }
  strcpy(list[p++], s);
  return 1;
}

int main(){
  int N, len, flag = 1;
  char W[100][11];
  
  scanf("%d", &N);
  for (int i = 0; i < N; i++){
    scanf("%s", W[i]);
    if(i > 0){
      if(W[i][0] != W[i - 1][len - 1]){
        flag = 0;
      }
    }
    len = strlen(W[i]);
    if(check(W[i]) == 0){
      flag = 0;
    }
  }
  
  if(flag == 1){
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", W[i]);
     ^
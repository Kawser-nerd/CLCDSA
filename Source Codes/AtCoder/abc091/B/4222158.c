#include<stdio.h>
#include<string.h>

char list[200][11], p = 0;
int check(char *s){
  int i;
  for (i = 0; i < p; i++){
    if(strcmp(list[i], s) == 0){
      return i;
    }
  }
  strcpy(list[i], s);
  p++;
  return i;
}

int main(){
  int N, M, count[201] = {0}, max = -100, q;
  char s[11];
  
  scanf("%d", &N);
  for (int i = 0; i < N; i++){
    scanf("%s",s);
    count[check(s)]++;
  }
  scanf("%d", &M);
  for (int i = 0; i < M; i++){
    scanf("%s", s);
    count[check(s)]--;
  }
  
  for (int i = 0; i < 200; i++){
    if(max < count[i]){
      max = count[i];
    }
  }
  
  printf("%d\n", max);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &M);
   ^
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^
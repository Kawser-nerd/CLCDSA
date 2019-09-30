#include<stdio.h>

int main(){
  int N;
  scanf("%d", &N);
  
  if(N >= 64){
    printf("64\n");
  } else if(N >= 32){
    printf("32\n");
  } else if(N >= 16){
    printf("16\n");
  } else if(N >= 8){
    printf("8\n");
  } else if(N >= 4){
    printf("4\n");
  } else if(N >= 2){
    printf("2\n");
  } else {
    printf("1\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
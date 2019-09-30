#include<stdio.h>
#include<string.h>

int main(){
  int i,j,k=0;
  char A[256];
  scanf("%s",A);
  
  for(i=0;i<strlen(A);i++){
    k += A[i] - '0';
  }
  
  if(atoi(A)%k == 0){
    puts("Yes");
    return 0;
  }
  
  else
    puts("No");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:6: warning: implicit declaration of function ‘atoi’ [-Wimplicit-function-declaration]
   if(atoi(A)%k == 0){
      ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",A);
   ^
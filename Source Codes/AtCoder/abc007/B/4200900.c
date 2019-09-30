#include <stdio.h>

int main(){
  int i=0,n;
  char A[10];
  scanf("%s",A);
  while(A[i]!=NULL){
    i++;
  }
  n=i;
  if(n==1 && A[0]=='a'){
    printf("-1\n");
    return 0;
  }
  printf("a\n");
} ./Main.c: In function ‘main’:
./Main.c:7:13: warning: comparison between pointer and integer
   while(A[i]!=NULL){
             ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",A);
   ^
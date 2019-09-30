#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
  int i,j,k=0;
  
  char N[256];
  
  scanf("%s",N);
  
  for(i=0;i<strlen(N);i++){
    k += (N[i] - '0');
  }
  
  j = atoi(N);
  
  if(j%k == 0)
    puts("Yes");
  
  else
    puts("No");
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",N);
   ^
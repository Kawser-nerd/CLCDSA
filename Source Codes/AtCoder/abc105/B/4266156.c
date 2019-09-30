#include<stdio.h>

int main(){
  int N,i,j,k;
  
  scanf("%d",&N);
  
  for(i = 0;i <= N;i+=7){
    j = N - i;
    if(j % 4 == 0){
      puts("Yes");
      return 0;
    }
  }
  puts("No");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
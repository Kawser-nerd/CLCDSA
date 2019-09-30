#include<stdio.h>
#include<math.h>

int main(){
  int i=1;
  int N;
  
  scanf("%d",&N);
  
  while(1){
    if(i*i > N){
      printf("%d\n",(i-1)*(i-1));
      return 0;
    }
    i++;
  }
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
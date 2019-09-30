#include<stdio.h>
#include<math.h>

int main(){
  int i,j,k=0;
  int N;
  scanf("%d",&N);
  for(i=1;i<=N;i++){
    for(j=2;j <1000;j++){
      if(N < pow(i,j))
        break;
      if(k < pow(i,j))
        k=pow(i,j);
    }
  }
  
  printf("%d\n",k);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
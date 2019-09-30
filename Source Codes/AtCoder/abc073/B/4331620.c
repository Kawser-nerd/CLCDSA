#include<stdio.h>
#include<math.h>

int main(){
  int i,j,k=0;
  int N;
  int a,b;
  scanf("%d",&N);
  
  for(i=0;i<N;i++){
    scanf("%d %d",&a,&b);
    k += (b-a+1);
    }
    
    printf("%d\n",k);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a,&b);
     ^
#include<stdio.h>
#include<math.h>

int main(){
  int i,j,k=0;
  int N,T,A;
  double min=10000000000;
  
  scanf("%d",&N);
  scanf("%d %d",&T,&A);
  int H[N];
  for(i=0;i<N;i++)
    scanf("%d ",&H[i]);
  double x;
  for(i=0;i<N;i++){
    x =  T - H[i] * 0.006 - A;
    if(fabs(x) < min){
      min = fabs(x);
      k = i;
    }
  }
  
  printf("%d\n",k+1);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&T,&A);
   ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d ",&H[i]);
     ^
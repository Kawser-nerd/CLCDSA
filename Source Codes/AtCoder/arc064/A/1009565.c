#include<stdio.h>

int main(){
  long ans = 0;
  int N,x;
  scanf("%d %d", &N, &x);
  int A[N];
  for(int i = 0;i < N;i++){
    scanf("%d",&A[i]);
  }
  for(int i = 0;i<N-1;i++){
    int sa = A[i]+A[i+1] - x;
    if(sa > 0){
      ans += sa;
      if(A[i+1]>=sa){
        A[i+1]-=sa;
      }else{
        A[i+1]=0;
      }
    }
  }
printf("%ld",ans);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &x);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A[i]);
     ^
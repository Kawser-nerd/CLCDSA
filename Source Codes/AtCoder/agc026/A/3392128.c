#include <stdio.h>

int main(){
  int N;
  scanf("%d",&N);
  int i;
  int A[N];
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  int ans=0;
  int k=1;
  for(i=1;i<N;i++){
    if(A[i]==A[i-1]){
      k++;
    }else{
      ans=ans+(int)(k/2);
      k=1;
    }
  }
  ans=ans+(int)(k/2);
  printf("%d",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A[i]);
     ^
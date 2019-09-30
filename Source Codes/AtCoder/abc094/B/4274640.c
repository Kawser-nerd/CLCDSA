#include<stdio.h>

int main(){
  int i,j=0,k=0,s;
  int N,M,X;
  scanf("%d %d %d",&N,&M,&X);
  int A[M];
  for(i=0;i<M;i++)
    scanf("%d ",&A[i]);
  
  for(i = X;i!=0;i--){
    for(s=0;s<M;s++){
      if(i == A[s])
        j++;
    }
  }
  
  for(i=X;i<=N;i++){
    for(s=0;s<M;s++){
      if(i==A[s])
        k++;
    }
  }
  
  if(j > k)
    printf("%d\n",k);
  else
    printf("%d\n",j);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&N,&M,&X);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d ",&A[i]);
     ^
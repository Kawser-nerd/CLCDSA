#include<stdio.h>
#include<math.h>
int main()
{
  int N,i,j;
  scanf("%d",&N);
  
  if(N%2==0){
    printf("%d\n",N*(N-2)/2);
    
    for(i=1;i<=N-1;i++){
      for(j=i+1;j<=N;j++){
        if((i+j)!=(N+1)){
          printf("%d %d\n",i,j);
        }
      }
    }
    
  } else {
        printf("%d\n",((N-1)*(N-3)/2 + (N-1)));
    
    for(i=1;i<=N-2;i++){
      for(j=i+1;j<=N-1;j++){
        if((i+j)!=N){
          printf("%d %d\n",i,j);
        }
      }
    }
    for(i=1;i<=N-1;i++){
      printf("%d %d\n",i,N);
    }
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
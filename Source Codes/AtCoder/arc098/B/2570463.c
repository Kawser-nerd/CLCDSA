#include <stdio.h>

int main(){
  int N;
  int A[300000]={0};
  long long int xorA[300000]={0};
  long long int sumA[300000]={0};
  int index=1;
  long long int count=0;
  
  scanf("%d",&N);
  for(int i=1;i<=N;i++)
    scanf("%d",&A[i]);

  for(int i=1;i<=N;i++){
    sumA[i]=sumA[i-1]+A[i];
    xorA[i]=xorA[i-1]^A[i];
    for(int j=index;j<=i;j++,index++)
      if((sumA[i]-sumA[j-1])==(xorA[i]^xorA[j-1]))
	break;
    count+=(i-index)+1;
  }

  printf("%lld\n",count);
  return 0;
    
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A[i]);
     ^
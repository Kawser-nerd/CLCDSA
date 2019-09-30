#include<stdio.h>

int main(void){
  int N;
  int A[100000]={0};
  short nums[100000]={0};
  int i,j,k;
  const int mod=(int)1E9+7;

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
    nums[A[i]]++;
  }
  
  for(i=0;i<N;i++){
    if(i%2==N%2 && nums[i]!=0){
      puts("0");
      return 0;
    }else if(i%2!=N%2 && ((i!=0 && nums[i]!=2) || (i==0 && nums[i]!=1))){
      puts("0");
      return 0;
    }
  }

  k=1;
  N/=2;
  for(i=0;i<N;i++){
    k*=2;
    k%=mod;
  }
  printf("%d\n",k);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A[i]);
     ^
#include <stdio.h>
#define mod 1000000007

int num(int N){
  if(N<0){
    return 1;
  }
  int n[7]={1,2,3,5,8,13,21};  
  return n[N];
}
  
int main(){
  int H,W,K,i,j;
  scanf("%d%d%d",&H,&W,&K);
  long long int A[W+1][H+1];
  A[1][0]=1;
  if(W==1){
    printf("1");
    return 0;
  }
  
  for(i=2;i<=W;i++){
    A[i][0]=0;
  }
  
  for(i=1;i<=H;i++){
    A[W][i]=(num(W-2)*A[W][i-1]+num(W-3)*A[W-1][i-1])%mod;
    A[1][i]=(num(W-2)*A[1][i-1]+num(W-3)*A[2][i-1])%mod;
    if(W>=3){
      for(j=2;j<=W-1;j++){
	A[j][i]=(num(j-3)*num(W-j-1)*A[j-1][i-1]+num(j-2)*num(W-j-1)*A[j][i-1]+num(j-2)*num(W-j-2)*A[j+1][i-1])%mod;
      }
    }
  }
  
  printf("%lld",A[K][H]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&H,&W,&K);
   ^
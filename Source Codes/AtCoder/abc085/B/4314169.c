#include<stdio.h>

int main(){
  int N;
  scanf("%d",&N);
  
  int i,j,k,A[N];
 for(i=0;i<N;i++)
   scanf("%d",&A[i]);
  
  for (i=0; i<N; ++i) {
    for (j=i+1; j<N; ++j) {
      if (A[i] > A[j]) {
        k =  A[i];
        A[i] = A[j];
        A[j] = k;
      }
    }
  }

  int ans=1;
  
  for(i=1;i<N;i++){
    if(A[i] != A[i-1])
      ans++;
  }
  printf("%d\n",ans);
  return 0;} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:9:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&A[i]);
    ^
#include<stdio.h>
#include<string.h>
int main(void) {
  int N,B[100],i,j,ans=0,M[100],A[100];
  for(i=0;i<100;i++)M[i]=0;
  scanf("%d",&N);
  for(i=0;i<N;i++)scanf("%d",&B[i]);
  for(i=0;i<N;i++) {
    if(B[i] > i+1)ans++;
  }
  if(ans)printf("%d\n",-1);
  else {
    for(i=0;i<N+1;i++) {
      for(j=0;j<N-i;j++) {
        if(B[j] == j+1) {
          M[i]=j+1;
        }
      }
      for(j=M[i]-1;j<N-i-1;j++) {
        B[j] = B[j+1];
      }
    }
    for(i=N-1;i>-1;i--)printf("%d\n",M[i]);
  }
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:7:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<N;i++)scanf("%d",&B[i]);
                   ^
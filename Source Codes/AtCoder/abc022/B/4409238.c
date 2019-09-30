#include <stdio.h>

int main(void){
  int N;
  scanf("%d",&N);

  int a,ans = 0;
  int A[100000];
  for(int i = 0;i < 100000;i++) A[i] = 0;
  for(int i = 0;i < N;i++){
    scanf("%d",&a);
    if(A[a-1]) ans++;
    A[a-1]++;
  }

  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^
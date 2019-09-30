#include <stdio.h>

int main(void){
  int N,Q;
  scanf("%d%d",&N,&Q);

  int r,l;
  int data[N+1];
  for(int i = 0;i < N+1;i++) data[i] = 0;
  for(int i = 0;i < Q;i++){
    scanf("%d%d",&l,&r);
    data[l-1]++;
    data[r]--;
  }

  int sum,psum;
  for(int i = 0;i < N;i++){
    if(i == 0) sum = data[i];
    else sum = psum+data[i];
    printf("%d",sum%2);
    psum = sum;
  }
  printf("\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&Q);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&l,&r);
     ^
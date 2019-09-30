#include<stdio.h>

int main (void) {

  int N,T;
  int t[200010];
  int i;

  scanf("%d %d",&N,&T);
  for (i=0;i<N;i++) {
    scanf("%d",&t[i]);
  }

  int sum = 0;
  int tmp = 0;
  for (i=0;i<N;i++) {
    if(t[i]>=tmp){
      sum += T;
    } else {
      sum -= tmp - t[i];
      sum += T;
    }
    tmp = t[i] + T;
  }

  printf("%d\n",sum);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&N,&T);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&t[i]);
     ^
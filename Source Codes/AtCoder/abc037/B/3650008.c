#include <stdio.h>

int main(void){
  int N,Q,L,R,T;
  int seq[101] = {};
  scanf("%d%d",&N,&Q);
  for(int i=0; i<Q; i++) {
    scanf("%d%d%d",&L,&R,&T);
    for(int j=L-1; j<=R-1; j++) {
      seq[j]=T;
    }
  }
  for(int i=0; i<N; i++) {
    printf("%d\n",seq[i]);
  }
  return 0;  
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&Q);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&L,&R,&T);
     ^
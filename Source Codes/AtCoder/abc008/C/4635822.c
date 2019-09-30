#include <stdio.h>

int main(void){
  int N;
  scanf("%d",&N);

  int C[N];
  for(int i = 0;i < N;i++){
    scanf("%d",&C[i]);
  }

  double ans = 0;
  for(int i = 0;i < N;i++){
    int S = 0;
    for(int j = 0;j < N;j++){
      if(i == j) continue;
      if(C[i]%C[j] == 0) S++;
    }
    if(S%2 == 0) ans += (double)(S+2)/(2*S+2);
    else ans += (double)1/2;
  }
   
  printf("%.9lf\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&C[i]);
     ^
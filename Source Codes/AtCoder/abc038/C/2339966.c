#include<stdio.h>
int main (void){
  int N;
  int aN[100000]={};
  long long int score=0;
  int plus=0;
  scanf("%d",&N);
  for(int i=0; i<N; i++){
    scanf("%d",&aN[i]);
    score++;
  }
  for(int i=1; i<N; i++){
    if(aN[i-1] < aN[i]){
      plus++;
      score += plus;
    }
    else
      plus = 0;
  }
  printf("%lld\n",score);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&aN[i]);
     ^
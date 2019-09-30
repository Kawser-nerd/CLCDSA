#include <stdio.h>
#define INF 1 << 29

int min(int a,int b){
  if(a < b){
    return a;
  }
  return b;
}

int main(void){
  int N;
  scanf("%d",&N);

  int MIN = INF;
  int t;
  for(int i = 0;i < N;i++){
    scanf("%d",&t);
    MIN = min(t,MIN);
  }

  printf("%d\n",MIN);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&t);
     ^
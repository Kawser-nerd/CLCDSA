#include <stdio.h>

int min(int a,int b){
  if(a < b){
    return a;
  }
  return b;
}

int main(void){
  int N,M;
  scanf("%d%d",&N,&M);

  int l,r,s;
  int point[M+1];
  int ans = 0;
  for(int i = 0;i <= M;i++) point[i] = 0;
  for(int i = 0;i < N;i++){
    scanf("%d%d%d",&r,&l,&s);
    point[r-1] += s;
    point[l] -= s;
    ans += s;
  }

  int mini = point[0];
  for(int i = 1;i < M;i++){
    point[i] += point[i-1];
    mini = min(mini,point[i]);
  }
  printf("%d\n",ans-mini);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&r,&l,&s);
     ^
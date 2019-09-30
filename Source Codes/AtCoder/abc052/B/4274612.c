#include <stdio.h>

int max(int a,int b){
  if(a > b){
    return a;
  }
  return b;
}

int main(void){
  int N;
  scanf("%d",&N);

  char S[N];
  scanf("%s",S);

  int num = 0;
  int ans = 0;
  for(int i = 0;i < N;i++){
    if(S[i] == 'I')
      num++;
    else
      num--;
    ans = max(ans,num);
  }

  printf("%d\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^
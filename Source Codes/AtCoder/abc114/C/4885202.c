#include <stdio.h>

long N;
int ans = 0;

void dfs(long num,int a,int b,int c){
  if(num > N) return;
  if(a && b && c) ans++;
  dfs(num*10+3,1,b,c);
  dfs(num*10+5,a,1,c);
  dfs(num*10+7,a,b,1);
}

int main(void){
  scanf("%ld",&N);

  dfs(0,0,0,0);

  printf("%d\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&N);
   ^
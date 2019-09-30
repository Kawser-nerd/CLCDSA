#include <stdio.h>

int ans = 0;
long N;
int keta;

void dfs(int limit,int n,int a,int b,int c){
  if(limit == -1) return ;
  if(n <= N){
    if(a && b && c) ans++;
  }

  dfs(limit-1,n*10+3,1,b,c);
  dfs(limit-1,n*10+5,a,1,c);
  dfs(limit-1,n*10+7,a,b,1);
}


int main(void){
  scanf("%ld",&N);
  long i = N;
  while(i > 0){
    i /= 10;
    keta++;
  }

  dfs(keta,0,0,0,0);
  printf("%d\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&N);
   ^
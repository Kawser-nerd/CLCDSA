#include <stdio.h>

int N;
int ans = 0;

void dfs(int limit,int num,int a,int b,int c){
  if(limit == 0) return;
  if(num <= N){
    if(a && b && c) ans++;
    dfs(limit-1,num*10+3,1,b,c);
    dfs(limit-1,num*10+5,a,1,c);
    dfs(limit-1,num*10+7,a,b,1);
  }
}

int main(void){
  scanf("%d",&N);
  int tmp = N;
  int cnt = 0;
  while(tmp > 0) tmp /= 10,cnt++;

  dfs(cnt+1,0,0,0,0);

  printf("%d\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
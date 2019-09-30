#include <stdio.h>

int N,sum=0;

void dfs(long long int tmp, int flag) {
  if (tmp > N) return;
  if (tmp <= N && flag == 7) sum++;
  dfs(tmp*10+3,flag|1);
  dfs(tmp*10+5,flag|2);
  dfs(tmp*10+7,flag|4);
}

int main() {
  scanf("%d",&N);
  dfs(0,0);
  printf("%d\n",sum);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
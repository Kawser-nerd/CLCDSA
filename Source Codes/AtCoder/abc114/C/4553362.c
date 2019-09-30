#include <stdio.h>
#include <stdlib.h>
#define ll long long int
int n,sum=0;

void dfs(ll tmp,int flag){
	if(tmp > n) return;
	if(tmp<=n && flag==7) sum++;
	dfs(tmp*10 + 3, flag|1);
	dfs(tmp*10 + 5, flag|2);
	dfs(tmp*10 + 7, flag|4);
}

int main(void){
	scanf("%d",&n);
	dfs(0,0);
	printf("%d",sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
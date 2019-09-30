#include <stdio.h>
int min(int x, int y){return x<y?x:y;}
int max(int x, int y){return x<y?y:x;}
int main(void){
	int n,i,b[21],maxS[21],minS[21],S[21];
	scanf("%d",&n);
	for(i=2;i<=n;i++)scanf("%d",&b[i]);
	b[1] = 1;
	for(i=1;i<=n;i++){maxS[i]=0;minS[i]=1e9;}
	for(i=n;i>=1;i--){
		if(maxS[i]==0)S[i]=1;
		else S[i] = maxS[i]+minS[i]+1;
		maxS[b[i]] = max(maxS[b[i]],S[i]);
		minS[b[i]] = min(minS[b[i]],S[i]);
	}
	
	
	printf("%d\n",S[1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:7:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=2;i<=n;i++)scanf("%d",&b[i]);
                   ^
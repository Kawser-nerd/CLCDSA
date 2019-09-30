#include<stdio.h>

int main(){
	int n,i,ab[2],col[1000002]={0},ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&ab[0],&ab[1]);
		col[ab[0]]++;
		col[ab[1]+1]--;
	}
	for(i=1;i<=1000000;i++)col[i]+=col[i-1];
	for(i=0;i<=1000000;i++){
		if(ans<col[i])ans=col[i];
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&ab[0],&ab[1]);
   ^
#include<stdio.h>

int main(){
		int n,m,i,j,ab[50][2],ans[51]={0};
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)scanf("%d%d",&ab[i][0],&ab[i][1]);
		for(j=1;j<=n;j++){
				for(i=0;i<m;i++){
						if(ab[i][0]==j||ab[i][1]==j)ans[j]++;
				}
		}
		for(i=1;i<=n;i++)printf("%d\n",ans[i]);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:6:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<m;i++)scanf("%d%d",&ab[i][0],&ab[i][1]);
                   ^
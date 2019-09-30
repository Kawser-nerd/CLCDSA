#include <stdio.h>

int p[15];
int c[15];
int used[15];
int D,G;
int ans;

void dfs(int depth){

	int i,j;

	if(depth==D){

		int cnt=0;
		int sum=0;

		for(i=0;i<D;i++){
			if(used[i]==1){
				cnt+=p[i];
				sum+=(100*(i+1)*p[i])+c[i];
			}
		}
		if(sum>=G){
			if(ans>cnt){ans=cnt;}
		}

		for(i=D-1;i>=0;i--){
			if(used[i]==0){
				for(j=0;j<p[i];j++){
					if(sum>=G){
						if(ans>cnt){ans=cnt;}
					}
					sum+=100*(i+1);
					if(j==p[i]-1){sum+=c[i];}
					cnt++;
				}
			}
		}
		return;
	}

	used[depth]=1;
	dfs(depth+1);
	used[depth]=0;
	dfs(depth+1);
}

int main(){


	scanf("%d %d",&D,&G);

	int i;

	for(i=0;i<D;i++){
		scanf("%d %d",&p[i],&c[i]);
	}

	ans=114514;

	dfs(0);

	printf("%d\n",ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:52:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&D,&G);
  ^
./Main.c:57:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&p[i],&c[i]);
   ^
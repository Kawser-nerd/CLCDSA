#include <stdio.h>

int d[15][15];
int N;
int ans;
int route[10];
int used[10];

void dfs(int depth,int pos){

	int i;

	if(depth==N){

		int flag=0;

		if(route[0]!=1){flag=1;}

		for(i=0;i<N-1;i++){
			if(flag==1){break;}
			if(d[route[i]][route[i+1]]==0){
				flag=1;
			}
		}
		if(flag==0){
			ans++;
		}
		return;
	}

	for(i=1;i<=N;i++){
		if(used[i]==0){
			used[i]=1;
			route[depth]=i;
			dfs(depth+1,i);
			used[i]=0;
		}
	}

}

int main(){


	int M;

	scanf("%d %d",&N,&M);

	int i;

	for(i=0;i<M;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		d[a][b]=1;
		d[b][a]=1;
	}

	dfs(0,1);

	printf("%d\n",ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:47:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&M);
  ^
./Main.c:53:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^
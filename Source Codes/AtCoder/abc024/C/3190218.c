#include <stdio.h>

int ans;
int N,D,K;
int L[10005];
int R[10005];

int max(int a,int b){
	if(a>b){return a;}
	else{return b;}
}
int min(int a,int b){
	if(a<b){return a;}
	else{return b;}
}

void dfs(int depth,int left,int right,int goal){

	if(left<=goal&&goal<=right){
	ans=min(ans,depth);
	}

	if(depth==D){return;}

	if(left>R[depth] || right<L[depth]){
	dfs(depth+1,left,right,goal);
	}
	else{
	dfs(depth+1,min(left,L[depth]),max(right,R[depth]),goal);
	}
}

int main(){

	scanf("%d %d %d",&N,&D,&K);

	int i,j;

	for(i=0;i<D;i++){
	scanf("%d %d",&L[i],&R[i]);
	}
	
	for(i=0;i<K;i++){
	int Si,Ti;
	scanf("%d %d",&Si,&Ti);
	ans=114514;
	dfs(0,Si,Si,Ti);
	printf("%d\n",ans);
	}

return 0;
} ./Main.c: In function ‘main’:
./Main.c:35:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&N,&D,&K);
  ^
./Main.c:40:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&L[i],&R[i]);
  ^
./Main.c:45:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&Si,&Ti);
  ^
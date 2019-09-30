#include <stdio.h>

int N,M,R;
int r[8];
int d[205][205];
int ans;
int per[8];
int used[8];

int min(int a,int b){
	if(a<b){return a;}
	else{return b;}
}

void warshall_floyd(){
	int i,j,k;

	for(k=1;k<=N;k++){
		for(i=1;i<=N;i++){
			for(j=1;j<=N;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}

}

void dfs(int depth){

	int i;

	if(depth==R){


		int cost=0;

		for(i=0;i<R-1;i++){
			int from=r[per[i]-1];
			int to=r[per[i+1]-1];
			cost+=d[from][to];
		}

		if(ans>cost){ans=cost;}

		return ;
	}

	for(i=0;i<R;i++){

	if(used[i]==0){
		per[depth]=i+1;
		used[i]=1;
		dfs(depth+1);
		used[i]=0;
		}
	}
}

int main(){

	scanf("%d %d %d",&N,&M,&R);

	int i,j;

	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			if(i==j){d[i][j]=0;}
			else{d[i][j]=1<<25;}
		}
	}


	for(i=0;i<R;i++){
		scanf(" %d",&r[i]);
	}
	for(i=0;i<M;i++){
		int A,B,C;
		scanf("%d %d %d",&A,&B,&C);
		d[A][B]=C;
		d[B][A]=C;
	}

	warshall_floyd();

	ans=1<<30;

	dfs(0);

	printf("%d\n",ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:61:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&N,&M,&R);
  ^
./Main.c:74:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf(" %d",&r[i]);
   ^
./Main.c:78:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&A,&B,&C);
   ^
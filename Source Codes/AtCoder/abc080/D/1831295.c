#include <stdio.h>

int N;
int C;
int s[100005];
int t[100005];
int c[100005];

int T[31][100005];

int main(){

	scanf("%d %d",&N,&C);

	int i,j;

	for(i=0;i<N;i++){
	scanf("%d %d %d",&s[i],&t[i],&c[i]);
	}

	for(i=0;i<N;i++){
		for(j=s[i];j<=t[i];j++){
			if(T[c[i]][j]==0){
			T[c[i]][j]=1;
			}
		}
	}

	int ans=0;

	for(i=0;i<100005;i++){
	int cnt=0;
	for(j=1;j<=C;j++){
	cnt+=T[j][i];
	}
	if(ans<cnt){ans=cnt;}
	}


	printf("%d\n",ans);

return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&C);
  ^
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&s[i],&t[i],&c[i]);
  ^
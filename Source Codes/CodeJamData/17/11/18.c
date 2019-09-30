#include<stdio.h> 
char map[30][30],ans[30][30];
void DO(int n,int m){
	int i,j,k;
	for(i=0;i<n+1;i++)
		for(j=0;j<m+1;j++)
			ans[i][j]=0;
	for(i=0;i<n;i++){
		for(j=0,k=0;j<m;j++){
			if(map[i][j]=='?')
				continue;
			for(;k<=j;k++)
				ans[i][k]=map[i][j];
		}
		if(k!=0){
			for(j=k-1;k<m;k++)
				ans[i][k]=map[i][j];
		}
	}
	for(j=0;j<m;j++){
		for(i=0,k=0;i<n;i++){
			if(ans[i][j]==0)
				continue;
			for(;k<=i;k++)
				ans[k][j]=ans[i][j];
		}
		for(i=k-1;k<n;k++)
			ans[k][j]=ans[i][j];
		
	}
}
int main(){
	int t,T,n,m,i;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%s",map[i]);
		DO(n,m);
		printf("Case #%d:\n",t);
		for(i=0;i<n;i++)
			puts(ans[i]);
	}
}

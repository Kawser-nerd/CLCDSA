#include<stdio.h> 
int a[5];
int dp[5][110][110][110][4]={};
int DO2(){
	int i,j,k,x;
	for(i=0;i<=100;i++){
		for(x=0;x<2;x++){
			if(i&&dp[2][i][0][0][x]<dp[2][i-1][0][0][(x+1)%2])
				dp[2][i][0][0][x]=dp[2][i-1][0][0][(x+1)%2];
			if(x==0&&i)
				dp[2][i][0][0][x]++;
		}
		
	}
}
int DO3(){
	int i,j,k,x;
	for(i=0;i<=100;i++){
		for(j=0;j<=100;j++){
			for(k=0;k<=0;k++){
				for(x=0;x<3;x++){
					if(i&&dp[3][i][j][k][x]<dp[3][i-1][j][k][(x+1)%3])
						dp[3][i][j][k][x]=dp[3][i-1][j][k][(x+1)%3];
					if(j&&dp[3][i][j][k][x]<dp[3][i][j-1][k][(x+2)%3])
						dp[3][i][j][k][x]=dp[3][i][j-1][k][(x+2)%3];
					if(x==0&&i+j)
						dp[3][i][j][k][x]++;
				}
				
			}
		}
	}
}
int DO4(){
	int i,j,k,x;
	for(i=0;i<=100;i++){
		for(j=0;j<=100;j++){
			for(k=0;k<=100;k++){
				for(x=0;x<4;x++){
					if(i&&dp[4][i][j][k][x]<dp[4][i-1][j][k][(x+1)%4])
						dp[4][i][j][k][x]=dp[4][i-1][j][k][(x+1)%4];
					if(j&&dp[4][i][j][k][x]<dp[4][i][j-1][k][(x+2)%4])
						dp[4][i][j][k][x]=dp[4][i][j-1][k][(x+2)%4];
					if(j&&dp[4][i][j][k][x]<dp[4][i][j][k-1][(x+3)%4])
						dp[4][i][j][k][x]=dp[4][i][j][k-1][(x+3)%4];
					if(x==0&&i+j+k)
						dp[4][i][j][k][x]++;
				}
				
			}
		}
	}
}
int main(){
	int t,T,n,m,i,x,ans;
	DO2();
	DO3();
	DO4();
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d%d",&n,&m);
		for(i=0;i<5;i++)
			a[i]=0;
		for(i=0;i<n;i++){
			scanf("%d",&x);
			x=x%m;
			a[x]++;
		}
		printf("Case #%d: %d\n",t,a[0]+dp[m][a[1]][a[2]][a[3]][0]);
		
	}
}

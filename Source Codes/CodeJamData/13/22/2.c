#include <stdio.h>
#include <string.h>
#define MAX(u,v) (((u)>(v))?(u):(v))
#define MIN(u,v) (((u)<(v))?(u):(v))
double dp[4000][2000];

int main(){
	int t,n,x,y,k,p,q,i,j;
	double r;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		scanf("%d%d%d",&n,&x,&y);
		if(x<0)x=-x;
		p=(x+y)/2;i=0;
		while(n-(4*i+1)>=0){
			n-=(4*i+1);i++;
		}
		q=i;
		if(p<q){r=1.0;goto END;}
		if(p>q){r=0.0;goto END;}
		if(x==0){r=0.0;goto END;}
		/*if(y<=n-q*2-1){r=1.0;goto END;}
		if(y>n){r=0.0;goto END;}*/
		//for(i=0;i<1000;i++)for(j=0;j<2000;j++)dp[i][j]=0.0;
		memset(dp,0,sizeof(dp));
		dp[0][0]=1.0;
		for(i=0;i<n;i++){
			for(j=MAX(0,i-q*2);j<=MIN(q*2,i);j++){
				if(i-j>=q*2)dp[i+1][j+1]+=dp[i][j];
				else if(j==q*2)dp[i+1][j]+=dp[i][j];
				else{
					dp[i+1][j]+=dp[i][j]*0.5;
					dp[i+1][j+1]+=dp[i][j]*0.5;
				}
			}
		}
		r=0.0;
		for(j=0;n-j>y;j++){
			r+=dp[n][j];
		}
		END:
		printf("Case #%d: %.8lf\n",k,r);
	}
	return 0;
}

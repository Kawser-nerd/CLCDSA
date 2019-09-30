#include<stdio.h>

#define min(a,b) ((a)<(b)?(a):(b))

/*int solve(int kai,long now){
	if(kai>=ans)return 0;
	if(now>n)return 0;
	if(n-now>=0&&n-now<6){
		if(ans>kai+n-now)ans=kai+n-now;
		return 0;
	}else {
		if(n-now>=0&&ans>kai+n-now)ans=kai+n-now;
		printf("%ld\n",ans);
		if(n-now>=59049)solve(kai+1,now+59049);
		if(n-now>=46656)solve(kai+1,now+46656);
		if(n-now>=7776)solve(kai+1,now+7776);
		if(n-now>=6561)solve(kai+1,now+6561);
		if(n-now>=1296)solve(kai+1,now+1296);
		if(n-now>=729)solve(kai+1,now+729);
		if(n-now>=216)solve(kai+1,now+216);
		if(n-now>=81)solve(kai+1,now+81);
		if(n-now>=36)solve(kai+1,now+36);
		if(n-now>=9)solve(kai+1,now+9);
		if(n-now>=6)solve(kai+1,now+6);
		//solve(kai+1,now+2799366);
		//solve(kai+1,now+531441);
		return 0;
	}
}*/

int ru(int a,int b){
	int r=1,i;
	for(i=0;i<b;i++)r=r*a;
	return r;
}

int main(){
	int n;
	scanf("%d",&n);
	int dp[100001],i,j;
	for(i=0;i<6;i++)dp[i]=i;
	//solve(0,0);
	for(i=6;i<=n;i++){
		for(j=0;ru(6,j)<=i;j++)dp[i]=min(dp[i-1]+1,dp[i-ru(6,j)]+1);
		for(j=0;ru(9,j)<=i;j++)dp[i]=min(dp[i-1]+1,min(dp[i-ru(9,j)]+1,dp[i]));
	}
	printf("%d\n",dp[n]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:39:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define HELL (1000000007)
#define MIN(p,q) (((p)<(q))?(p):(q))
int a[1008];
int sorted[1008];
int dp[1008][1008];
int bit[1008];
int n;

int comp(const void *p,const void *q){
	return *(int *)p-*(int *)q;
}

int sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=(i&(-i));
	}
	return s;
}
void add(int i,int x){
	while(i<=n){
		bit[i]+=x;
		i+=(i&(-i));
	}
}

int main(){
	int TT,T,i,j,mini;
	int tmp1,tmp2;
	scanf("%d",&T);
	for(TT=1;TT<=T;TT++){
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%d",&a[i]);
		memset(bit,0,sizeof(bit));
		memcpy(sorted,a,sizeof(sorted));
		qsort(sorted,n,4,comp);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(a[i]==sorted[j]){
					a[i]=j+1;break;
				}
			}
		}
		//for(i=0;i<n;i++)printf("%d ",a[i]);
		for(i=1;i<=n;i++)add(i,1);
		for(i=1;i<=n;i++){
			for(j=0;j<n;j++){
				if(a[j]==i){
					mini=j+1;
					break;
				}
			}
			tmp1=sum(n)-sum(mini);
			tmp2=sum(mini-1);
			//printf("(%d,%d,%d)",mini,tmp1,tmp2);
			dp[i][0]=dp[i-1][0]+tmp1;
			dp[i][i]=dp[i-1][i-1]+tmp2;
			for(j=1;j<i;j++){
				dp[i][j]=MIN(dp[i-1][j]+tmp1,dp[i-1][j-1]+tmp2);
			}
			add(mini,-1);
		}
		tmp1=HELL;
		for(i=0;i<=n;i++){
			if(tmp1>dp[n][i])tmp1=dp[n][i];
		}
		printf("Case #%d: %d\n",TT,tmp1);
	}
	return 0;
}

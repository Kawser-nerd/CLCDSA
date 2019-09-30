#include <stdio.h>
#include <string.h>
char dp[1048576][21],tmp[21];
int c[21],on[21],o[21][41],minu[21],b[201];
int nw[201];

int main(){
	int t,k,n,i,j,l,x,tmp,sl,r;
	scanf("%d",&t);
	for(l=1;l<=t;l++){
		memset(b,0,sizeof(b));
		memset(minu,0,sizeof(minu));
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&k,&n);
		for(i=0;i<k;i++){
			scanf("%d",&tmp);
			b[tmp]++;
		}
		for(i=0;i<n;i++){
			scanf("%d%d",&c[i],&on[i]);
			for(j=0;j<on[i];j++){
				scanf("%d",&o[i][j]);
				if(o[i][j]==c[i])minu[i]++;
			}
		}
		for(i=1;i<(1<<n);i++){
			memcpy(nw,b,sizeof(b));
			for(j=0;j<n;j++){
				if(i&(1<<j)){
					for(x=0;x<on[j];x++)nw[o[j][x]]++;
					nw[c[j]]--;
				}
			}
			dp[i][0]=(char)(n+1);r=n+1;
			for(j=0;j<n;j++){
				if(i&(1<<j)){
					if(nw[c[j]]+1-minu[j]>0){
						if(strcmp(dp[i],dp[i^(1<<j)])>0){
							strcpy(dp[i],dp[i^(1<<j)]);
							r=j+1;
						}
					}
				}
			}
			if(dp[i][0]==(char)(n+1))continue;
			sl=strlen(dp[i]);
			dp[i][sl]=(char)r;dp[i][sl+1]=0;
		}
		printf("Case #%d: ",l);
		if(dp[(1<<n)-1][0]==(char)(n+1))puts("IMPOSSIBLE");
		else{
			for(i=0;i<n;i++)printf("%d%c",(int)dp[(1<<n)-1][i],i==n-1?'\n':' ');
		}
	}
	return 0;
}
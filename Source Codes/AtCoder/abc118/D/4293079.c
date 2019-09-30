#include<stdio.h>

int main(){
	int n,m,i,a[10]={0},j,k,
	ans[10]={0},
	at[11]={10,2,5,5,4,5,6,3,7,6},
	aj[11]={0,1,7,4,3,2,9,5,6,8};
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		int ab;
		scanf("%d",&ab);
		a[ab]=1;
	}
	int min1[10],c=0;
	for(i=1;i<10;i++){
		//if(c==2)break;
		if(a[i]==1){
			min1[c]=i;
			c++;
		}
	}
	//for(i=0;i<c;i++)printf("%d\n",min1[i]);
	int dp[10001][10]={0};
	dp[0][0]=1;
	//for(i=0;i<c;i++)dp[min1[i]][0]=1;
	for(i=0;i<10001;i++){
		for(j=0;j<c;j++){
			if(i>=at[min1[j]]&&dp[i-at[min1[j]]][0]>0){
				int tmp=dp[i-at[min1[j]]][0]+1,king=dp[i][0];
				//for(k=0;k<10;k++)king+=dp[i][k];
				//for(k=1;k<10;k++)tmp+=dp[i-at[min1[j]]][k];
				//printf("%d:%d,%d\n",i,tmp,king);
				if(king<=tmp){
					for(k=0;k<10;k++){
						dp[i][k]=dp[i-at[min1[j]]][k];
					}
					dp[i][0]=dp[i-at[min1[j]]][0]+1;
					dp[i][min1[j]]++;
				}
			}
		}
	}
	//puts("o");
	for(i=9;i>0;i--){
		//printf("%d\n",dp[5][i]);
		for(k=0;k<dp[n][i];k++)printf("%d",i);
	}
		puts("");
		return 0;
		
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&ab);
   ^
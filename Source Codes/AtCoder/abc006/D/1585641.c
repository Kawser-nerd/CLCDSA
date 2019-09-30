#include <stdio.h>

int big(int a,int b){
	int t;
	if(a>=b){
		t=a;
	}else{
		t=b;
	}
	return t;
}

int main(){
	int n,i,j,c=0,data[30001]={0},dp[30001]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&data[i]);
	}
 
	for(i=0;i<n;i++){
		dp[i]=1;
		for(j=0;j<i;j++){
			if(data[j]<data[i]){
				dp[i]=big(dp[i],dp[j]+1);
			}
		}
		c=big(c,dp[i]);
	}
	
	printf("%d\n",n-c);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&data[i]);
   ^
#include<stdio.h>

int main(){
	int i,j,min,N,ans=0,memo[100001]={0};
	scanf("%d",&N);

	for(i=1;i<=N;i++){
		min=memo[i-1];
		if(i>=6 && min>memo[i-6])min=memo[i-6];
		if(i>=9 && min>memo[i-9])min=memo[i-9];
		if(i>=36 && min>memo[i-36])min=memo[i-36];
		if(i>=81 && min>memo[i-81])min=memo[i-81];
		if(i>=216 && min>memo[i-216])min=memo[i-216];
		if(i>=729 && min>memo[i-729])min=memo[i-729];
		if(i>=1296 && min>memo[i-1296])min=memo[i-1296];
		if(i>=6561 && min>memo[i-6561])min=memo[i-6561];
		if(i>=7776 && min>memo[i-7776])min=memo[i-7776];
		if(i>=46656 && min>memo[i-46656])min=memo[i-46656];
		if(i>=59049 && min>memo[i-59049])min=memo[i-59049];

		memo[i]=min+1;
	}

	printf("%d\n",memo[N]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
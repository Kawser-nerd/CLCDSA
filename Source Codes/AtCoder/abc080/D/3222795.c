#include<stdio.h>

int work[200000][30];

int main(){
	int N,C,ans=0;
	scanf("%d%d",&N,&C);
	int s[N],t[N],c[N];
	
	for(int i=0;i<N;i++){
		scanf("%d%d%d",&s[i],&t[i],&c[i]);
		s[i]=s[i]*2-1;
		t[i]=t[i]*2;
		c[i]--;
		for(int j=s[i];j<t[i];j++)work[j][c[i]]=1;
	}
	
	for(int i=0;i<200000;i++){
		int c=0;
		for(int j=0;j<30;j++)if(work[i][j]==1)c++;
		if(c>ans)ans=c;
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&N,&C);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&s[i],&t[i],&c[i]);
   ^
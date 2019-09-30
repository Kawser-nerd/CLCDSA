#include<stdio.h>

long long at[51]={1};
long long pat[51]={1};
long long ans=0;

int am(long long x,int level){
		//printf("%lld,%d\n",x,level);
		if(x==-1)return 0;
		if(level==-1)return 0;
		if(x==at[level])ans+=pat[level];
		else if(x<=at[level-1]+1)am(x-1,level-1);
		else if(x==at[level-1]+2)ans+=pat[level-1]+1;
		else {
				ans+=pat[level-1]+1;
				am(x-(at[level-1]+2),level-1);
		}
		return 0;
}

int main(){
		int n,i;
		long long x;
		scanf("%d%lld",&n,&x);
		for(i=1;i<=50;i++)at[i]=at[i-1]*2+3;
		for(i=1;i<=50;i++)pat[i]=pat[i-1]*2+1;
		am(x,n);
		printf("%lld\n",ans);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%lld",&n,&x);
   ^
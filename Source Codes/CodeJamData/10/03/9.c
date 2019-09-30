#include<stdio.h>
#include<memory.h>
#define ull unsigned long long
ull G[2001];
int g[1001];
int mark[1001];
int k,r,n;
inline static void find(int *start,int *end){
	int j=1;
	int count=1;
	while(!mark[j]){
		mark[j]=count;
		ull sum=0;
		for(;sum<=(ull)k;){
			sum+=(ull)g[j];
			if(sum<=(ull)k)j=j%n+1;
		}
		G[count]=G[count-1]+sum-(ull)g[j];
		count++;
	}
	*start=mark[j];
	*end=count-1;
	return;
}
int main(){
	int T;
	scanf("%d",&T);
	int L;
	for(L=1;L<=T;L++){
		scanf("%d%d%d",&r,&k,&n);
		memset(g,0,sizeof g);
		memset(mark,0,sizeof mark);
		int i;
		ull tmp=0;
		for(i=1;i<=n;i++){
			scanf("%d",g+i);
			tmp+=g[i];
		}
		ull ans=0;
		if(tmp>k){
			int s,e;
			find(&s,&e);
			ans=G[s-1];
			ans+=(G[e]-G[s-1])*((r-s+1)/(e-s+1));
			ans+=G[(r-s+1)%(e-s+1)+s-1]-G[s-1];
		}else{
			ans=tmp*r;
		}
		printf("Case #%d: %llu\n",L,ans);
	}
	return 0;
}
	


#include<stdio.h>
struct _{
       int num,id;
}g2[1001];
int g[1001];
int mark[1001];
static int cmp(const void *a,const void *b){
	return ((struct _ *)a)->num-((struct _ *)b)->num;
}
int main(){
	int t,n;
	scanf("%d",&t);
	int pp;
	for(pp=1;pp<=t;pp++){
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++){
			scanf("%d",g+i);
			g2[i].num=g[i];
			g2[i].id=i;
		}
		qsort(g2,n,sizeof(struct _),cmp);
		for(i=0;i<n;i++)
			g[g2[i].id]=i;
		memset(mark,0,sizeof mark);
		int ans=0;
		for(i=0;i<n;i++){
			if(mark[i])continue;
			int now=g[i];
			mark[i]=1;
			int len=1;
			while(now!=i){
				mark[now]=1;
				len++;
				now=g[now];
			}
			if(len>1)ans+=len;
		}
		printf("Case #%d: %d.000000\n",pp,ans);
	}
	return 0;
}
	

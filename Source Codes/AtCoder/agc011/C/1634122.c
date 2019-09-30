#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 100000000
#define MOD 1000000007
#define SIZE 100005
#define FOR(i,a,n) for(i=(a);i<(n);i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
typedef struct LIST{
	int to;
	struct LIST *next;
}Edge;
void add_edge(Edge **edge,int s,int t){
	Edge *tmp=(Edge*)malloc(sizeof(Edge));
	tmp->to=t;
	tmp->next=edge[s];
	edge[s]=tmp;
	return;
}
void delete_edge(Edge **edge,int v){
	int i;
	Edge *e,*tmp;
	FOR(i,0,v){
		e=edge[i];
		while(e!=NULL){
			tmp=e->next;
			free(e);
			e=tmp;
		}
	}
	return;
}
Edge *edge[100000];
int color[100000];
int cnt[3];
int flag;
void dfs(int v,int c){
	Edge *e;
	color[v]=c;
	for(e=edge[v];e!=NULL;e=e->next){
		if(color[e->to]==c) flag=0;
		if(color[e->to]==0) dfs(e->to,-c);
	}
	return;
}
int main(void)
{
	int n,m,a,b,i;
	ll res=0;
	scanf("%d%d",&n,&m);
	FOR(i,0,m){
		scanf("%d%d",&a,&b);
		add_edge(edge,--a,--b);
		add_edge(edge,b,a);
	}
	FOR(i,0,n){
		if(color[i]!=0) continue;
		if(edge[i]==NULL) cnt[0]++;
		else{
			flag=1;
			dfs(i,1);
			if(flag) cnt[1]++;
			else cnt[2]++;
		}
	}
	//FOR(i,0,3) printf("%d ",cnt[i]);
	res+=(ll)cnt[0]*(2*n-cnt[0]);
	res+=2LL*cnt[1]*cnt[2];
	res+=2LL*cnt[1]*cnt[1]+cnt[2]*cnt[2];
	printf("%lld\n",res);
	delete_edge(edge,n);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:59:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:61:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^
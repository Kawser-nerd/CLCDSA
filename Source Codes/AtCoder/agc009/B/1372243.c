#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 100000000
#define FOR(i,a,n) for(i=a;i<n;i++)
int comp(const void* a,const void* b){
	return *(int*)b-*(int*)a;
}
typedef struct LIST{
	int num;
	struct LIST *next;
}Graph;
Graph** init(int v){
	Graph **g=(Graph**)calloc(v,sizeof(Graph*));
	return g;
}
void add(Graph **g,int s,int n){
	Graph *tmp=(Graph*)malloc(sizeof(Graph));
	tmp->num=n;
	tmp->next=g[s];
	g[s]=tmp;
	return;
}
void delete_graph(Graph **g,int v){
	int i;
	Graph *e,*tmp;
	FOR(i,0,v){
		e=g[i];
		while(e!=NULL){
			tmp=e->next;
			free(e);
			e=tmp;
		}
	}
	return;
}
Graph **g;
int dp[100000];
int s[100000];
void dfs(int v){
	int i;
	int *a=calloc(s[v],sizeof(int));
	int size=0;
	Graph *k;
	for(k=g[v];k!=NULL;k=k->next){
		dfs(k->num);
		a[size++]=dp[k->num];
	}
	qsort(a,size,sizeof(int),comp);
	FOR(i,0,size){
		dp[v]=MAX(dp[v],a[i]+i+1);
	}
	return;
}
int main(void){
	int n,p,i;
	scanf("%d",&n);
	g=init(n);
	FOR(i,1,n){
		scanf("%d",&p);
		add(g,--p,i);
		s[p]++;
	}
	dfs(0);
	printf("%d\n",dp[0]);
	delete_graph(g,n);
} ./Main.c: In function ‘main’:
./Main.c:62:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:65:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&p);
   ^
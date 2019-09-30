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
int size[100000];
int a[100000];
int dfs(int v,int prev){
	int cnt=0,s,max=0,t;
	Edge *e;
	if(size[v]==1) return a[v];
	for(e=edge[v];e!=NULL;e=e->next){
		if(e->to==prev) continue;
		s=dfs(e->to,v);
		cnt+=s;
		max=MAX(max,s);
	}
	t=a[v]*2-cnt;
	if(a[v]>cnt||a[v]<max||2*a[v]<cnt){
		puts("NO");
		exit(0);
	}
	return t;
}
int main(void)
{
	int n,x,y,i;
	scanf("%d",&n);
	FOR(i,0,n) scanf("%d",&a[i]);
	if(n==2){
		printf("%s\n",a[0]==a[1]?"YES":"NO");
		return 0;
	}
	FOR(i,0,n-1){
		scanf("%d%d",&x,&y);
		add_edge(edge,--x,--y);
		add_edge(edge,y,x);
		size[x]++,size[y]++;
	}
	for(i=0;size[i]==1;i++);
	printf("%s\n",dfs(i,-1)==0?"YES":"NO");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:65:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:66:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,n) scanf("%d",&a[i]);
             ^
./Main.c:72:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&x,&y);
   ^
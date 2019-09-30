#include <stdio.h>
#include <string.h>
#include <stdbool.h>

long long d[300020];
bool visited[300020];
typedef struct{
	int to,head,next;
	long long cost;
}edge;
edge tree[300030];


void dfs(int v,int p, long long cost){
	d[v]=cost;
	visited[v]=true;
	for (int e=tree[v].head; e!=-1; e=tree[e].next){
		if (!visited[tree[e].to]){
			if (tree[e].to==p)continue;
			dfs(tree[e].to,v,tree[e].cost+cost);
			visited[tree[e].to]=false;
		}
	}
}

int main(void){
	int n,m=0;
	scanf("%d",&n);
	for (int i=0; i<n; i++)tree[i].head=-1;
	for (int i=0; i<n-1; i++){
		int a,b;
		long long c;
		scanf("%d%d%lld",&a,&b,&c);
		a--;
		b--;
		tree[m].next=tree[a].head;
		tree[a].head=m;
		tree[m].to=b;
		tree[m].cost=c;
		m++;
		tree[m].next=tree[b].head;
		tree[b].head=m;
		tree[m].to=a;
		tree[m].cost=c;
		m++;
	}
	int q,k;
	scanf("%d%d",&q,&k);
	dfs(k-1,-1,0);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",d[x-1]+d[y-1]);
	}
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:28:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%lld",&a,&b,&c);
   ^
./Main.c:48:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&q,&k);
  ^
./Main.c:52:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&x,&y);
   ^
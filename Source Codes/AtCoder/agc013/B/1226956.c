#include <stdio.h>
#include <stdlib.h>
#define swap(type,a,b) do{type temp=a; a=b; b=temp;}while(0);
#define FOR(i,a,n) for(i=a;i<n;i++)

typedef struct LIST{
	int to;
	struct LIST *next;
}Edge;

Edge *edge[100001];
int used[100001];
int ans[100001];
int size=0;

void reverse(int a[],int left,int right){
	while(right>left){
		swap(int,a[left],a[right]);
		left++,right--;
	}
	return;
}

void add(int v,int t){
	Edge *temp = (Edge*)malloc(sizeof(Edge));
	temp->to = t;
	temp->next = edge[v];
	edge[v] = temp;
	return;
}

void end(int v){
	for(int i=1;i<=v;i++){
		for(Edge *e=edge[i]->next;e!=NULL;e=e->next)
		    free(e);
	}
	return;
}

void dfs(int v){
	used[v]=1;
	for(Edge* e=edge[v];e!=NULL;e=e->next){
		if(!used[e->to]){
			ans[size++]=e->to;
			dfs(e->to);
			return;
		}
	}
	return;
}

int main(void)
{
 	int n,m,i,a,b;
 	scanf("%d%d",&n,&m);
 	FOR(i,0,m){
 		scanf("%d%d",&a,&b);
 		add(a,b); add(b,a);
 	}
 	int s=1;
 	int g=edge[s]->to;
 	used[s]=used[g]=1;
 	ans[size++]=s;
 	dfs(s);
 	reverse(ans,0,size-1);
 	ans[size++]=g;
 	dfs(g);
 	printf("%d\n",size);
 	FOR(i,0,size) printf("%d\n",ans[i]);
 	end(n);
 	return 0;
} ./Main.c: In function ‘main’:
./Main.c:55:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:57:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d%d",&a,&b);
    ^
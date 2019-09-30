#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define MOD 1000000007
#define FOR(i,a,n) for(i=a;i<n;i++)
typedef struct{
	int x,y,num;
}Pos;
int comp1(const void* a,const void* b){
	return ((Pos*)a)->x - ((Pos*)b)->x;
}
int comp2(const void *a,const void *b){
	return ((Pos*)a)->y - ((Pos*)b)->y;
}
//Union-Find
int *par;
int *rank;
void union_init(int size){
	int i;
	par=calloc(size,sizeof(int));
	rank=calloc(size,sizeof(int));
	FOR(i,0,size) par[i]=i;
	return;
}
int root(int a){
	if(par[a]==a) return a;
	else{
		par[a]=root(par[a]);
		return par[a];
	}
}
int is_same(int a,int b){
	return root(a)==root(b);
}
void unite(int a,int b){
	a=root(a);
	b=root(b);
	if(a==b) return;
	if(rank[a]>rank[b])
	    par[b]=a;
	else{
		par[a]=b;
		if(rank[a]==rank[b]) rank[b]++;
	}
	return;
}
void delete_union(){
	free(par);
	free(rank);
	return;
}

typedef struct{
	int s,t,cost;
} Edge;
int comp(const void *a,const void *b){
	return ((Edge*)a)->cost > ((Edge*)b)->cost?1:-1;
};
ll kruscal(Edge *edge,int V,int E){
	int i,cnt=0;
	ll res=0;
	Edge e;
	qsort(edge,E,sizeof(Edge),comp);
	union_init(V);
	FOR(i,0,E){
		e=edge[i];
		if(!is_same(e.s,e.t)){
			unite(e.s,e.t);
			res+=e.cost,cnt++;
		}
	}
	delete_union();
	return cnt==V-1?res:-1;
}
Edge edge[200000];
Pos a[100000];
int main(void)
{
	int n,i;
	scanf("%d",&n);
	FOR(i,0,n){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].num=i;
	}
	qsort(a,n,sizeof(Pos),comp1);
	FOR(i,0,n-1) edge[i].s=a[i].num,edge[i].t=a[i+1].num,edge[i].cost=a[i+1].x-a[i].x;
	qsort(a,n,sizeof(Pos),comp2);
	FOR(i,0,n-1) edge[i+n-1].s=a[i].num,edge[i+n-1].t=a[i+1].num,edge[i+n-1].cost=a[i+1].y-a[i].y;
	printf("%lld\n",kruscal(edge,n,2*(n-1)));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:85:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:87:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a[i].x,&a[i].y);
   ^
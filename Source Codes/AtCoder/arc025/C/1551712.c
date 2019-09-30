#include <stdio.h>
#include <stdlib.h>
#define FOR(i,a,n) for(i=a;i<n;i++)
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define INF 100000000
#define ll long long
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
typedef struct LIST{
	int to,cost;
	struct LIST *next;
}Edge;
typedef struct{
	int num,dist;
}Pos;
Edge** init(int v){
	Edge **edge=(Edge**)calloc(v,sizeof(Edge*));
	return edge;
}
void add_edge(Edge **edge,int s,int t,int c){
	Edge *tmp=(Edge*)malloc(sizeof(Edge));
	tmp->to=t,tmp->cost=c;
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
void push(Pos *heap,int *heap_size,int n,int d){
	int i=(*heap_size)++;
	while(i>0){
		int p=(i-1)/2;
		if(heap[p].dist<=d) break;
		heap[i]=heap[p];
		i=p;
	}
	heap[i].num=n;
	heap[i].dist=d;
	return;
}
Pos pop(Pos *heap,int *heap_size){
	Pos data=heap[0];
	Pos n=heap[--*heap_size];
	int a,b,pos=0;
	while(pos*2+1<*heap_size){
		a=pos*2+1;
		b=pos*2+2;
		if(b<*heap_size&&heap[a].dist>heap[b].dist) a=b;
		if(n.dist<=heap[a].dist) break;
		heap[pos]=heap[a];
		pos=a;
	}
	heap[pos]=n;
	return data;
}
Pos heap[2500];
int heap_size;
void dijkstra(Edge **edge,int v,int d[],int s){
	int i;
	Pos p;
	Edge *e;
	FOR(i,0,v) d[i]=INF;
	d[s]=0;
	push(heap,&heap_size,s,0);
	while(heap_size){
		p=pop(heap,&heap_size);
		if(d[p.num]<p.dist) continue;
		for(e=edge[p.num];e!=NULL;e=e->next){
			if(d[e->to]>d[p.num]+e->cost){
				d[e->to]=d[p.num]+e->cost;
				push(heap,&heap_size,e->to,d[e->to]);
			}
		}
	}
	return;
}
Edge **edge;
int d[2500];
int main(void)
{
	int n,m,r,t,a,b,c,i,j,k;
	ll ans=0;
	scanf("%d%d%d%d",&n,&m,&r,&t);
	edge=init(n);
	FOR(i,0,m){
		scanf("%d%d%d",&a,&b,&c);
		add_edge(edge,--a,--b,c);
		add_edge(edge,b,a,c);
	}
	FOR(i,0,n){
		heap_size=0;
		dijkstra(edge,n,d,i);
		qsort(d,n,sizeof(int),comp);
		k=1;
		FOR(j,1,n){
			while(k<n&&d[j]*r>=d[k]*t) k++;
			ans+=n-k-(k<=j);
		}
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:96:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d",&n,&m,&r,&t);
  ^
./Main.c:99:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^
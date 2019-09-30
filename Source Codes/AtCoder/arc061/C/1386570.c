#include <stdio.h>
#include <stdlib.h>
#define FOR(i,a,n) for(i=a;i<n;i++)
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define INF 1000000000
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
void dijkstra(Edge **edge,int v,int d[],int s){
	int i,heap_size=0;
	Pos p,*heap;
	Edge *e;
	heap=calloc(v,sizeof(Edge));
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
	free(heap);
	return;
}
int size=0;
typedef struct{
	int sta,company,v_num;
}Data;
typedef struct node{
	struct node *right;
	struct node *left;
	Data data;
} Node;
Node* add(Node *n,int a,int b,int c){
	int cmp;
	if(n==NULL){
		Node *m=malloc(sizeof(Node));
		m->data.sta=a,m->data.company=b,m->data.v_num=c;
		m->right=m->left=NULL;
		return m;
	}
	else{
		cmp=(n->data.sta==a?n->data.company-b:n->data.sta-a);
		if(cmp==0) return n;
		if(cmp<0) n->right=add(n->right,a,b,c);
		else n->left=add(n->left,a,b,c);
		return n;
	}
}
int find(Node *n,int a,int b){
	int cmp;
	if(n==NULL) return size++;
	cmp=(n->data.sta==a?n->data.company-b:n->data.sta-a);
	if(cmp==0) return n->data.v_num;
	if(cmp<0) return find(n->right,a,b);
	else return find(n->left,a,b);
}
void delete_node(Node *n){
	if(n!=NULL){
		delete_node(n->left);
		delete_node(n->right);
		free(n);
	}
	return;
}
Edge **edge;
int d[500000];
int main(void)
{
	int n,m,p,q,c,v1,v2,i;
	Node *k=NULL;
	scanf("%d%d",&n,&m);
	edge=init(2*m+n);
	FOR(i,0,m){
		scanf("%d%d%d",&p,&q,&c);
		v1=find(k,--p,c);
		v2=find(k,--q,c);
		add_edge(edge,v1,v2,0);
		add_edge(edge,v2,v1,0);
		add_edge(edge,v1,2*m+p,0);
		add_edge(edge,v2,2*m+q,0);
		add_edge(edge,2*m+p,v1,1);
		add_edge(edge,2*m+q,v2,1);
		k=add(k,p,c,v1);
		k=add(k,q,c,v2);
	}
	dijkstra(edge,2*m+n,d,2*m);
	printf("%d\n",d[2*m+n-1]==INF?-1:d[2*m+n-1]);
	delete_edge(edge,2*m+n);
	delete_node(k);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:133:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:136:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&p,&q,&c);
   ^
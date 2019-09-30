#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <regex.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a) ((a)<0?-(a):(a))
#define alloc(type,size) calloc(sizeof(type),size)

typedef struct node {
	struct branch {
		struct branch *next;
		struct node *below;
		bool b;
	} *branch;
	bool bl;
	int val;
} node;
typedef struct branch branch;

typedef struct heap {
	node *nd;
	int val;
	int b;
} hp;



branch* push_back(node *a,node *b,branch *c){
	c->next = a->branch;
	c->below = b;
	a->branch = c;
	return ++c;
}
void hp_push(hp x,hp *heap,int *heap_size){
	int i = (*heap_size)++;
	while(i>0){
		int p = (i-1)/2;
		if(heap[p].b <= x.b) break;
		heap[i] = heap[p];
		i = p;
	}
	heap[i] = x;
}

hp hp_pop(hp *heap,int *heap_size){
	hp ret = heap[0];
	hp x = heap[--*heap_size];
	int i = 0;
	while(i*2+1 < *heap_size){
		int a = i*2+1;
		int b = i*2+2;
		if(b < *heap_size && heap[b].b < heap[a].b)a = b;
		if(heap[a].b > x.b)break;
		heap[i] = heap[a];
		i = a;
	}
	heap[i] = x;
	return ret;
}

void dijkstra(hp x,hp *heap,int *heap_size){
	branch *br;
	
	if(x.nd->val <= x.val){
		if(*heap_size) return dijkstra(hp_pop(heap,heap_size),heap,heap_size);
		else return;		
	}
	
	x.nd->val = x.val;
	for(br=x.nd->branch;br;br=br->next){
		if(br->b){
			int cost = x.val + 1 + x.b;
			hp x_ = {br->below,cost,x.b+1};
			if(cost < br->below->val) hp_push(x_,heap,heap_size);
		}else{
			int cost = x.val + 1;
			hp x_ = {br->below,cost,x.b};
			if(cost < br->below->val) hp_push(x_,heap,heap_size);
		}
	}
	if(*heap_size) return dijkstra(hp_pop(heap,heap_size),heap,heap_size);

}
void nd_init(node *nd,int n){
	int i;
	for(i=0;i<n;i++){
		nd[i].bl = false;
		nd[i].val = INT_MAX;
	}
}

int main(void){
	int n,m;
	int a,b,c;

	node *nd;
	hp *heap;
	branch *br;
	int heap_size=0;
	int i;

	scanf("%d%d",&n,&m);

	nd = alloc(node,n);
	br = alloc(branch,m*2);
	heap = alloc(hp,100000000);
	nd_init(nd,n);

	for(i=0;i<m;i++){
		scanf("%d%d%d",&c,&a,&b);
		br->b = c;
		push_back(&nd[a],&nd[b],br++);
		br->b = c;
		push_back(&nd[b],&nd[a],br++);
	}
	hp x_ = {nd,0,0};
	dijkstra(x_,heap,&heap_size);

	for(i=0;i<n;i++){
		printf("%d\n", nd[i].val);
	}



    return 0;
} ./Main.c: In function ‘main’:
./Main.c:108:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:116:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&c,&a,&b);
   ^
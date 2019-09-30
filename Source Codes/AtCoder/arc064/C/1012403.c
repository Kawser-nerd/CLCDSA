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

#define N 1020

typedef struct {
	double x;
	double y;
	double r;
} circle;


typedef struct node {
	struct branch {
		struct branch *next;
		struct node *below;
		double cost;
	} *branch;
	bool bl;
	bool vs;
	double val;
} node;
typedef struct branch branch;

typedef struct heap {
	node *nd;
	double val;
} hp;


circle point[N];
int n;

void push_back(node *a,node *b,branch *c){
	c->next = a->branch;
	c->below = b;
	a->branch = c;
	return;
}
void hp_push(hp x,hp *heap,int *heap_size){
	int i = (*heap_size)++;
	while(i>0){
		int p = (i-1)/2;
		if(heap[p].val < x.val) break;
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
		if(b < *heap_size && heap[b].val < heap[a].val)a = b;
		if(heap[a].val >= x.val)break;
		heap[i] = heap[a];
		i = a;
	}
	heap[i] = x;
	return ret;
}

void dijkstra(node *start,hp *heap,int *heap_size){
	branch *br;
	if(start->bl){
		if(*heap_size) return dijkstra(hp_pop(heap,heap_size).nd,heap,heap_size);
		else return;
	}

	start->bl = true;
	for(br=start->branch;br;br=br->next){
		if(br->below->bl) continue;
		if(br->below->val > start->val+br->cost){
			br->below->val = start->val+br->cost;
			hp x;
			x.nd = br->below;
			x.val = br->below->val;
			hp_push(x,heap,heap_size);
		}else if(br->below->vs == false){
			br->below->val = start->val+br->cost;
			br->below->vs = true;
			hp x;
			x.nd = br->below;
			x.val = br->below->val;
			hp_push(x,heap,heap_size);
		}
	}
	if(*heap_size){
		return dijkstra(hp_pop(heap,heap_size).nd,heap,heap_size);
	}
}
void init(node *nd,int n){
	int i;
	for(i=1;i<=n;i++){
		nd[i].bl = false;
		nd[i].val = 0;
	}
}


double dist(circle a,circle b){
	double x = a.x-b.x;
	double y = a.y-b.y;
	double d = sqrt(x*x+y*y)-a.r-b.r;
	return d<0.0?0.0:d;
}

int main(void){
	int i,j;
	double m;
	node *nd;
	hp *heap;
	branch *br;
	int *heap_size = alloc(int,1);

	scanf("%lf%lf",&point[0].x,&point[0].y);
	scanf("%lf%lf",&point[1].x,&point[1].y);
	scanf("%d",&n);
	n+=2;
	nd = alloc(node,n+n);
	br = alloc(branch,n*n+n);
	heap = alloc(hp,n*n+n);
	for(i=2;i<n;i++){
		scanf("%lf%lf%lf",&point[i].x,&point[i].y,&point[i].r);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			br->cost = dist(point[i],point[j]);
			push_back(&nd[i],&nd[j],br++);
		}
	}
	dijkstra(&nd[1],heap,heap_size);
	printf("%.10lf\n", nd[0].val);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:131:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf%lf",&point[0].x,&point[0].y);
  ^
./Main.c:132:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf%lf",&point[1].x,&point[1].y);
  ^
./Main.c:133:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:139:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf%lf%lf",&point[i].x,&point[i].y,&point[i].r);
   ^
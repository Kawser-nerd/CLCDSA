#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define true 1
#define false 0

typedef struct unionFind{
	int par;
	int val;
	int count;
} unionFind;


unionFind* uf_make(int n){
	unionFind* u;
	u = calloc(sizeof(unionFind),n);
	return u;
}

void uf_init(int n,unionFind *u){
	int i;
	for(i = 0;i < n;i++){
		u[i].par = i;
		u[i].count = 1;
	}
}
int uf_root(int x,unionFind *u){
	if(u[x].par == x){
		return x;
	}else{
		return u[x].par = uf_root(u[x].par,u);
	}
}
int uf_same(int x,int y,unionFind *u){
	return uf_root(x,u) == uf_root(y,u);
}
void uf_unite(int x,int y,unionFind *u){
	x = uf_root(x,u);
	y = uf_root(y,u);
	if(x == y)return;
	u[x].par = y;
	u[y].count += u[x].count;
}
int uf_count(int x,unionFind *u){
	x = uf_root(x,u);
	return u[x].count;
}


typedef struct node {
	struct connecter {
		struct connecter *side;
		struct node *below;
	} *connecter;
	int id;
	int size;
} node;
typedef struct connecter connecter;

void push_back(node *a,node *b){
	connecter *c;
	c = calloc(sizeof(connecter),1);
	c->side = a->connecter;
	c->below = b;
	a->connecter = c;
	a->size++;
}

int comp(const void *a,const void *b){
	return *(int*)a - *(int*)b;
}

int main(void){
	int i,j,x,y;
	int n,m,s;
	unionFind *fa;
	node *g;
	connecter *p;
	int *ans;
	int ans_length = 0;
	scanf("%d%d%d",&n,&m,&s);
	fa = uf_make(n+1);
	uf_init(n+1,fa);
	g = calloc(sizeof(node),n+1);
	ans = calloc(sizeof(int),n);
	for(i=1;i<=n;i++) g[i].id = i;
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(x < y){
			push_back(&g[x],&g[y]);
		}else{
			push_back(&g[y],&g[x]);
		}
	}
	for(i=n;i>=1;i--){
		for(p = g[i].connecter;p;p = p->side) uf_unite(i,p->below->id,fa);
		if(uf_same(s,i,fa)) ans[ans_length++] = i;
	}
	qsort(ans,ans_length,sizeof(int),comp);
	for(i=0;i<ans_length;i++){
		printf("%d\n", ans[i]);
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:85:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&m,&s);
  ^
./Main.c:92:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&x,&y);
   ^
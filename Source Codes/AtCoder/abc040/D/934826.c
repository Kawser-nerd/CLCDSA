#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define	abs(a) ((a)<0?-(a):(a))

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

typedef struct branch {
	int a;
	int b;
	int y;
} branch;

typedef struct citizen {
	int v;
	int w;
	int ans;
} citizen;

int comp(const void *a,const void *b){
	return (*(citizen**)b)->w - (*(citizen**)a)->w;
}
int comp2(const void *a,const void *b){
	return ((branch*)b)->y - ((branch*)a)->y;
}
void solve(unionFind *uf,branch *br,citizen **ctp,int i,int j,int m,int q){
	for(j=0;j<q;j++){
		while(br[i].y > ctp[j]->w && i < m){
			uf_unite(br[i].a,br[i].b,uf);
			i++;
		}
		ctp[j]->ans = uf_count(ctp[j]->v,uf);
	}
}

int main(void){
	/* === ??????? ===*/
	int n,m;
	branch *br;
	int q;
	citizen *ct;

	/* === ?? ===*/
	int i;
	unionFind *uf;
	citizen **ctp;//????/*??????ct???????????*/

	/* === ?? === */
	scanf("%d%d",&n,&m);
	br = calloc(sizeof(branch),m);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&br[i].a,&br[i].b,&br[i].y);
	}
	scanf("%d",&q);
	ct = calloc(sizeof(citizen),q);
	ctp = calloc(sizeof(citizen*),q);
	for(i=0;i<q;i++){
		scanf("%d%d",&ct[i].v,&ct[i].w);
		ctp[i] = &ct[i];
	}
	/* === ??? === */
	uf = uf_make(n+1);
	uf_init(n+1,uf);
	qsort(ctp,q,sizeof(citizen*),comp);
	qsort(br,m,sizeof(branch),comp2);
	/* === solve === */
	solve(uf,br,ctp,0,0,m,q);

	/* === ?? === */
	for(i=0;i<q;i++){
		printf("%d\n", ct[i].ans);
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:94:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:97:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&br[i].a,&br[i].b,&br[i].y);
   ^
./Main.c:99:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&q);
  ^
./Main.c:103:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&ct[i].v,&ct[i].w);
   ^
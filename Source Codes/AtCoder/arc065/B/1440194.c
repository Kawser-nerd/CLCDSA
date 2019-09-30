#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 100000000
#define FOR(i,a,n) for(i=(a);i<(n);i++)
void fill(int a[],int b,int c){
	int i;
	FOR(i,0,b) a[i]=c;
	return;
}
typedef struct{
	int *par,*rank;
}Union;
void init_union(Union *u,int size){
	int i;
	u->par = (int*)calloc(size,sizeof(int));
	u->rank = (int*)calloc(size,sizeof(int));
	FOR(i,0,size) u->par[i]=i;
	return;
}
int root(Union *u,int a){
 	if(u->par[a]==a) return a;
 	else{
 		u->par[a]=root(u,u->par[a]);
 		return u->par[a];
 	}
}
int is_same(Union *u,int a,int b){
 	return root(u,a)==root(u,b);
} 
void unite(Union *u,int a,int b){
	a=root(u,a);
	b=root(u,b);
	if(a==b) return;
	if(u->rank[a]>u->rank[b])
	    u->par[b]=a;
	else{
		u->par[a]=b;
		if(u->rank[a]==u->rank[b]) u->rank[b]++;
	}
	return;
}
void delete_union(Union *u){
	free(u->par);
	free(u->rank);
	return;
}
typedef struct{
	int x,y,num;
}City;
int comp(const void *a,const void *b){
	City s=*(City*)a,t=*(City*)b;
	return s.x!=t.x?s.x-t.x:s.y-t.y;
}
int lower_bound(City a[],int n,City k){
	int left=-1; int right=n;
	while(right-left>1){
		int mid=(left+right)/2;
		if(comp((void*)&a[mid],(void*)&k)<0) left=mid;
		else right=mid;
	}
	return right;
}
int upper_bound(City a[],int n,City k){
	int left=-1; int right=n;
	while(right-left>1){
		int mid=(left+right)/2;
		if(comp((void*)&a[mid],(void*)&k)<=0) left=mid;
		else right=mid;
	}
	return right;
}
City city[200000];
int main(void)
{
	int n,k,l,a,b,i;
	Union p,q;
	City c;
	scanf("%d%d%d",&n,&k,&l);
	init_union(&p,n);
	init_union(&q,n);
	while(k-->0){
		scanf("%d%d",&a,&b);
		unite(&p,--a,--b);
	}
	while(l-->0){
		scanf("%d%d",&a,&b);
		unite(&q,--a,--b);
	}
	FOR(i,0,n) city[i].x=root(&p,i),city[i].y=root(&q,i);
	qsort(city,n,sizeof(City),comp);
	FOR(i,0,n){
		//printf("%d %d\n",city[i].x,city[i].y);
		c.x=root(&p,i),c.y=root(&q,i);
		printf("%d%c",upper_bound(city,n,c)-lower_bound(city,n,c),i==n-1?'\n':' ');
	}
	delete_union(&p);
	delete_union(&q);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:85:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&k,&l);
  ^
./Main.c:89:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^
./Main.c:93:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^
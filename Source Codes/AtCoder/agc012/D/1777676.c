#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 2000000000
#define MOD 1000000007
#define SIZE 200005
#define FOR(i,a,n) for(i=(a);i<(n);i++)

int *par;
int *rank;
int *v;
void init_union(int size){
	int i;
	par = (int*)calloc(size,sizeof(int));
	rank = (int*)calloc(size,sizeof(int));
	v = (int*)calloc(size,sizeof(int));
	FOR(i,0,size) par[i]=i,v[i]=1;
	return;
}

int root(int a){
 	if(par[a]==a) return a;
 	else{
 		return (par[a]=root(par[a]));
 	}
}
 
int is_same(int a,int b){
 	return root(a)==root(b);
}
 
void unite(int a,int b){
	a=root(a);
	b=root(b);
	if(a==b){
		return;
	}
	if(rank[a]>rank[b]){
		par[b]=a;
		v[a]+=v[b];
		v[b]=0;
	}
	else{
		par[a]=b;
		v[b]+=v[a];
		v[a]=0;
		if(rank[a]==rank[b]) rank[b]++;
	}
	return;
}

ll inv[SIZE],f[SIZE],finv[SIZE];
void make_table(){
	int i;
	f[0]=f[1]=1; finv[0]=finv[1]=1;
	inv[1]=1;
	FOR(i,2,SIZE+1){
		inv[i]=MOD-(MOD/i)*inv[MOD%i]%MOD;
		f[i]=(f[i-1]*(ll)i)%MOD;
		finv[i]=(finv[i-1]*inv[i])%MOD;
	}
	return;
}
ll comb(int n,int k){
	if(n<0||k<0||n<k) return 0;
	return (((f[n]*finv[k])%MOD)*finv[n-k])%MOD;
}

typedef struct{
	int c,w;
}Ball;
int comp1(const void* a,const void* b){
	return ((Ball*)a)->w - ((Ball*)b)->w;
}
int comp2(const void* a,const void* b){
	return *(int*)a - *(int*)b;
}
Ball ball[SIZE];
int min[SIZE];
int *ary[SIZE],mem[SIZE];
int size[SIZE];
int main(void)
{
	int n,x,y,id,color,total,cnt,i,j,k;
	ll res;
	scanf("%d%d%d",&n,&x,&y);
	FOR(i,0,n){
		scanf("%d%d",&ball[i].c,&ball[i].w);
		ball[i].c--;
		min[i]=INF;
	}
	
	FOR(i,0,n) min[ball[i].c]=MIN(min[ball[i].c],ball[i].w);
	FOR(i,0,n){
		if(ball[i].w+min[ball[i].c]<=x){
			ball[i].w=min[ball[i].c];
		}
	}
	qsort(ball,n,sizeof(Ball),comp1);
	//FOR(i,0,n) printf("%d %d\n",ball[i].c,ball[i].w);
	
	color=ball[0].c;
	FOR(i,1,n){
		if(color!=ball[i].c){
			id=i;
			color=ball[i].c;
			break;
		}
	}
	if(color==ball[0].c){
		puts("1");
		return 0;
	}
	
	init_union(n);
	FOR(i,0,n){
		if(ball[i].c==ball[0].c&&ball[i].w+ball[id].w<=y){
			unite(id,i);
		}
		if(ball[i].c!=ball[0].c&&ball[i].w+ball[0].w<=y){
			unite(0,i);
		}
	}
	
	ary[0]=mem;
	FOR(i,0,n-1) ary[i+1]=ary[i]+v[i];
	FOR(i,0,n){
		id=root(i);
		ary[id][size[id]++]=ball[i].c;
	}
	
	make_table();
	res=1;
	
	FOR(i,0,n){
		if(size[i]==0) continue;
		qsort(ary[i],size[i],sizeof(int),comp2);
		total=size[i]; cnt=j=k=0;
		while(j<size[i]){
			while(k<size[i]&&ary[i][j]==ary[i][k]) k++;
			res*=comb(total,k-j);
			res%=MOD;
			total-=(k-j);
			j=k;
		}
	}
	printf("%lld\n",res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:93:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&x,&y);
  ^
./Main.c:95:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&ball[i].c,&ball[i].w);
   ^
./Main.c: In function ‘make_table’:
./Main.c:65:9: warning: iteration 200003u invokes undefined behavior [-Waggressive-loop-optimizations]
   inv[i]=MOD-(MOD/i)*inv[MOD%i]%MOD;
         ^
./Main.c:14:20: note: containing loop
 #define FOR(i,a,n) for(i=(a);i<(n);i++)
                    ^
./Main.c:64:2: note: in expansion of macro ‘FOR’
  FOR(i,2,SIZE+1){
  ^
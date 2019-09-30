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
	int a,b,c,d;
}Coin;
int comp(const void* a,const void* b){
	return ((Coin*)a)->d - ((Coin*)b)->d;
}
Coin heap[100000];
int heap_size=0;
void push(Coin x){
 	int i=heap_size++;
 	while(i>0){
 		int p=(i-1)/2;
 		if(heap[p].d<=x.d) break;
 		heap[i]=heap[p];
 		i=p;
 	}
 	heap[i]=x;
 	return;
}
Coin pop(void){
 	Coin data=heap[0];
 	Coin n=heap[--heap_size];
 	int pos=0;
 	while(pos*2+1<heap_size){
 		int a=pos*2+1;
 		int b=pos*2+2;
 		if(b<heap_size&&heap[a].d>heap[b].d) a=b;
 		if(n.d<=heap[a].d) break;
 		heap[pos]=heap[a];
 		pos=a;
 	}
 	heap[pos]=n;
 	return data;
}
Coin coin[100000];
ll sum[100000];
int main(void)
{
	int x,y,z,size,i;
	ll s,res;
	Coin p;
	scanf("%d%d%d",&x,&y,&z);
	size=x+y+z;
	FOR(i,0,size){
		scanf("%d%d%d",&coin[i].a,&coin[i].b,&coin[i].c);
		coin[i].d=coin[i].a-coin[i].b;
	}
	qsort(coin,size,sizeof(Coin),comp);
	s=0;
	FOR(i,0,y){
		s+=coin[i].b;
		p.b=coin[i].b,p.c=coin[i].c,p.d=coin[i].b-coin[i].c;
		push(p);
	}
	sum[0]=s;
	FOR(i,y,y+z){
		p.b=coin[i].b,p.c=coin[i].c,p.d=coin[i].b-coin[i].c;
		s+=p.b;
		push(p);
		p=pop();
		s-=p.d;
		sum[i-y+1]=s;
	}
	//FOR(i,0,x+y+z) printf("%d %d %d\n",coin[i].a,coin[i].b,coin[i].c);
	heap_size=0,s=0;
	FOR(i,0,x){
		s+=coin[size-i-1].a;
		p.a=coin[size-i-1].a,p.c=coin[size-i-1].c,p.d=coin[size-i-1].a-coin[size-i-1].c;
		push(p);
	}
	res=s+sum[z];
	FOR(i,x,x+z){
		p.a=coin[size-i-1].a,p.c=coin[size-i-1].c,p.d=coin[size-i-1].a-coin[size-i-1].c;
		s+=p.a;
		push(p);
		p=pop();
		s-=p.d;
		res=MAX(res,s+sum[z-(i-x+1)]);
	}
	printf("%lld\n",res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:58:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&x,&y,&z);
  ^
./Main.c:61:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&coin[i].a,&coin[i].b,&coin[i].c);
   ^
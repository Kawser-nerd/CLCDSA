#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int*data,size,max_size;
}vector;

void init(vector*v){
	v->data=(int*)malloc(sizeof(int)*(v->max_size=1));
	v->size=0;
}

void push(vector*v,int x){
	if(v->size==v->max_size){
		v->data=(int*)realloc(v->data,sizeof(int)*(v->max_size<<=1));
	}
	v->data[v->size++]=x;
}

vector v[100001];

int max(int a,int b){return a>b?a:b;}
int cmp(const void*a,const void*b){return*(int*)b-*(int*)a;}

int f(int x){
	int n=v[x].size;
	int t[n];
	for(int i=0;i<n;++i){
		t[i]=f(v[x].data[i]);
	}
	qsort(t,n,sizeof(int),cmp);
	int r=0;
	for(int i=0;i<n;++i){
		r=max(r,t[i]+i+1);
	}
	return r;
}

int main(){
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;++i){
		init(&v[i]);
	}
	for(int i=2;i<=N;++i){
		int a;
		scanf("%d",&a);
		push(&v[a],i);
	}
	printf("%d\n",f(1));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:41:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:47:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^
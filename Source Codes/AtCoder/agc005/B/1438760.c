#include <stdio.h>
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
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}

typedef struct{
	int top;
	int *data;
}Stack;
void init(Stack *s,int size){
	s->data=(int*)calloc(size,sizeof(int));
	s->top=0;
	return;
}
void push(Stack *t,int a){
	t->data[t->top++]=a;
	return;
}
int pop(Stack *t){
	return t->data[--t->top];
}
int a[200000];
int l[200000],r[200000];
int main(void)
{
	int n,i;
	ll ans=0;
	Stack s;
	scanf("%d",&n);
	FOR(i,0,n) scanf("%d",&a[i]);
	init(&s,n);
	FOR(i,0,n){
		while(s.top&&a[s.data[s.top-1]]>a[i]) s.top--;
		if(!s.top) l[i]=-1;
		else l[i]=s.data[s.top-1];
		push(&s,i);
	}
	s.top=0;
	for(i=n-1;i>=0;i--){
		while(s.top&&a[s.data[s.top-1]]>a[i]) s.top--;
		if(!s.top) r[i]=n;
		else r[i]=s.data[s.top-1];
		push(&s,i);
	}
	FOR(i,0,n) ans+=(ll)a[i]*(i-l[i])*(r[i]-i);
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:40:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:41:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,n) scanf("%d",&a[i]);
             ^
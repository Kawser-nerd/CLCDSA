#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
	int *to;
	int len, alloced;
} Vector;
#define MAX_NODE (200000)
Vector train[MAX_NODE], road[MAX_NODE];
int parent[MAX_NODE], sizes[MAX_NODE] = {0};
int flags[MAX_NODE] = {0}, ans[MAX_NODE] = {0};

void add(Vector *v, int to){
	if(++(v->len) >= v->alloced){
		v->alloced = (v->alloced ? v->alloced*2 : 2);
		v->to = (int*)realloc(v->to, sizeof(int)*v->alloced);
	}
	v->to[v->len-1] = to;
}
void setParent(int p, int n){
	Vector *v = &road[n];
	int i, len = v->len, next;
	for(i=0;i<len;i++){
		next = v->to[i];
		if(parent[next]!=next || p==next){ continue; }
		parent[next] = p;
		setParent(p, next);
	}
}
void setSize(int n){
	Vector *v = &train[n];
	int i, len = v->len, next;
	flags[n] = 1;
	sizes[parent[n]]++;
	for(i=0;i<len;i++){
		next = v->to[i];
		if(flags[next]){ continue; }
		setSize(next);
	}
}
void getSize(int n){
	Vector *v = &train[n];
	int i, len = v->len, next;
	ans[n] = sizes[parent[n]];
	for(i=0;i<len;i++){
		next = v->to[i];
		if(ans[next]){ continue; }
		getSize(next);
	}
}
void resetSize(int n){
	Vector *v = &train[n];
	int i, len = v->len, next;
	flags[n] = 0;
	sizes[parent[n]] = 0;
	for(i=0;i<len;i++){
		next = v->to[i];
		if(!flags[next]){ continue; }
		resetSize(next);
	}
}

int main(void){
	int i, j;
	int N, K, L, from, to;
	scanf("%d%d%d", &N, &K, &L);
	for(i=0;i<N;i++){
		parent[i] = i;
	}
	for(i=0;i<K;i++){
		scanf("%d%d", &from, &to); from--; to--;
		add(&road[from], to);
		add(&road[to], from);
	}
	for(i=0;i<N;i++){ if(parent[i]==i){ setParent(i, i); } }
	
	for(i=0;i<L;i++){
		scanf("%d%d", &from, &to); from--; to--;
		add(&train[from], to);
		add(&train[to], from);
	}
	for(i=0;i<N;i++){
		if(ans[i]){ continue; }
		setSize(i);
		getSize(i);
		resetSize(i);
	}
	printf("%d", ans[0]);
	for(i=1;i<N;i++){
		printf(" %d", ans[i]);
	}
	puts("");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:66:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &K, &L);
  ^
./Main.c:71:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &from, &to); from--; to--;
   ^
./Main.c:78:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &from, &to); from--; to--;
   ^
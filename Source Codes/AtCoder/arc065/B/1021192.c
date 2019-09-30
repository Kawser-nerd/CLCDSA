#include <stdio.h>

typedef struct Item {
	struct Item *next;
	int to;
} Item;
#define MAX_NODE (200000)
Item *train[MAX_NODE] = {0}, *road[MAX_NODE] = {0};
int parent[MAX_NODE], sizes[MAX_NODE] = {0};
int setted[MAX_NODE] = {0}, resetted[MAX_NODE] = {0};
int ans[MAX_NODE] = {0};

void add(Item* list[], int from, int to){
	Item *p = (Item*)malloc(sizeof(Item));
	p->next = list[from];
	p->to = to;
	list[from] = p;
}
void setParent(int p, int n){
	Item *it;
	int next;
	for(it=road[n]; it!=NULL; it=it->next){
		next = it->to;
		if(parent[next]!=next || p==next){ continue; }
		parent[next] = p;
		setParent(p, next);
	}
}
void setSize(int n){
	Item *it;
	int next;
	setted[n] = 1;
	sizes[parent[n]]++;
	for(it=train[n]; it!=NULL; it=it->next){
		next = it->to;
		if(setted[next]){ continue; }
		setSize(next);
	}
}
void getSize(int n){
	Item *it;
	int next;
	ans[n] = sizes[parent[n]];
	for(it=train[n]; it!=NULL; it=it->next){
		next = it->to;
		if(ans[next]){ continue; }
		getSize(next);
	}
}
void resetSize(int n){
	Item *it;
	int next;
	resetted[n] = 1;
	sizes[parent[n]] = 0;
	for(it=train[n]; it!=NULL; it=it->next){
		next = it->to;
		if(resetted[next]){ continue; }
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
		add(road, from, to);
		add(road, to, from);
	}
	for(i=0;i<N;i++){ if(parent[i]==i){ setParent(i, i); } }
	
	for(i=0;i<L;i++){
		scanf("%d%d", &from, &to); from--; to--;
		add(train, from, to);
		add(train, to, from);
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
} ./Main.c: In function ‘add’:
./Main.c:14:19: warning: implicit declaration of function ‘malloc’ [-Wimplicit-function-declaration]
  Item *p = (Item*)malloc(sizeof(Item));
                   ^
./Main.c:14:19: warning: incompatible implicit declaration of built-in function ‘malloc’
./Main.c:14:19: note: include ‘<stdlib.h>’ or provide a declaration of ‘malloc’
./Main.c: In function ‘main’:
./Main.c:65:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &K, &L);
  ^
./Main.c:70:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &from, &to); from--; to--;
   ^
./Main.c:77:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &from, &to); from--; to--;
   ^
#include <stdio.h>
#include <stdlib.h>
#define N_MAX 100010
#define M_MAX 100010
#define BIG(i,j) (i >= j ? i : j)
#define SMALL(i,j) (i <= j ? i : j)

long long n,m,t;
typedef struct{
	long long treasure;
	struct list *hp [2];
}root_t;
typedef struct list{
	long long town;
	long long time;
	struct list *np;
}edge_t;

root_t root [N_MAX] = {0};
long long array [N_MAX * 2] = {0};

void make_node(long long a,long long b,long long c,long long check)
{
	edge_t *tail,*p;

	p = malloc(sizeof(edge_t));
	p->town = b;
	p->time = c;
	p->np = NULL;
	if(root [a].hp [check] == NULL){
		root [a].hp [check] = p;
	}
	else{
		tail = root [a].hp [check];
		while(tail->np != NULL){
			tail = tail->np;
		}
		tail->np = p;
	}
}

long long pop_heap(long long cost [],long long num)
{
	long long i = 0,j,ret;

	ret = array [0];
	while(1){
		j = i * 2 + 1;
		if(j + 1 < num - 1 && cost [array [j]] < cost [array [j + 1]] && 
		   cost [array [j]] < cost [array [num - 1]]){
			array [i] = array [j];
			i = j;
		}
		else if(j + 1 < num - 1 && cost [array [j]] > cost [array [j + 1]] && 
		        cost [array [j + 1]] < cost [array [num - 1]]){
			array [i] = array [j + 1];
			i = j + 1;
		}
		else if(j < num - 1 && cost [array [j]] < cost [array [num - 1]]){
			array [i] = array [j];
			i = j;
		}
		else{
			break;
		}
	}
	array [i] = array [num - 1];
	array [num - 1] = -1;

	return ret;
}

void push_heap(long long cost [],long long num,long long x)
{
	long long i = num,j;

	while(1){
		j = (i - 1) / 2;
		if(i < 1 || cost [array [j]] <= cost [x]){
			break;
		}
		array [i] = array [j];
		i = j;
	}
	array [i] = x;
}

void dijk(long long cost [],int check)
{
	long long i,save = 0,num = 1;
	char visited [N_MAX] = {0};
	edge_t *p;

	for(i = 1;i < n;i++){
		array [i] = -1;
	}
	array [0] = 0;
	for(i = 1;i < n;i++){
		cost [i] = t;
	}
	cost [0] = 0;

	while(1){
		if(array [0] != -1){
			save = pop_heap(cost,num--);
			if(visited [save]){
				continue;
			}
		}
		else{
			break;
		}
		visited [save] = 1;
		p = root [save].hp [check];
		while(p != NULL){
			if(!visited [p->town]){
				cost [p->town] = SMALL(cost [p->town],cost [save] + p->time);
				push_heap(cost,num++,p->town);
			}
			p = p->np;
		}
	}
}

int main(void)
{
	long long i,j,a,b,c;
	long long cost_go [N_MAX] = {0},cost_re [N_MAX] = {0};
	long long ans;
	edge_t *p;

	scanf("%lld %lld %lld",&n,&m,&t);
	for(i = 0;i < n;i++){
		scanf("%lld",&a);
		root [i].treasure = a;
	}
	for(i = 0;i < m;i++){
		scanf("%lld %lld %lld",&a,&b,&c);
		make_node(a - 1,b - 1,c,0);
		make_node(b - 1,a - 1,c,1);
	}

	dijk(cost_go,0);
	dijk(cost_re,1);

	for(i = 0,ans = 0;i < n;i++){
		ans = BIG(ans,((long long) t - cost_go [i] - cost_re [i]) * root [i].treasure);
	}
	printf("%lld\n",ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:132:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld %lld",&n,&m,&t);
  ^
./Main.c:134:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&a);
   ^
./Main.c:138:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld %lld",&a,&b,&c);
   ^
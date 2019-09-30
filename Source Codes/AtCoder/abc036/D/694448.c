#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007LL
#define N_MAX 100000

typedef struct list
{
	long long island;
	struct list *np;
}edge_t;
edge_t *hp [N_MAX] = {NULL};

long long dp_white [N_MAX] = {0};
long long dp_black [N_MAX] = {0};

void insert(long long a,long long b);
long long dfs_white(long long root,long long child);
long long dfs_black(long long root,long long child);

void insert(long long a,long long b)
{
	edge_t *p = hp [a];

	if(hp [a] == NULL){
		hp [a] = malloc(sizeof(edge_t));
		p = hp [a];
	}
	else{
		while(p->np != NULL){
			p = p->np;
		}
		p->np = malloc(sizeof(edge_t));
		p = p->np;
	}
	p->island = b;
	p->np = NULL;
}

long long dfs_white(long long parent,long long child)
{
	edge_t *p = hp [child];
	long long ret = 1;
	
	if(dp_white [child]){
		return dp_white [child];
	}

	while(p != NULL){
		if(p->island != parent){
			ret *= dfs_black(child,p->island) % MOD;
			ret %= MOD;
		}
		p = p->np;
	}
	
	dp_white [child] = ret;

	return ret;
}

long long dfs_black(long long parent,long long child)
{
	edge_t *p = hp [child];
	long long ret1 = 1,ret2 = 1;

	if(dp_black [child]){
		return dp_black [child];
	}
	
	
	while(p != NULL){
		if(p->island != parent){
			ret1 *= dfs_white(child,p->island);
			ret2 *= dfs_black(child,p->island);
			ret1 %= MOD;
			ret2 %= MOD;
		}
		p = p->np;
	}
	
	dp_black [child] = (ret1 + ret2) % MOD;
	
	return (ret1 + ret2) % MOD;
}

int main(void)
{
	long long i,n,a,b;
	edge_t *p;

	scanf("%lld",&n);
	for(i = 0;i < n - 1;i++){
		scanf("%lld %lld",&a,&b);
		insert(a - 1,b - 1);
		insert(b - 1,a - 1);
	}

	printf("%lld\n",dfs_black(0,0));

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:91:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:93:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld",&a,&b);
   ^
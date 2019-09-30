#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p (int)(1e9 + 7)

int MOD(int a){
	a %= p;
	return a >= 0 ? a : a + p;
}

typedef struct {
	int N;
	int *u;
	int *u_rank;
}union_find;

union_find *make_union_find(int N){
	int i;
	union_find *uf = (union_find *)malloc(sizeof(union_find));
	uf->N = N;
	uf->u = (int *)malloc(sizeof(int) * N);
	uf->u_rank = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		uf->u[i] = i;
		uf->u_rank[i] = 1;
	}
	return uf;
}

int root_uf(int x, union_find *uf){
	int *u = uf->u;
	if(u[x] == x){
		return x;
	}
	else{
		u[x] = root_uf(u[x], uf);
		return u[x];
	}
}

void combine_uf(int x, int y, union_find *uf){
	int x_root = root_uf(x, uf);
	int y_root = root_uf(y, uf);
	int *u = uf->u;
	int *u_rank = uf->u_rank;
	if(x_root == y_root){
		return;
	}
	else if(u_rank[x_root] < u_rank[y_root]){
		u[x_root] = y_root;
		u_rank[y_root] += u_rank[x_root];
		u_rank[x_root] = 0;
	}
	else{
		u[y_root] = x_root;
		u_rank[x_root] += u_rank[y_root];
		u_rank[y_root] = 0;
	}
}

//x?y????????????1?,???????0???
int is_same_union_uf(int x, int y, union_find *uf){
	if(root_uf(x, uf) == root_uf(y, uf)){
		return 1;
	}
	else{
		return 0;
	}
}

//x?????????????
int rank_uf(int x, union_find *uf){
	return uf->u_rank[root_uf(x, uf)];
}

typedef struct {
	int c;
	int w;
	int i;
}pair;

signed compair(const void *a, const void *b){
	int sub = ((pair *)a)->w - ((pair *)b)->w;
	if(sub < 0){
		return -1;
	}
	else if(sub == 0){
		return 0;
	}
	else{
		return 1;
	}
}

signed main(){
	int N, X, Y, i, j;
	scanf("%lld%lld%lld", &N, &X, &Y);
	pair *ps = (pair *)malloc(sizeof(pair) * N);
	int *num_c = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		num_c[i] = 0;
	}
	for(i = 0; i < N; i++){
		scanf("%lld%lld", &ps[i].c, &ps[i].w);
		ps[i].c--;
		num_c[ps[i].c]++;
	}
	qsort(ps, N, sizeof(pair), compair);
	pair **cs = (pair **)malloc(sizeof(pair *) * N);
	for(i = 0; i < N; i++){
		ps[i].i = i;
		cs[i] = (pair *)malloc(sizeof(pair) * num_c[i]);
		num_c[i] = 0;
	}
	int *index = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
//		printf("cs[%lld][%lld] = (%lld, %lld, %lld)\n", ps[i].c, num_c[ps[i].c], ps[i].c, ps[i].w, ps[i].i);
		cs[ps[i].c][num_c[ps[i].c]] = ps[i];
		index[i] = num_c[ps[i].c];
		num_c[ps[i].c]++;
	}

/*	printf("ps:\n");
	for(i = 0; i < N; i++){
		printf("(%lld, %lld, %lld) ", ps[i].c, ps[i].w, ps[i].i);
	}
	printf("\n");
	printf("cs:\n");
	for(i = 0; i < N; i++){
		printf("%lld: ", i);
		for(j = 0; j < num_c[i]; j++){
			printf("(%lld, %lld, %lld) ", cs[i][j].c, cs[i][j].w, cs[i][j].i);
		}
		printf("\n");
	}
	printf("index:\n");
	for(i = 0; i < N; i++){
		printf("%lld ", index[i]);
	}
	printf("\n");
*/
	union_find *uf = make_union_find(N);
	for(i = 0; i < N; i++){
		for(j = 0; j < num_c[i]; j++){
			if(cs[i][0].w + cs[i][j].w <= X){
				combine_uf(cs[i][0].i, cs[i][j].i, uf);
			}
		}
	}
	for(i = 0; i < N; i++){
		if(ps[0].w + ps[i].w <= Y && ps[0].c != ps[i].c){
			combine_uf(0, i, uf);
		}
	}
	for(i = 0; i < N && ps[i].c == ps[0].c; i++);
	if(i < N){
		for(j = 0; j < N; j++){
			if(ps[i].w + ps[j].w <= Y && ps[i].c != ps[j].c){
				combine_uf(i, j, uf);
			}
		}
	}

	int *fact = (int *)malloc(sizeof(int) * (N + 1));
	fact[0] = 1;
	for(i = 1; i <= N; i++){
		fact[i] = MOD(fact[i - 1] * i);
	}
	int *fact_inv = (int *)malloc(sizeof(int) * (N + 1));
	fact_inv[1] = 1;
	for(i = 2; i <= N; i++){
		fact_inv[i] = MOD(-(p / i) * fact_inv[p % i]);
	}
	fact_inv[0] = 1;
	for(i = 1; i <= N; i++){
		fact_inv[i] = MOD(fact_inv[i - 1] * fact_inv[i]);
	}
/*	for(i = 0; i <= N; i++){
		printf("(fact * fact_inv)[%lld] = %lld\n", i, MOD(fact[i] * fact_inv[i]));
	}
*/
	int ans = 1;
	for(i = 0; i < N; i++){
		if(root_uf(i, uf) == i){
			ans = MOD(ans * fact[rank_uf(i, uf)]);
		}
	}
	for(i = 0; i < N; i++){
		for(j = 0; j < num_c[i] && root_uf(cs[i][0].i, uf) == root_uf(cs[i][j].i, uf); j++);
		ans = MOD(ans * fact_inv[j]);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:97:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld", &N, &X, &Y);
  ^
./Main.c:104:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &ps[i].c, &ps[i].w);
   ^
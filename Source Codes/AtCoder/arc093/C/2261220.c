#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p (int)(1e9 + 7)
#define ms_valtype edge

typedef struct {
	int U;
	int V;
	int W;
}edge;

//????
int compare_ms(ms_valtype a, ms_valtype b){
	return a.W - b.W;
}

//??
void sort_sub(ms_valtype *origin, int left, int right, ms_valtype *tmp){
	if(right - left > 1){
		int i, j, k, half = (left + right) / 2;
		sort_sub(origin, left, half, tmp);
		sort_sub(origin, half, right, tmp);
		for(i = left; i < right; i++){
			tmp[i] = origin[i];
		}
		for(i = left, j = left, k = half; i < right; i++){
			if(k == right){
				origin[i] = tmp[j];
				j++;
			}
			else if(compare_ms(tmp[j], tmp[k]) <= 0 && j < half){
				origin[i] = tmp[j];
				j++;
			}
			else{
				origin[i] = tmp[k];
				k++;
			}
		}
	}
}

void sort(ms_valtype *origin, int N){
	ms_valtype *tmp = (ms_valtype *)malloc(sizeof(ms_valtype) * N);
	sort_sub(origin, 0, N, tmp);
	free(tmp);
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
		(uf->u)[i] = i;
		(uf->u_rank)[i] = 1;
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
	return (uf->u_rank)[root_uf(x, uf)];
}

int power(int a, int N){
	if(N == 0){
		return 1;
	}
	else if(N % 2 == 0){
		return power((a * a) % p, N / 2);
	}
	else{
		return (a * power(a, N - 1)) % p;
	}
}

signed main(){
	int N, M, X, i, j;
	scanf("%lld%lld", &N, &M);
	scanf("%lld", &X);
	edge *Es = (edge *)malloc(sizeof(edge) * M);
	for(i = 0; i < M; i++){
		scanf("%lld%lld%lld", &Es[i].U, &Es[i].V, &Es[i].W);
		Es[i].U--;
		Es[i].V--;
	}
	int *MST = (int *)malloc(sizeof(int) * M);
	for(i = 0; i < M; i++){
		MST[i] = 0;
	}
	sort(Es, M);
	union_find *uf;
	for(i = 0; i < M; i++){
		uf = make_union_find(N);
		combine_uf(Es[i].U, Es[i].V, uf);
		MST[i] = Es[i].W;
		for(j = 0; j < M; j++){
			if(j != i && is_same_union_uf(Es[j].U, Es[j].V, uf) == 0){
				combine_uf(Es[j].U, Es[j].V, uf);
				MST[i] += Es[j].W;
			}
		}
	}
	int less = 0, equal = 0, more = 0;
	for(i = 0; i < M; i++){
		if(MST[i] < X){
			less++;
		}
		else if(MST[i] == X){
			equal++;
		}
		else{
			more++;
		}
	}
//	printf("less = %lld\n", less);
//	printf("equal = %lld\n", equal);
//	printf("more = %lld\n", more);
	if(more == N){
		printf("0\n");
		return 0;
	}
	if(MST[0] == X){
		equal--;
	}
	int ans = (power(2, more) * (power(2, equal) - 1) * 2) % p;
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:129:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &M);
  ^
./Main.c:130:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &X);
  ^
./Main.c:133:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld", &Es[i].U, &Es[i].V, &Es[i].W);
   ^
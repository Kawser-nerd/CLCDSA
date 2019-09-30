#include <stdio.h>
#include <stdlib.h>

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

typedef struct {
	int u;
	int v;
}pair;

int compair(const void *a, const void *b){
	return ((pair *)a)->u - ((pair *)b)->u;
}

int main(){
	int N, M, s, i, j, tmp;
	scanf("%d%d%d", &N, &M, &s);
	s--;
	pair *ps = (pair *)malloc(sizeof(pair) * (M + 1));
	ps[0].u = -1;
	ps[0].v = -1;
	for(i = 1; i <= M; i++){
		scanf("%d%d", &ps[i].u, &ps[i].v);
		ps[i].u--;
		ps[i].v--;
		if(ps[i].u > ps[i].v){
			tmp = ps[i].u;
			ps[i].u = ps[i].v;
			ps[i].v = tmp;
		}
	}
	qsort(ps, M + 1, sizeof(pair), compair);
	union_find *uf = make_union_find(N);
	int *ans = (int *)malloc(sizeof(int) * N);
	for(i = N - 1, j = M; i >= 0; i--){
//		printf("i = %d\n", i);
		while(ps[j].u >= i){
//			printf("j = %d\n", j);
			combine_uf(ps[j].u, ps[j].v, uf);
			j--;
		}
		if(is_same_union_uf(s, i, uf) == 1){
			ans[i] = 1;
		}
		else{
			ans[i] = 0;
		}
	}
	for(i = 0; i < N; i++){
		if(ans[i] == 1){
			printf("%d\n", i + 1);
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:80:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &M, &s);
  ^
./Main.c:86:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &ps[i].u, &ps[i].v);
   ^
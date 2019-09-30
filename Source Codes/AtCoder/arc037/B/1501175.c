#include <stdio.h>
#include <stdlib.h>

#define inf (int)(1e9);

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

int root(int x, union_find *uf){
	int *u = uf->u;
	if(u[x] == x){
		return x;
	}
	else{
		u[x] = root(u[x], uf);
		return u[x];
	}
}

void combine(int x, int y, union_find *uf){
	int x_root = root(x, uf);
	int y_root = root(y, uf);
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
int is_same_union(int x, int y, union_find *uf){
	if(root(x, uf) == root(y, uf)){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	int N, M, u, v, i, ans = 0;
	scanf("%d%d", &N, &M);
	union_find *uf = make_union_find(N);
	for(i = 0; i < M; i++){
		scanf("%d%d", &u, &v);
		u--;
		v--;
		if(is_same_union(u, v, uf) == 1){
			(uf->u_rank)[root(u, uf)] = -inf;
		}
		else{
			combine(u, v, uf);
		}
	}
	for(i = 0; i < N; i++){
		if((uf->u_rank)[i] > 0){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:68:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:71:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &u, &v);
   ^
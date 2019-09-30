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

//x?????????????
int rank(int x, union_find *uf){
	return (uf->u_rank)[root(x, uf)];
}

int main(){
	int N = 10, i, j, k, l;
	char **A = (char **)malloc(sizeof(char *) * N);
	for(i = 0; i < N; i++){
		A[i] = (char *)malloc(sizeof(char) * (N + 1));
		scanf("%s", A[i]);
	}
	union_find *origin_uf = make_union_find(N * N + 1);
	for(i = 0; i < N; i++){
		for(j = 1; j < N; j++){
			if(A[i][j] == 'o' && A[i][j - 1] == 'o'){
				combine(i * N + j, i * N + (j - 1), origin_uf);
			}
		}
	}
	for(i = 1; i < N; i++){
		for(j = 0; j < N; j++){
			if(A[i][j] == 'o' && A[i - 1][j] == 'o'){
				combine(i * N + j, (i - 1) * N + j, origin_uf);
			}
		}
	}
	union_find *uf = make_union_find(N * N + 1);
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			for(k = 0; k <= N * N; k++){
				uf->u[k] = origin_uf->u[k];
				uf->u_rank[k] = origin_uf->u_rank[k];
			}
			if(i > 0){
				if(A[i - 1][j] == 'o'){
					combine(i * N + j, (i - 1) * N + j, uf);
				}
			}
			if(i < N - 1){
				if(A[i + 1][j] == 'o'){
					combine(i * N + j, (i + 1) * N + j, uf);
				}
			}
			if(j > 0){
				if(A[i][j - 1] == 'o'){
					combine(i * N + j, i * N + (j - 1), uf);
				}
			}
			if(j < N - 1){
				if(A[i][j + 1] == 'o'){
					combine(i * N + j, i * N + (j + 1), uf);
				}
			}
			for(k = 0; k < N; k++){
				for(l = 0; l < N; l++){
					if((k != i || l != j) && A[k][l] == 'x'){
						combine(k * N + l, N * N, uf);
					}
				}
			}
			if(rank(i * N + j, uf) + rank(N * N, uf) == N * N + 1){
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:74:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", A[i]);
   ^
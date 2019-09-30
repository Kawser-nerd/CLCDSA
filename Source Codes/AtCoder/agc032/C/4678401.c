#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int N;
	int *u;
	int *u_size;
}union_find;

union_find *make_union_find(int N){
	int i;
	union_find *uf = (union_find *)malloc(sizeof(union_find));
	uf->N = N;
	uf->u = (int *)malloc(sizeof(int) * N);
	uf->u_size = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		uf->u[i] = i;
		uf->u_size[i] = 1;
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
	int *u_size = uf->u_size;
	if(x_root == y_root){
		return;
	}
	else if(u_size[x_root] < u_size[y_root]){
		u[x_root] = y_root;
		u_size[y_root] += u_size[x_root];
		u_size[x_root] = 0;
	}
	else{
		u[y_root] = x_root;
		u_size[x_root] += u_size[y_root];
		u_size[y_root] = 0;
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
int size_uf(int x, union_find *uf){
	return uf->u_size[root_uf(x, uf)];
}

int main(){
	int N, M, i, j, k;
	scanf("%d%d", &N, &M);
	int *num = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		num[i] = 0;
	}
	int *a = (int *)malloc(sizeof(int) * M);
	int *b = (int *)malloc(sizeof(int) * M);
	for(i = 0; i < M; i++){
		scanf("%d%d", &a[i], &b[i]);
		a[i]--;
		b[i]--;
		num[a[i]]++;
		num[b[i]]++;
	}
	int count = 0;
	for(i = 0; i < N; i++){
		if(num[i] % 2 == 1){
			printf("No\n");
			return 0;
		}
	}
	for(i = 0; i < N; i++){
		if(num[i] >= 6){
			printf("Yes\n");
			return 0;
		}
		if(num[i] == 4){
			count++;
		}
	}
	if(count >= 3){
		printf("Yes\n");
		return 0;
	}
	if(count < 2){
		printf("No\n");
		return 0;
	}
	int **es = (int **)malloc(sizeof(int *) * N);
	int *now = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		es[i] = (int *)malloc(sizeof(int) * 4);
		now[i] = 0;
	}
	for(i = 0; i < M; i++){
		es[a[i]][now[a[i]]] = b[i];
		now[a[i]]++;
		es[b[i]][now[b[i]]] = a[i];
		now[b[i]]++;
	}

	union_find *uf = make_union_find(N);
	for(i = 0; i < M; i++){
		if(num[a[i]] < 4 && num[b[i]] < 4){
			combine_uf(a[i], b[i], uf);
		}
	}
	for(i = 0; i < N; i++){
		if(num[i] == 4){
			for(j = 0; j < 4; j++){
				for(k = j + 1; k < 4; k++){
					if(is_same_union_uf(es[i][j], es[i][k], uf) == 1){
						printf("Yes\n");
						return 0;
					}
				}
			}
		}
	}
	printf("No\n");

/*	srand(time(NULL));
	if(rand() % 2 == 0){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
*/	return 0;
} ./Main.c: In function ‘main’:
./Main.c:72:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:80:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a[i], &b[i]);
   ^
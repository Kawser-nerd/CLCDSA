#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int a;
	int b;
	int y;
}edge;

typedef struct {
	int num;
	int v;
	int w;
	int ans;
}info;

int compare_edge(const void *a, const void *b){
	return ((edge *)b)->y - ((edge *)a)->y;
}

int compare_w_info(const void *a, const void *b){
	return ((info *)b)->w - ((info *)a)->w;
}

int compare_num_info(const void *a, const void *b){
	return ((info *)a)->num - ((info *)b)->num;
}

int root(int a, int *array){
	if(array[a] == a){
		return a;
	}
	else{
		array[a] = root(array[a], array);
		return array[a];
	}
}

void combine(int a, int b, int *array, int *array_rank){
	int a_root = root(a, array);
	int b_root = root(b, array);
	if(a_root == b_root){
		return;
	}
	else if(array_rank[a_root] < array_rank[b_root]){
		array[a_root] = b_root;
		array_rank[b_root] += array_rank[a_root];
	}
	else{
		array[b_root] = a_root;
		array_rank[a_root] += array_rank[b_root];
	}
}

int main(){
	int N, M, i, j = 0;
	scanf("%d%d", &N, &M);
	int *vertex = (int *)malloc(sizeof(int) * N);
	int *vertex_size = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		vertex[i] = i;
		vertex_size[i] = 1;
	}
	edge *E = (edge *)malloc(sizeof(edge) * M);
	for(i = 0; i < M; i++){
		scanf("%d%d%d", &E[i].a, &E[i].b, &E[i].y);
		E[i].a--;
		E[i].b--;
	}
	int Q;
	scanf("%d", &Q);
	info *P = (info *)malloc(sizeof(info) * Q);
	for(i = 0; i < Q; i++){
		P[i].num = i;
		scanf("%d%d", &P[i].v, &P[i].w);
		P[i].v--;
	}
	qsort(E, M, sizeof(edge), compare_edge);
	qsort(P, Q, sizeof(info), compare_w_info);
	for(i = 0; i < Q; i++){
		for(; E[j].y > P[i].w && j < M; j++){
			combine(E[j].a, E[j].b, vertex, vertex_size);
		}
		P[i].ans = vertex_size[root(P[i].v, vertex)];
	}

	qsort(P, Q, sizeof(info), compare_num_info);
	for(i = 0; i < Q; i++){
		printf("%d\n", P[i].ans);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:57:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:66:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &E[i].a, &E[i].b, &E[i].y);
   ^
./Main.c:71:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &Q);
  ^
./Main.c:75:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &P[i].v, &P[i].w);
   ^
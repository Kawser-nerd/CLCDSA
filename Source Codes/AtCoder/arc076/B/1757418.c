#include <stdio.h>
#include <stdlib.h>
#define ms_valtype data

typedef struct {
	int num;
	int x;
	int y;
}data;

//????
int compare_ms_num(ms_valtype a, ms_valtype b){
	return a.num - b.num;
}

int compare_ms_x(ms_valtype a, ms_valtype b){
	return a.x - b.x;
}

int compare_ms_y(ms_valtype a, ms_valtype b){
	return a.y - b.y;
}

//??
void sort_sub(ms_valtype *origin, int left, int right, ms_valtype *tmp, int (*compare_ms)(ms_valtype a, ms_valtype b)){
	if(right - left > 1){
		int i, j, k, half = (left + right) / 2;
		sort_sub(origin, left, half, tmp, compare_ms);
		sort_sub(origin, half, right, tmp, compare_ms);
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

void sort(ms_valtype *origin, int N, int (*compare_ms)(ms_valtype a, ms_valtype b)){
	ms_valtype *tmp = (ms_valtype *)malloc(sizeof(ms_valtype) * N);
	sort_sub(origin, 0, N, tmp, compare_ms);
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

int main(){
	int N, i, ans = 0;
	scanf("%d", &N);
	data *v = (data *)malloc(sizeof(data) * N);
	for(i = 0; i < N; i++){
		v[i].num = i;
		scanf("%d%d", &v[i].x, &v[i].y);
	}
	data *e = (data *)malloc(sizeof(data) * 2 * (N - 1));
	sort(v, N, compare_ms_x);
	for(i = 0; i < N - 1; i++){
		e[i].num = v[i + 1].x - v[i].x;
		e[i].x = v[i].num;
		e[i].y = v[i + 1].num;
	}
	sort(v, N, compare_ms_y);
	for(i = 0; i < N - 1; i++){
		e[N - 1 + i].num = v[i + 1].y - v[i].y;
		e[N - 1 + i].x = v[i].num;
		e[N - 1 + i].y = v[i + 1].num;
	}
	sort(e, 2 * (N - 1), compare_ms_num);
	union_find *uf = make_union_find(N);
	for(i = 0; i < 2 * (N - 1); i++){
		if(root_uf(e[i].x, uf) != root_uf(e[i].y, uf)){
			combine_uf(e[i].x, e[i].y, uf);
			ans += e[i].num;
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:123:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:127:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &v[i].x, &v[i].y);
   ^
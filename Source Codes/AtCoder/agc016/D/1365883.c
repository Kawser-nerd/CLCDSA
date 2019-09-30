#include <stdio.h>
#include <stdlib.h>

#define datatype pair

typedef struct {
	int val;
	int pos;
}pair;

//????
int compare(datatype a, datatype b){
	if(a.val < b.val){
		return -1;
	}
	else if(a.val > b.val){
		return 1;
	}
	else{
		return 0;
	}
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

//??
void sort_sub(datatype *origin, int left, int right, datatype *tmp){
	if(right - left > 1){
		int i, j, k, half = (left + right) / 2;
		sort_sub(origin, left, half, tmp);
		sort_sub(origin, half, right, tmp);
		for(i = left; i < right; i++){
			tmp[i] = origin[i];
		}
		for(i = left, j = left, k = half; i < right; i++){
			if((compare(tmp[j], tmp[k]) <= 0 && j < half) || k == right){
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

void sort(datatype *origin, int N){
	datatype *tmp = (datatype *)malloc(sizeof(datatype) * N);
	sort_sub(origin, 0, N, tmp);
}

int main(){
	int N, x, i, j, k, prev;
	scanf("%d", &N);
	int *a0 = (int *)malloc(sizeof(int) * (N + 1));
	int *b0 = (int *)malloc(sizeof(int) * (N + 1));
	int *a = (int *)malloc(sizeof(int) * (N + 1));
	int *b = (int *)malloc(sizeof(int) * (N + 1));
	x = 0;
	for(i = 0; i < N; i++){
		scanf("%d", &a0[i]);
		x ^= a0[i];
	}
	a0[N] = x;
	x = 0;
	for(i = 0; i < N; i++){
		scanf("%d", &b0[i]);
		x ^= b0[i];
	}
	b0[N] = x;
	for(i = 0, j = 0; i < N; i++){
		if(a0[i] != b0[i]){
			a[j] = a0[i];
			b[j] = b0[i];
			j++;
		}
	}
	a[j] = a0[N];
	b[j] = b0[N];
	N = j;
	if(N == 0){
		printf("0\n");
		return 0;
	}
	pair *a2 = (pair *)malloc(sizeof(pair) * (N + 1));
	pair *b2 = (pair *)malloc(sizeof(pair) * (N + 1));
	for(i = 0; i <= N; i++){
		a2[i].val = a[i];
		b2[i].val = b[i];
		a2[i].pos = i;
		b2[i].pos = i;
	}
	sort(a2, N + 1);
	sort(b2, N + 1);/*
	for(i = 0; i <= N; i++){
		printf("a[%d] = %d ", i, a[i]);
	}
	printf("\n");
	for(i = 0; i <= N; i++){
		printf("b[%d] = %d ", i, b[i]);
	}
	printf("\n");*/
	for(i = 0, j = -1, prev = -1; i <= N; i++){
		if(a2[i].val != b2[i].val){
			printf("-1\n");
			return 0;
		}
		if(prev != a2[i].val){
			j++;
		}
		prev = a2[i].val;
		a[a2[i].pos] = j;
		b[b2[i].pos] = j;
	}
	j++;
	int *uni = (int *)malloc(sizeof(int) * j);
	int *uni_rank = (int *)malloc(sizeof(int) * j);
	int *exist = (int *)malloc(sizeof(int) * j);
	for(i = 0; i < j; i++){
		uni[i] = i;
		uni_rank[i] = 1;
		exist[i] = -1;
	}/*
	for(i = 0; i <= N; i++){
		printf("a[%d] = %d ", i, a[i]);
	}
	printf("\n");
	for(i = 0; i <= N; i++){
		printf("b[%d] = %d ", i, b[i]);
	}
	printf("\n");*/
	for(i = 0; i <= N; i++){
		combine(a[i], b[i], uni, uni_rank);
	}
	for(i = 0, k = 0; i < j; i++){
		//printf("root(%d) = %d\n", i, root(i, uni));
		if(exist[root(i, uni)] == -1){
			exist[root(i, uni)] = 1;
			k++;
		}
	}
	//printf("N = %d\nk = %d\n", N, k);
	printf("%d\n", N + k - 1);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:79:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:86:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a0[i]);
   ^
./Main.c:92:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &b0[i]);
   ^
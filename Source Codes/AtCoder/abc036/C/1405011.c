#include <stdio.h>
#include <stdlib.h>

#define datatype pair

typedef struct {
	int a;
	int b;
}pair;

//????
int compare(datatype a, datatype b){
	if(a.a < b.a){
		return -1;
	}
	else if(a.a > b.a){
		return 1;
	}
	else{
		return 0;
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
	int N, i;
	scanf("%d", &N);
	pair *p = (pair *)malloc(sizeof(pair) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &(p[i].a));
		p[i].b = i;
	}
	sort(p, N);
	int *b = (int *)malloc(sizeof(int) * N);
	int old = -1, now = -1;
	for(i = 0; i < N; i++){
		if(p[i].a > old){
			old = p[i].a;
			now++;
		}
		b[p[i].b] = now;
	}
	for(i = 0; i < N; i++){
		printf("%d\n", b[i]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:53:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:56:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &(p[i].a));
   ^
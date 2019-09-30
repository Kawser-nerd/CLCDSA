#include <stdio.h>
#include <stdlib.h>
#define datatype student

typedef struct {
	int h;
	int w;
	int D;
}student;

//????
int D_compare(datatype a, datatype b){
	return a.D - b.D;
}

int w_compare(datatype a, datatype b){
	return a.w - b.w;
}

//??
void sort_sub(datatype *origin, int left, int right, datatype *tmp, int (*comp)(datatype a, datatype b)){
	if(right - left > 1){
		int i, j, k, half = (left + right) / 2;
		sort_sub(origin, left, half, tmp, comp);
		sort_sub(origin, half, right, tmp, comp);
		for(i = left; i < right; i++){
			tmp[i] = origin[i];
		}
		for(i = left, j = left, k = half; i < right; i++){
			if(k == right){
				origin[i] = tmp[j];
				j++;
			}
			else if(comp(tmp[j], tmp[k]) <= 0 && j < half){
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

void sort(datatype *origin, int N, int (*comp)(datatype a, datatype b)){
	datatype *tmp = (datatype *)malloc(sizeof(datatype) * N);
	sort_sub(origin, 0, N, tmp, comp);
	free(tmp);
}

int ABS(int x){
	return x >= 0 ? x : -x;
}

int main(){
	int N, M, x0, a, p, i, j;
	long long ans = 0;
	scanf("%d%d", &N, &M);
	scanf("%d%d%d", &x0, &a, &p);
	student *s = (student *)malloc(sizeof(student) * N * M);
	s[0].h = 0;
	s[0].w = 0;
	s[0].D = x0;
	for(i = 1; i < N * M; i++){
		s[i].h = i / M;
		s[i].w = i % M;
		s[i].D = (s[i - 1].D + a) % p;
	}
	sort(s, N * M, D_compare);
	for(i = 0; i < N; i++){
		sort(&s[i * M], M, w_compare);
		for(j = 0; j < M; j++){
			ans += ABS(s[i * M + j].h - i) + ABS(s[i * M + j].w - j);
		}
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:59:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:60:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &x0, &a, &p);
  ^
#include <stdio.h>
#include <stdlib.h>
#define ms_valtype int

typedef struct {
	int a;
	int b;
}pair;

//????
int compare_ms(ms_valtype a, ms_valtype b){
	return a - b;
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

int main(){
	int R, C, K, N, i, j, k, l;
	long long ans = 0;
	scanf("%d%d%d", &R, &C, &K);
	scanf("%d", &N);
	int *H = (int *)malloc(sizeof(int) * R);
	int *W = (int *)malloc(sizeof(int) * C);
	int *r = (int *)malloc(sizeof(int) * N);
	int *c = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < R; i++){
		H[i] = 0;
	}
	for(j = 0; j < C; j++){
		W[j] = 0;
	}
	for(i = 0; i < N; i++){
		scanf("%d%d", &r[i], &c[i]);
		r[i]--;
		c[i]--;
		H[r[i]]++;
		W[c[i]]++;
	}
	for(i = 0; i < N; i++){
		if(H[r[i]] + W[c[i]] == K + 1){
			ans++;
		}
		else if(H[r[i]] + W[c[i]] == K){
			ans--;
		}
	}
	sort(H, R);
	sort(W, C);
	for(i = 1, k = 1; i < R; i++){
		if(H[i] != H[i - 1]){
			k++;
		}
	}
	for(j = 1, l = 1; j < C; j++){
		if(W[j] != W[j - 1]){
			l++;
		}
	}
	pair *Ph = (pair *)malloc(sizeof(pair) * k);
	pair *Pw = (pair *)malloc(sizeof(pair) * l);
	Ph[0].a = H[0];
	Ph[0].b = 1;
	for(i = 1, j = 0; i < R; i++){
		if(H[i] == Ph[j].a){
			Ph[j].b++;
		}
		else{
			j++;
			Ph[j].a = H[i];
			Ph[j].b = 1;
		}
	}
	Pw[0].a = W[0];
	Pw[0].b = 1;
	for(i = 1, j = 0; i < C; i++){
		if(W[i] == Pw[j].a){
			Pw[j].b++;
		}
		else{
			j++;
			Pw[j].a = W[i];
			Pw[j].b = 1;
		}
	}
	for(i = 0, j = l - 1; i < k && j >= 0; ){
		if(Ph[i].a + Pw[j].a == K){
			ans += Ph[i].b * Pw[j].b;
			i++;
			j--;
		}
		else if(Ph[i].a + Pw[j].a > K){
			j--;
		}
		else{
			i++;
		}
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:50:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &R, &C, &K);
  ^
./Main.c:51:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:63:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &r[i], &c[i]);
   ^
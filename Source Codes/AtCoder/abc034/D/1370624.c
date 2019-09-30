#include <stdio.h>
#include <stdlib.h>

#define datatype double

typedef enum{
	false,
	true
}Boolean;

//????
int compare(datatype a, datatype b){
	if(a < b){
		return -1;
	}
	else if(a > b){
		return 1;
	}
	else{
		return 0;
	}
}

void sort_sub(datatype *origin, int left, int right, datatype *tmp){
	if(right - left > 1){
		int i, j, k, half = (left + right) / 2;
		sort_sub(origin, left, half, tmp);
		sort_sub(origin, half, right, tmp);
		for(i = left; i < right; i++){
			tmp[i] = origin[i];
		}
		for(i = left, j = left, k = half; i < right; i++){
			if((compare(tmp[j], tmp[k]) >= 0 && j < half) || k == right){
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

Boolean can_achieve(int N, int K, int *w, int *p, double h){
	int i;
	double *s = (double *)malloc(sizeof(double) * N);
	for(i = 0; i < N; i++){
		s[i] = (p[i] - h) * w[i];
	}
	sort(s, N);
	double sum = 0;
	for(i = 0; i < K; i++){
		sum += s[i];
	}
	if(sum >= 0){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	int N, K, i;
	scanf("%d%d", &N, &K);
	int *w = (int *)malloc(sizeof(int) * N);
	int *p = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d%d", &w[i], &p[i]);
	}
	double l, r, h;
	for(l = 0, r = 100; r - l > 1e-10; ){
		//printf("test:(l, r) = (%f, %f)\n", l, r);
		h = (r + l) / 2;
		if(can_achieve(N, K, w, p, h) == true){
			l = h;
		}
		else{
			r = h;
		}
	}
	printf("%2.9f\n", l);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:71:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &K);
  ^
./Main.c:75:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &w[i], &p[i]);
   ^
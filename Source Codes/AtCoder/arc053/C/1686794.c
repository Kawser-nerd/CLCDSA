#include <stdio.h>
#include <stdlib.h>
#define int long long
#define datatype pair

typedef struct {
	int a;
	int b;
}pair;

//????
int compare(datatype x, datatype y){
	if(x.a - x.b < 0 && y.a - y.b < 0){
		return x.a - y.a;
	}
	else if(x.a - x.b >= 0 && y.a - y.b < 0){
		return 1;
	}
	else if(x.a - x.b < 0 && y.a - y.b >= 0){
		return -1;
	}
	else{
		return y.b - x.b;
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
			if(k == right){
				origin[i] = tmp[j];
				j++;
			}
			else if(compare(tmp[j], tmp[k]) <= 0 && j < half){
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
	free(tmp);
}

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

signed main(){
	int N, i, ans = 0, now = 0;
	scanf("%lld", &N);
	pair *p = (pair *)malloc(sizeof(pair) * N);
	for(i = 0; i < N; i++){
		scanf("%lld%lld", &p[i].a, &p[i].b);
	}
	sort(p, N);
	for(i = 0; i < N; i++){
		ans = max(ans, now + p[i].a);
		now += p[i].a - p[i].b;
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:70:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:73:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &p[i].a, &p[i].b);
   ^
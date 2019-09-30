#include <stdio.h>
#include <stdlib.h>
#define int long long
#define inf ((int)(1e18) + 1)
#define datatype int
#define p (int)(1e9 + 7)

//????
int compare(datatype a, datatype b){
	return a - b;
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
	free(tmp);
}

int MOD(int a){
	if(a >= 0){
		return a % p;
	}
	else{
		return p + a % p;
	}
}

int power(int a, int n){
	if(n == 0){
		return 1;
	}
	else if(n % 2 == 0){
		return power(MOD(a * a), n / 2);
	}
	else{
		return MOD(a * power(a, n - 1));
	}
}

signed main(){
	int N, A, B, i, amax = 0, amin, aminnum;
	scanf("%lld%lld%lld", &N, &A, &B);
	int *a = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &a[i]);
	}
	if(A == 1){
		sort(a, N);
		for(i = 0; i < N; i++){
			printf("%lld\n", a[i]);
		}
		return 0;
	}
	for(i = 0; i < N; i++){
		if(a[i] > amax){
			amax = a[i];
		}
	}
	while(1){
		if(B == 0){
			sort(a, N);
			for(i = 0; i < N; i++){
				printf("%lld\n", MOD(a[i]));
			}
			return 0;
		}
		amin = inf;
		for(i = 0; i < N; i++){
			if(a[i] < amin){
				amin = a[i];
				aminnum = i;
			}
		}
		if(amin >= amax){
			break;
		}
		a[aminnum] *= A;
		B--;
	}
	sort(a, N);
	int AvBJN = power(A, B / N);
	for(i = B % N; i < N; i++){
		printf("%lld\n", MOD(MOD(a[i]) * AvBJN));
	}
	for(i = 0; i < B % N; i++){
		printf("%lld\n", MOD(MOD(a[i]) * MOD(A * AvBJN)));
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:64:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld", &N, &A, &B);
  ^
./Main.c:67:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &a[i]);
   ^
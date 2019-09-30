#include <stdio.h>
#include <stdlib.h>

#define datatype lli
#define lli long long int

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

//??
lli inv_num_sub(datatype *origin, int left, int right, datatype *tmp){
	lli ans = 0;
	if(right - left > 1){
		int i, j, k, half = (left + right) / 2;
		ans += inv_num_sub(origin, left, half, tmp);
		ans += inv_num_sub(origin, half, right, tmp);
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
				ans += (lli)(k - i);
				k++;
			}
		}
	}
	return ans;
}

//i < j && a[i] > a[j] ????(i, j)??
//effect: sort???
lli inv_num(datatype *origin, int N){
	datatype *tmp = (datatype *)malloc(sizeof(datatype) * N);
	return inv_num_sub(origin, 0, N, tmp);
}

int main(){
	lli N, K, i;
	scanf("%lld%lld", &N, &K);
	lli *sum = (lli *)malloc(sizeof(lli) * (N + 1));
	sum[0] = 0;
	for(i = 1; i <= N; i++){
		scanf("%lld", &sum[i]);
		sum[i] += sum[i - 1] - K;
	}
	printf("%lld\n", N * (N + 1) / 2 - inv_num(sum, (int)(N + 1)));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:54:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &K);
  ^
./Main.c:58:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &sum[i]);
   ^
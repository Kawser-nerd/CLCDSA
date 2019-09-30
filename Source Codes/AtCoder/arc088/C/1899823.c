#include <stdio.h>
#include <stdlib.h>
#define int long long
#define max_size (int)(2e5 + 1)

typedef struct {
	char c;
	int val;
}pair;

#define inv_num_valtype pair

//????
int compare(inv_num_valtype a, inv_num_valtype b){
	return a.val - b.val;
}

//??
int inv_num_sub(inv_num_valtype *origin, int left, int right, inv_num_valtype *tmp){
	int ans = 0;
	if(right - left > 1){
		int i, j, k, half = (left + right) / 2;
		ans += inv_num_sub(origin, left, half, tmp);
		ans += inv_num_sub(origin, half, right, tmp);
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
				ans += k - i;
				k++;
			}
		}
	}
	return ans;
}

//i < j && a[i] > a[j] ????(i, j)??
//effect: sort???
int inv_num(inv_num_valtype *origin, int N){
	inv_num_valtype *tmp = (inv_num_valtype *)malloc(sizeof(inv_num_valtype) * N);
	return inv_num_sub(origin, 0, N, tmp);
}

signed main(){
	int N, i, odd_num, alf_int, ans = 0;
	char *S = (char *)malloc(sizeof(char) * max_size);
	int *alf_num = (int *)malloc(sizeof(int) * 26);
	int *alf_count = (int *)malloc(sizeof(int) * 26);
	for(i = 0; i < 26; i++){
		alf_num[i] = 0;
		alf_count[i] = 0;
	}
	scanf("%s", S);
	for(i = 0; S[i] != '\0'; i++){
		alf_num[(int)S[i] - (int)'a']++;
	}
	N = i;
	for(i = 0, odd_num = 0; i < 26; i++){
		odd_num += alf_num[i] % 2;
	}
	if(odd_num > 1){
		printf("-1\n");
		return 0;
	}
	pair *P = (pair *)malloc(sizeof(pair) * N);
	for(i = 0; i < N; i++){
		P[i].c = S[i];
		alf_int = (int)S[i] - (int)'a';
		alf_count[alf_int]++;
		if(alf_num[alf_int] % 2 == 0){
			if(alf_count[alf_int] <= alf_num[alf_int] / 2){
				P[i].val = 0;
			}
			else{
				P[i].val = 2;
			}
		}
		else{
			if(alf_count[alf_int] <= alf_num[alf_int] / 2){
				P[i].val = 0;
			}
			else if(alf_count[alf_int] == alf_num[alf_int] / 2 + 1){
				P[i].val = 1;
			}
			else{
				P[i].val = 2;
			}
		}
	}
	int **alf_number = (int **)malloc(sizeof(int *) * 26);
	for(i = 0; i < 26; i++){
		alf_number[i] = (int *)malloc(sizeof(int) * alf_num[i]);
		alf_count[i] = 0;
	}
	ans += inv_num(P, N);
//	printf("ans = %lld\n", ans);
	for(i = 0; i < N / 2; i++){
		P[i].val = N / 2 - i;
		alf_int = (int)P[i].c - (int)'a';
		alf_number[alf_int][alf_count[alf_int]] = P[i].val;
		alf_count[alf_int]++;
	}
	for(i = 0; i < 26; i++){
		alf_count[i] = 0;
	}
	for(i = N - 1; i >= (N + 1) / 2; i--){
		alf_int = (int)P[i].c - (int)'a';
//		printf("(i, alf_int) = (%lld, %lld)\n", i, alf_int);
//		printf("alf_count[alf_int] = %lld\n", alf_count[alf_int]);
		P[i].val = alf_number[alf_int][alf_count[alf_int]];
//		printf("P[i].val = %lld\n", P[i].val);
		alf_count[alf_int]++;
	}
/*	for(i = 0; i < N; i++){
		printf("(%c, %lld)\n", P[i].c, P[i].val);
	}
*/	ans += inv_num(&P[(N + 1) / 2], N / 2);
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:63:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^
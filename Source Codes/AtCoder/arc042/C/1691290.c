#include <stdio.h>
#include <stdlib.h>
#define datatype pair

typedef struct {
	int a;
	int b;
}pair;

//????
int compare(datatype a, datatype b){
	return b.a - a.a;
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
	return a >= b ? a : b;
}

int main(){
	int N, P, i, j, k, ans = 0;
	scanf("%d%d", &N, &P);
	pair *ab = (pair *)malloc(sizeof(pair) * (N + 1));
	for(i = 0; i < N; i++){
		scanf("%d%d", &ab[i].a, &ab[i].b);
	}
	ab[N].a = 0;
	ab[N].b = 0;
	sort(ab, N);
	int *dp = (int *)malloc(sizeof(int) * (P + ab[0].a + 1));
	for(i = 0; i <= P + ab[0].a; i++){
		dp[i] = 0;
	}
	for(i = ab[0].a, j = 0; i > 0; i--){
//		printf("i = %d\n", i);
		for(j = j; ab[j].a >= i && j < N; j++){
//			printf("j = %d\n", j);
			for(k = P + ab[0].a; k >= ab[j].a; k--){
				dp[k] = max(dp[k], dp[k - ab[j].a] + ab[j].b);
			}
/*			for(k = 0; k <= P + ab[0].a; k++){
				printf("%d  ", dp[k]);
			}
			printf("\n");
*/		}
		ans = max(ans, dp[P + i]);
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:53:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &P);
  ^
./Main.c:56:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &ab[i].a, &ab[i].b);
   ^
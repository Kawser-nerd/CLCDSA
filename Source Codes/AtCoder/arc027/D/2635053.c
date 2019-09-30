#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p (int)(1e9 + 7)

const int b = 1000;

int MOD(int a){
	if(a < p){
		return a;
	}
	else if(a < (p << 1)){
		return a - p;
	}
	else{
		return a % p;
	}
}

signed main(){
	int N, D, a, i, j, k, l;
	scanf("%lld", &N);
	int *h = (int *)malloc(sizeof(int) * b * ((N + 2 * b - 1) / b));
	for(i = 0; i < N; i++){
		scanf("%lld", &h[i]);
	}
	for(i = N; i < b * ((N + 2 * b - 1) / b); i++){
		h[i] = 1;
	}
	N = b * ((N + 2 * b - 1) / b);
	a = N / b;
	scanf("%lld", &D);
	int *s = (int *)malloc(sizeof(int) * D);
	int *t = (int *)malloc(sizeof(int) * D);
	int *ans = (int *)malloc(sizeof(int) * D);
	for(i = 0; i < D; i++){
		scanf("%lld%lld", &s[i], &t[i]);
		s[i]--;
		t[i]--;
	}
//	printf("(N, a, b) = (%lld, %lld, %lld)\n", N, a, b);
	int ***predp = (int ***)malloc(sizeof(int **) * (a - 1));
	for(i = 0; i < a - 1; i++){
		predp[i] = (int **)malloc(sizeof(int *) * 10);
		for(j = 0; j < 10; j++){
//			printf("(i, j) = (%lld, %lld)\n", i, j);
			predp[i][j] = (int *)malloc(sizeof(int) * (b + 10));
			for(k = 0; k < b + 10; k++){
				predp[i][j][k] = 0;
			}
			predp[i][j][j] = 1;
			for(k = j; k < b; k++){
				for(l = 1; l <= h[i * b + k]; l++){
					predp[i][j][k + l] = MOD(predp[i][j][k + l] + predp[i][j][k]);
				}
			}
		}
	}
	int *fst = (int *)malloc(sizeof(int) * (b + 10));
	int *lst = (int *)malloc(sizeof(int) * (b + 10));
	int **mid = (int **)malloc(sizeof(int *) * a);
	int bs, bt, ms, mt;
	for(i = 0; i < a; i++){
		mid[i] = (int *)malloc(sizeof(int) * 10);
	}
	for(i = 0; i < D; i++){
//		printf("i = %lld\n", i);
		for(j = 0; j < b + 10; j++){
			fst[j] = 0;
			lst[j] = 0;
		}
		for(j = 0; j < a; j++){
			for(k = 0; k < 10; k++){
				mid[j][k] = 0;
			}
		}
		bs = (s[i] + b) / b;
		bt = t[i] / b;
		ms = s[i] % b;
		mt = t[i] % b;
//		printf("(bs, bt) = (%lld, %lld)\n", bs, bt);
		if(bs > bt){
			fst[ms] = 1;
			for(j = ms; j < mt; j++){
				for(k = 1; k <= h[b * (bs - 1) + j]; k++){
					fst[j + k] = MOD(fst[j + k] + fst[j]);
				}
			}
			ans[i] = fst[mt];
		}
		else{
			fst[ms] = 1;
			for(j = ms; j < b; j++){
				for(k = 1; k <= h[b * (bs - 1) + j]; k++){
					fst[j + k] = MOD(fst[j + k] + fst[j]);
				}
			}
//			printf("test1\n");
			for(j = 0; j < 10; j++){
//				printf("%lld ", fst[b + j]);
				mid[bs][j] = fst[b + j];
			}
//			printf("\n");
			for(j = bs; j < bt; j++){
				for(k = 0; k < 10; k++){
					for(l = 0; l < 10; l++){
						mid[j + 1][l] = MOD(mid[j + 1][l] + mid[j][k] * predp[j][k][b + l]);
					}
				}
			}
//			printf("test2\n");
			for(j = 0; j < 10; j++){
//				printf("%lld ", mid[bt][j]);
				lst[j] = mid[bt][j];
			}
//			printf("\n");
			for(j = 0; j < mt; j++){
				for(k = 1; k <= h[b * bt + j]; k++){
					lst[j + k] = MOD(lst[j + k] + lst[j]);
				}
			}
			ans[i] = lst[mt];
		}
	}
	for(i = 0; i < D; i++){
		printf("%lld\n", ans[i]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &h[i]);
   ^
./Main.c:32:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &D);
  ^
./Main.c:37:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &s[i], &t[i]);
   ^
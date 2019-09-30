#include<stdio.h>

#define cmax 35
#define INFTY 1000000000

int Color_1[cmax] = { 0 };
int Color_2[cmax] = { 0 };
int Color_3[cmax] = { 0 };

int sum1[cmax] = { 0 };
int sum2[cmax] = { 0 };
int sum3[cmax] = { 0 };

int D[cmax][cmax];
int CIJ[510][510];

int main() {
	int N, C;
	int inp_int;
	int ans = INFTY;

	scanf("%d %d", &N, &C);
	for (int i = 1; i <= C; i++) {
		for (int j = 1; j <= C; j++) {
			scanf("%d", &inp_int);
			D[i][j] = inp_int;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &inp_int);
			CIJ[i][j] = inp_int;
		}
	}

	for (int i = 1; i <= 2*N; i+=3) {
		for (int j = 1; j <= i; j++) {
			if (j > N || i - j + 1 > N)continue;
			Color_1[CIJ[j][i - j + 1]]++;
		}
	}
	for (int i = 2; i <= 2*N; i += 3) {
		for (int j = 1; j <= i; j++) {
			if (j > N || i - j + 1 > N)continue;
			Color_2[CIJ[j][i - j + 1]]++;
		}
	}
	for (int i = 3; i <= 2*N; i += 3) {
		for (int j = 1; j <= i; j++) {
			if (j > N || i - j + 1 > N)continue;
			Color_3[CIJ[j][i - j + 1]]++;
		}
	}
	for (int i = 1; i <= C; i++) {
		for (int j = 1; j <= C; j++) {
			sum1[i] += D[j][i] * Color_1[j];
			sum2[i] += D[j][i] * Color_2[j];
			sum3[i] += D[j][i] * Color_3[j];
		}
	}
	for (int i = 1; i <= C; i++) {
		for (int j = 1; j <= C; j++) {
			for (int k = 1; k <= C; k++) {
				if (i == j || j == k || k == i)continue;
				else if (ans > sum1[i] + sum2[j] + sum3[k])ans = sum1[i] + sum2[j] + sum3[k];
			}
		}
	}
	printf("%d\n", ans);


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &N, &C);
  ^
./Main.c:25:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &inp_int);
    ^
./Main.c:31:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &inp_int);
    ^
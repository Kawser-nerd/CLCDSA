#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define inf (int)(1e9)
#define datatype int

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

double coefficient(double k, double a, double b, double *coe){
	coe[0] += k * a * a * a;
	coe[1] += k * 3 * a * a * b;
	coe[2] += k * 3 * a * b * b;
	return k * b * b * b;
}

double substitution(double a, double b, double *coe){
	double ans = coe[0];
	ans += coe[1] * a * a * a;
	ans += coe[2] * a * a;
	ans += coe[3] * a;
	ans += coe[4] * b * b * b;
	ans += coe[5] * b * b;
	ans += coe[6] * b;
	return ans;
}

int main(){
	int N, Q, i, j, k, m;
	scanf("%d%d", &N, &Q);
	int *X = (int *)malloc(sizeof(int) * N);
	int *R = (int *)malloc(sizeof(int) * N);
	int *H = (int *)malloc(sizeof(int) * N);
	int *sep = (int *)malloc(sizeof(int) * (2 * N + 1));
	for(i = 0; i < N; i++){
		scanf("%d%d%d", &X[i], &R[i], &H[i]);
		sep[2 * i] = X[i];
		sep[2 * i + 1] = X[i] + H[i];
	}
	sep[2 * N] = inf;
	sort(sep, 2 * N + 1);
/*	printf("sep:\n");
	for(i = 0; i <= 2 * N; i++){
		printf("%d  ", sep[i]);
	}
	printf("\n\n");
*/	double ***AB = (double ***)malloc(sizeof(double **) * (2 * N + 1));
	for(j = 0; j <= 2 * N; j++){
		AB[j] = (double **)malloc(sizeof(double *) * (2 * N + 1));
		for(k = 0; k <= 2 * N; k++){
			AB[j][k] = (double *)malloc(sizeof(double) * 7);
			for(m = 0; m < 7; m++){
				AB[j][k][m] = 0.0;
			}
		}
	}
	double HRR, Hid;
	for(i = 0; i < N; i++){
		for(j = 0; j <= 2 * N; j++){
			for(k = 0; k <= 2 * N; k++){
				Hid = (double)H[i];
				HRR = Hid * R[i] * R[i];
				if(sep[j] <= X[i]){
					if(X[i] < sep[k] && sep[k] <= X[i] + H[i]){
//						printf("(j, k) = (%d, %d): 1\n", j, k);
						AB[j][k][0] += coefficient(HRR, 1 / Hid, -(1 + X[i] / Hid), &AB[j][k][4]) + HRR;
					}
					else if(X[i] + H[i] < sep[k]){
//						printf("(j, k) = (%d, %d): 2\n", j, k);
						AB[j][k][0] += HRR;
					}
				}
				else if(X[i] < sep[j] && sep[j] <= X[i] + H[i]){
					if(X[i] < sep[k] && sep[k] <= X[i] + H[i]){
//						printf("(j, k) = (%d, %d): 3\n", j, k);
						AB[j][k][0] += coefficient(HRR, -1 / Hid, 1 + X[i] / Hid, &AB[j][k][1]);
						AB[j][k][0] += coefficient(HRR, 1 / Hid, -(1 + X[i] / Hid), &AB[j][k][4]);
					}
					else if(X[i] + H[i] < sep[k]){
//						printf("(j, k) = (%d, %d): 4\n", j, k);
						AB[j][k][0] += coefficient(HRR, -1 / Hid, 1 + X[i] / Hid, &AB[j][k][1]);
					}
				}
			}
		}
	}
/*	printf("AB-test:\n");
	for(j = 0; j <= 2 * N; j++){
		for(k = 0; k <= 2 * N; k++){
			printf("(j, k) = (%d, %d):  ", j, k);
			for(m = 0; m < 7; m++){
				printf("%lf  ", AB[j][k][m]);
			}
			printf("\n");
		}
	}
	printf("\n");
*/	int *A = (int *)malloc(sizeof(int) * Q);
	int *B = (int *)malloc(sizeof(int) * Q);
	for(i = 0; i < Q; i++){
		scanf("%d%d", &A[i], &B[i]);
	}
	int l, h, r;
	for(i = 0; i < Q; i++){
		l = -1;
		r = 2 * N + 1;
		while(r - l > 1){
			h = (l + r) / 2;
			if(A[i] < sep[h]){
				r = h;
			}
			else{
				l = h;
			}
		}
		j = r;
		l = -1;
		r = 2 * N + 1;
		while(r - l > 1){
			h = (l + r) / 2;
			if(B[i] < sep[h]){
				r = h;
			}
			else{
				l = h;
			}
		}
		k = r;
//		printf("(j, k) = (%d, %d)\n", j, k);
		printf("%lf\n", M_PI / 3 * substitution(A[i], B[i], AB[j][k]));
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:61:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &Q);
  ^
./Main.c:67:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &X[i], &R[i], &H[i]);
   ^
./Main.c:132:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &A[i], &B[i]);
   ^
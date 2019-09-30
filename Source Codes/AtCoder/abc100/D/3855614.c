#include <stdio.h>
#include<stdlib.h>

#define SENTINEL 10000000000000

int count = 0;
void merge(long long int A[], int left, int mid, int right);
void mergeSort(long long int A[], int left, int right) {
	int i, mid;
	if (left + 1 < right) {
		mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}



void merge(long long int A[], int left, int mid, int right) {
	long long int n1, n2, i, j, k;
	long long int *L, *R;
	n1 = mid - left;
	n2 = right - mid;
	L = (long long int *)malloc(sizeof(long long int)*(n1 + 1));
	R = (long long int *)malloc(sizeof(long long int)*(n2 + 1));
	for (i = 0; i <= n1 - 1; i++) {
		L[i] = A[left + i];
	}
	for (j = 0; j <= n2 - 1; j++) {
		R[j] = A[mid + j];
	}
	L[n1] = SENTINEL;
	R[n2] = SENTINEL;
	i = 0;
	j = 0;
	for (k = left; k <= right - 1; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
			count++;
		}
		else {
			A[k] = R[j];
			j++;
			count++;
		}
	}
	free(L);
	free(R);
}

long long int big(long long int a, long long int b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}
int main() {
	long long int n, m;
	long long int x[1005] = {}, y[1005] = {}, z[1005] = {}, num[1005] = {}, num2[10] = {};
	scanf("%lld%lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
		 num[i] = x[i] + y[i] + z[i]; 
		
	}
	mergeSort(num, 0, n);
	for (int i = 1; i <= m; i++) {
		num2[1] += num[n - i];
	}
	for (int i = 0; i < n; i++) {
		
		 num[i] = x[i] + y[i] - z[i]; 
		
	}
	mergeSort(num, 0, n);
	for (int i = 1; i <= m; i++) {
		num2[2] += num[n - i];
	}
	for (int i = 0; i < n; i++) {

		 num[i] = x[i] - y[i] - z[i]; 

	}
	mergeSort(num, 0, n);
	for (int i = 1; i <= m; i++) {
		num2[3] += num[n - i];
	}
	for (int i = 0; i < n; i++) {

		num[i] = -x[i] + y[i] - z[i]; 

	}
	mergeSort(num, 0, n);
	for (int i = 1; i <= m; i++) {
		num2[4] += num[n - i];
	}
	for (int i = 0; i < n; i++) {

		 num[i] = -x[i] - y[i] - z[i]; 

	}
	mergeSort(num, 0, n);
	for (int i = 1; i <= m; i++) {
		num2[5] += num[n - i];
	}
	for (int i = 0; i < n; i++) {

		num[i] = x[i] - y[i] + z[i]; 

	}
	mergeSort(num, 0, n);
	for (int i = 1; i <= m; i++) {
		num2[6] += num[n - i];
	}
	for (int i = 0; i < n; i++) {

		num[i] = -x[i] + y[i] + z[i]; 

	}
	mergeSort(num, 0, n);
	for (int i = 1; i <= m; i++) {
		num2[7] += num[n - i];
	}
	for (int i = 0; i < n; i++) {

		 num[i] = -x[i] - y[i] + z[i]; 

	}
	mergeSort(num, 0, n);
	for (int i = 1; i <= m; i++) {
		num2[0] += num[n - i];
	}
	printf("%lld", big(big(big(big(big(big(big(num2[0], num2[1]), num2[2]), num2[3]), num2[4]), num2[5]), num2[6]), num2[7]));
} ./Main.c: In function ‘main’:
./Main.c:64:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &n, &m);
  ^
./Main.c:66:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
   ^
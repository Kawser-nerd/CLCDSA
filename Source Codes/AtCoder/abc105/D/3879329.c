#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>

#define SENTINEL 1100000000000000000

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
	int n1, n2, i, j, k;
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



int main() {
	long long int result = 0, n, memo = 1, m, a[200005] = {}, sum[200005] = {};
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		sum[i] = sum[i - 1] + a[i];
		sum[i] %= m;
	}
	mergeSort(sum, 1, n + 1);
	for (int i = 1; i <= n; i++) {
      	
		if (sum[i] == sum[i - 1]) { memo++; }
		else {
			result += memo * (memo - 1) / 2;
          	memo=1;
		}
	}
  	result += memo * (memo - 1) / 2;
	printf("%lld", result);
} ./Main.c: In function ‘main’:
./Main.c:59:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &n, &m);
  ^
./Main.c:61:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &a[i]);
   ^
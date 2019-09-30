#ifndef ZIKKEN
#include <stdio.h>
#include <inttypes.h>

#define MOD_BY 1000000007

int mul(int a, int b) {
	return (int64_t)a * b % MOD_BY;
}

int pow_i(int a, int n) {
	int r = 1;
	while (n > 0) {
		if (n & 1) r = mul(r, a);
		a = mul(a, a);
		n >>= 1;
	}
	return r;
}

int inv(int a) {
	return pow_i(a, MOD_BY - 2);
}

int div(int a, int b) {
	return mul(a, inv(b));
}

int add(int a, int b) {
	int x = a + b;
	if (x >= MOD_BY) x -= MOD_BY;
	return x;
}

int sub(int a, int b) {
	int x = b == 0 ? 0 : MOD_BY - b;
	return add(a, x);
}

#define MAX 200000

int N;
int A[MAX];

int mofu[MAX * 2];

int main(void) {
	int i;
	int all;
	int result = 0;
	if (scanf("%d", &N) != 1) return 1;
	for (i = 0; i < N; i++) {
		if (scanf("%d", &A[i]) != 1) return 1;
	}
	all = 1;
	for (i = 1; i <= N; i++) all = mul(all, i);
	mofu[N] = all;
	for (i = 0; i < N; i++) {
		mofu[N - i] = mofu[N + i] = div(all, i + 1);
	}
	for (i = 1; i <= N + N; i++) mofu[i] = add(mofu[i - 1], mofu[i]);
	for (i = 0; i < N; i++) {
		int ruiseki = sub(mofu[i + N], mofu[i]);
		result = add(result, mul(A[i], ruiseki));
	}
	printf("%d\n", result);
	return 0;
}

/*
s(x, y) = answer for [x, y)
c(x, y) = cost (ruisekiwa) for {x, y)

s(0, 3) = c(0, 3) +
	s(0, 0) + s(1, 3) +
	s(0, 1) + s(2, 3) +
	s(0, 2) + s(3, 3)

s(0, 0) = 0
s(1, 3) = c(1, 3) +
	s(1, 1) + s(2, 3) +
	s(1, 2) + s(3, 3)
s(0, 1) = c(0, 1)
s(2, 3) = c(2, 3)
s(0, 2) = c(0, 2) +
	s(0, 0) + s(1, 2) +
	s(0, 1) + s(2, 2)
s(3, 3) = 0
s(1, 1) = 0
s(1, 2) = c(1, 2)

s(0, 3) = c(0, 3) +
	c(1, 3) + c(2, 3) + c(1, 2) +
	c(0, 1) + c(2, 3) +
	c(0, 2) + c(1, 2) + c(0, 1)

s(0, 3) =
	c(0, 3) + c(1, 3) + c(2, 3) +
	c(0, 3) + c(1, 3) + c(1, 2) +
	c(0, 3) + c(0, 1) + c(2, 3) +
	c(0, 3) + c(2, 3) + c(0, 1) +
	c(0, 3) + c(0, 2) + c(1, 2) +
	c(0, 3) + c(0, 2) + c(0, 1)

s(0, 3) =
	c(0, 3) * 6 +
	c(0, 2) * 2 + c(1, 3) * 2 +
	c(0, 1) * 3 + c(1, 2) * 2 + c(2, 3) * 3

s(0, 2) =
	c(0, 2) + c(1, 2) +
	c(0, 2) + c(0, 1)

s(0, 2) =
	c(0, 2) * 2 +
	c(0, 1) * 1 + c(1, 2) * 1

*/
#else
#include <stdio.h>
#include <stdlib.h>

/* {1,2,3} -> ... -> {3,2,1} */
int next_permutation(int arr[],int n) {
	int target;
	int i;
	int temp;
	for (i = n - 2; i >= 0; i--) {
		if (arr[i] < arr[i + 1]) break;
	}
	if (i < 0) return 0;
	target = i;

	for (i = 0; target + i + 1 < n - i - 1; i++) {
		temp = arr[target + 1 + i];
		arr[target + 1 + i] = arr[n - 1 - i];
		arr[n - i - 1] = temp;
	}

	for (i = target + 1; i < n; i++) {
		if (arr[i] > arr[target]) break;
	}
	temp = arr[i];
	arr[i] = arr[target];
	arr[target] = temp;
	return 1;
}

int main(void) {
	int N;
	int i, j, k;
	int *order;
	char *exists;
	int *count;
	int *count2;
	if (scanf("%d", &N) != 1) return 1;
	if ((order = malloc(sizeof(int) * N)) == NULL) return 1;
	if ((exists = malloc(sizeof(char) * N)) == NULL) {
		free(order);
		return 1;
	}
	if ((count = malloc(sizeof(int) * N * N)) == NULL) {
		free(order);
		free(exists);
		return 1;
	}
	if ((count2 = malloc(sizeof(int) * N * N)) == NULL) {
		free(order);
		free(exists);
		free(count);
		return 1;
	}
	for (i = 0; i < N * N; i++) count[i] = count2[i] = 0;
	for (i = 0; i < N; i++) order[i] = i;
	do {
		for (i = 0; i < N; i++) exists[i] = 1;
		for (i = 0; i < N; i++) {
			int left, right;
			left = right = order[i];
			while (left >= 0 && exists[left]) left--;
			while (right < N && exists[right]) right++;
			count[(left + 1) * N + (right - 1)]++;
			if (0) printf("%d -> %d %d\n", order[i], left + 1, right - 1);
			exists[order[i]] = 0;
			for (j = left + 1; j < right; j++) {
				count2[order[i] * N + j]++;
			}
		}
	} while (next_permutation(order, N));
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d\t", count[i * N + j]);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < N; i++) {
		int sum = 0;
		for (j = 0; j <= i; j++) {
			for (k = i; k < N; k++) sum += count[j * N + k];
		}
		printf("%d\t", sum);
	}
	printf("\n\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d\t", count2[i * N + j]);
		}
		printf("\n");
	}
	printf("\n");
	free(order);
	free(exists);
	free(count);
	free(count2);
	return 0;
}

#endif

/*
????????????????????????????
???????????
????????????????or?????

???????????????
????????????
0 1 2  3  4   5
1 1 2  6 24 120
1 2 4 10 36 156

#: ?? t: ???? *:??&???? .:?????? d:?????

*d : <del>2</del>
#t : 1

??
*dd : <del>2 + 2 + 1 = 5</del> 2(??) * 3(?????) = 6
#td : <del>2</del> 1(??) * 2(?????) = 2
#.t : 1

*dd : 2(??) * 3(?????) = 6
#td : 1(dt#) + 2(t(#d|d#)) = 3
#.t : 2(t??????) = 2

d*d : 2(??) * 3(?????) = 6

*/
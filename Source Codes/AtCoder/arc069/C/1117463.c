#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int cmp(const void* x, const void* y) {
	int a = *(const int*)x;
	int b = *(const int*)y;
	if (a > b) return 1;
	if (a < b) return -1;
	return 0;
}

int N;
int a[1000000];

int zaatu_num;
int zaatu_table[1000000];

int get_id(int num) {
	int left, right, mid;
	left = 0; right = zaatu_num;
	while (left <= right) {
		mid = (left + right) / 2;
		if (zaatu_table[mid] == num) {
			return mid;
		} else if (zaatu_table[mid] < num) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	printf("%d not found!\n", num);
	exit(1);
}

uint64_t isi_count[1000000];

int main(void) {
	int i;
	int prev_count = 0;
	int prev_index = -1;
	if (scanf("%d", &N) != 1) return 1;
	for (i = 0; i < N; i++) {
		if (scanf("%d", &a[i]) != 1) return 1;
		zaatu_table[i] = a[i];
	}
	/* ???? */
	qsort(zaatu_table, N, sizeof(int), cmp);
	zaatu_num = 0;
	for (i = 1; i < N; i++) {
		if (zaatu_table[i] != zaatu_table[zaatu_num]) {
			zaatu_table[++zaatu_num] = zaatu_table[i];
		}
	}
	/* ????????????? */
	for (i = 0; i < N; i++) {
		isi_count[get_id(a[i])]++;
	}
	/* ????????????????? */
	for (i = N - 1; i > 0; i--) {
		isi_count[i - 1] += isi_count[i];
	}
	/* ???? */
	for (i = 0; i < N; i++) {
		if (prev_count < a[i]) {
			/* ?????????????? */
			int current_index = get_id(a[i]);
			int j;
			uint64_t current_count = 0;
			for (j = prev_index + 1; j <= current_index; j++) {
				current_count += (uint64_t)(zaatu_table[j] - (j > 0 ? zaatu_table[j - 1] : 0)) * isi_count[j];
			}
			printf("%"PRIu64"\n", current_count);
			prev_count = a[i];
			prev_index = current_index;
		} else {
			puts("0");
		}
	}
	return 0;
}

/*
1?????????
???
3
1 3 2

???????????????????
??????????????

1 2 1 3 2 4 2 5 8 1 -> 9
1 2 1 3 2 4 2 5 7 1 -> 9
1 2 1 3 2 4 2 5 6 1 -> 9
1 2 1 3 2 4 2 5 5 1 -> 8
1 2 1 3 2 4 2 5 4 1 -> 8
1 2 1 3 2 4 2 4 4 1 -> 6
1 2 1 3 2 4 2 4 3 1 -> 6
1 2 1 3 2 4 2 3 3 1 -> 6
1 2 1 3 2 3 2 3 3 1 -> 4
1 2 1 3 2 3 2 3 2 1 -> 4
1 2 1 3 2 3 2 2 2 1 -> 4
1 2 1 3 2 2 2 2 2 1 -> 4
1 2 1 2 2 2 2 2 2 1 -> 2
1 2 1 2 2 2 2 2 1 1 -> 2
1 2 1 2 2 2 2 1 1 1 -> 2
1 2 1 2 2 2 1 1 1 1 -> 2
1 2 1 2 2 1 1 1 1 1 -> 2
1 2 1 2 1 1 1 1 1 1 -> 2
1 2 1 1 1 1 1 1 1 1 -> 2
1 1 1 1 1 1 1 1 1 1 -> 1
1 1 1 1 1 1 1 1 1 0 -> 1
1 1 1 1 1 1 1 1 0 0 -> 1
1 1 1 1 1 1 1 0 0 0 -> 1
1 1 1 1 1 1 0 0 0 0 -> 1
1 1 1 1 1 0 0 0 0 0 -> 1
1 1 1 1 0 0 0 0 0 0 -> 1
1 1 1 0 0 0 0 0 0 0 -> 1
1 1 0 0 0 0 0 0 0 0 -> 1
1 0 0 0 0 0 0 0 0 0 -> 1
*/
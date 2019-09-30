#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct S {
	int p;
	char c;
} A[30];

int N;

int compare(const void *p1, const void *p2)
{
	struct S *a1, *a2;

	a1 = (struct S *)p1;
	a2 = (struct S *)p2;

	return a2->p - a1->p;
}

void reduce(int ind)
{
	int i;

	if (ind % 2) {
		putchar(' ');
		putchar(A[0].c);
		A[0].p--;
		i = 1;
	} else {
		i = 0;
	}

	for (; i < ind; i += 2) {
		putchar(' ');
		putchar(A[i].c);
		putchar(A[i+1].c);
		A[i].p--;
		A[i+1].p--;
	}
}

int main(void)
{
	int i, j;
	int T;
	int index;

	scanf("%d ", &T);
	for (i = 1; i <= T; ++i) {
		printf("Case #%d:", i);
		memset(A, 0, sizeof(A));
		scanf("%d ", &N);

		for (j = 0; j < N; ++j) {
			scanf("%d ", &(A[j].p));
			A[j].c = 'A' + j;
		}

		qsort(A, N, sizeof(*A), compare);

		/* decrease first so it matches second */
		while (A[0].p > A[1].p) {
			if (A[0].p >= A[1].p + 2) {
				putchar(' ');
				putchar(A[0].c);
				putchar(A[0].c);
				A[0].p -= 2;
			} else {
				putchar(' ');
				putchar(A[0].c);
				A[0].p--;
			}
		}

		index = 2;
		do {
			/* advance index */
			if (index < N) {
				while (A[index].p == A[index-1].p)
					index++;
			}

			/* repeatedly reduce */
			if (index < N) {
				while (A[index].p < A[index-1].p)
					reduce(index);
			} else {
				while (A[index-1].p)
					reduce(index);
			}
		} while (index < N);
		putchar(10);
	}
	return 0;
}


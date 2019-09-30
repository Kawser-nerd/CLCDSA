#include <stdio.h>
#include <stdlib.h>

void QSort(int x[], int left, int right);
void Swap(int x[], int i, int j);

/* ?????????? */
void QSort(int *x, int left, int right)
{
	int i, j;
	int pivot;

	i = left;                      /* ?????????????????? */
	j = right;                     /* ?????????????????? */

	pivot = x[(left + right) / 2]; /* ?????????????? */

	while (1) {                    /* ????? */

		while (x[i] < pivot)       /* pivot ??????? */
			i++;                   /* ???? i ?????? */

		while (pivot < x[j])       /* pivot ??????? */
			j--;                   /*  ???? j ?????? */
		if (i >= j)                /* i >= j ?? */
			break;                 /* ?????????? */

		Swap(x, i, j);             /* x[i] ? x[j]??? */
		i++;                       /* ????? */
		j--;
	}
	if (left < i - 1)              /* ?????? 2 ???????? */
		QSort(x, left, i - 1);     /* ????? Q ????? */
	if (j + 1 <  right)            /* ?????? 2 ???????? */
		QSort(x, j + 1, right);    /* ????? Q ????? */
}

/* ?????????? */
void Swap(int *x, int i, int j) {
	int temp;

	temp = x[i];
	x[i] = x[j];
	x[j] = temp;
}

int main (void) {
	int N = -1, i, *x, *y, med;
	scanf("%d\n", &N);
	if (N % 2 != 0) return -1;
	i = 0;
	x = malloc(sizeof(int) * N);
	y = malloc(sizeof(int) * N);
	while (i < N) {
		scanf(" %d", &x[i]);
		y[i] = x[i];
		i++;
	}
	QSort(y, 0, N - 1);
	i = 0;
	int c = y[N / 2 - 1];
	while (i < N) {
		if (x[i] <= c)
			med = y[N / 2];
		else med = y[N / 2 - 1];
		printf("%d\n", med);
		i++;
	}
	free(x);
	free(y);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:49:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d\n", &N);
  ^
./Main.c:55:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf(" %d", &x[i]);
   ^
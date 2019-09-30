#include <stdio.h>
#include <stdlib.h>

int makecomb(int n, int k, int *comb);
void sub_mc(int n, int k, int rank, int *count, int p_tmp, int *comb);

int main(void)
{
	int i, j, k, n, m, **rel, comb[924], count, result;
	scanf("%d %d", &n, &m);
	rel = (int **)malloc(sizeof(int *) * (n-1));
	for (i = 0; i < n-1; ++i)
		rel[i] = (int *)calloc(n-i-1, sizeof(int));
	for (i = 0; i < m; ++i) {
		scanf("%d %d", &j, &k);
		++rel[j-1][k-j-1];
	}

	for (result = n; result > 1; --result) {
		count = makecomb(n, result, comb);
		for (i = 0; i < count; ++i) {
			for (j = 0; j < n-1; ++j) {
				if (comb[i] & (1 << j)) {
					for (k = j+1; k < n; ++k) {
						if (comb[i] & (1 << k)) {
							if (!rel[j][k-j-1])
								goto next;
						}
					}
				}
			}

			goto exit;
		next:;
		}
	}
exit:;

	printf("%d\n", result);

	return 0;
}

int makecomb(int n, int k, int *comb)
{
	int tmp, count = 0;

	for (int i = 0; i < n-k+1; ++i) {
		tmp = 1 << i;
		sub_mc(n, k-1, i+1, &count, tmp, comb);
	}

	return count;
}

void sub_mc(int n, int k, int rank, int *count, int p_tmp, int *comb)
{
	int tmp;

	if (k) {
		for (int i = rank; i < n-k+1; ++i) {
			tmp = p_tmp | (1 << i);
			sub_mc(n, k-1, i+1, count, tmp, comb);
		}
	}
	else {
		comb[(*count)++] = p_tmp;
	}
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &m);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &j, &k);
   ^
#include<stdio.h>
#include<stdlib.h>
#define TYPE int
int cmp(const void *a, const void *b) { return *(TYPE *)a - *(TYPE *)b; }
int main() {
	int A[3];
	int ans = 0;
	scanf("%d%d%d", &A[0], &A[1], &A[2]);
	qsort(A, 3, sizeof(int), cmp);
	//printf("%d %d %d", A[0], A[1], A[2]);
	if (A[0] == A[1] && A[1] == A[2]) {
		printf("%d\n", ans);
		return 0;
	}
	while (A[0] != A[1] || A[0] != A[2])
	{
		qsort(A, 3, sizeof(int), cmp);
		if (A[0] + 2 <= A[2])
		{
			A[0] += 2;;
		}
		else
		{
			A[0] += 1;
			A[1] += 1;
		}
		ans++;
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &A[0], &A[1], &A[2]);
  ^
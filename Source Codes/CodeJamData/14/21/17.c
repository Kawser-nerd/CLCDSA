#include <stdio.h>
#include <stdlib.h>

char szs[100][101];
int idxArr[100];
int numArr[100];

int 
cmp(const void *x, const void *y) {
	int *a = (int *) x;
	int *b = (int *) y;
	return *a - *b;
}

int 
calc(int *arr, int size) {
	qsort(arr, size, sizeof(int), cmp);

	int cost = 0;
	int i, j;
	for (i = 0, j = size - 1; i < j; i++, j--) {
		cost += arr[j] - arr[i];
	}
	return cost;
}

int 
main(void) {
	int nTest, seqno;
	int N;

	scanf("%d", &nTest);
	for (seqno = 1; seqno <= nTest; seqno++) {
		scanf("%d", &N);
		
		int i, j;
		for (i = 0; i < N; i++) {
			scanf("%s", szs[i]);
		}

		int totCost = 0;

		for (i = 0; i < N; i++) {
			idxArr[i] = 0;
		}

		while (1) {
			char ch = szs[0][idxArr[0]];
			for (i = 1; i < N; i++) {
				if (szs[i][idxArr[i]] != ch) {
					totCost = -1;
					goto out;
				}
			}

			if (ch == '\0') {
				goto out;
			}

			// stat
			for (i = 0; i < N; i++) {
				numArr[i] = 1;	
				for (j = idxArr[i] + 1; szs[i][j] == szs[i][j - 1]; j++) {
					numArr[i]++;
				}
				idxArr[i] = j;
			}

			// calc
			totCost += calc(numArr, N);
		}
	out:
		printf("Case #%d: ", seqno);
		if (totCost >= 0) {
			printf("%d", totCost);
		} else {
			printf("Fegla Won");
		}
		printf("\n");
	}
	return 0;
}

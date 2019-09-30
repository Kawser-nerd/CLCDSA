#include <stdio.h>
#include <string.h>

int T, N, matrix[41][41], matN[41];

int isSatisfied(int k) {
	int i;
	for (i = 1; i<= k; i++) {
		if (matN[i] > i) return 0;
	}
	return 1;
}
void swap(int i, int j){ 
	int tmp;
	tmp = matN[i];
	matN[i] = matN[j];
	matN[j] = tmp;
}
void doProcess(FILE *fout, int index) {
	int swapN = 0;
	int i, j, k;
	for (k = 1; k <= N; k++) {
		//if (isSatisfied(k)) break;
		if (isSatisfied(k)) continue;
		for (i = k + 1; i <= N; i++) {
			if (matN[i] <= k) {
				for (j = i; j >= k + 1; j--) {
					swap(j, j-1);
					swapN++;
				}
				break;
			}
		}
	}
	fprintf(fout, "Case #%d: %d\n", index, swapN);
}
void main() {
	FILE *fp, *fout;
	char str[402];
	int i, j, k, lastRight;

	printf("file> ");
	//gets(str);
	fprintf(str, "test.txt");
	fp = fopen("A-large.in", "r");
	fout = fopen("out.txt", "w+");

	fscanf(fp, "%d\n", &T);

	for (i = 0; i < T; i ++) {
		fscanf(fp, "%d\n", &N);
		for (j = 0;j < N; j++) {
			fgets(str, 60, fp);
			lastRight = -1;
			for (k = 0; k < N; k++) {
				matrix[j][k] = str[k] - '0';
				if (matrix[j][k] == 1) 
					lastRight = k;
			}
			lastRight ++;
			matN[j+1] = lastRight;
		}
		doProcess(fout, i + 1);
	}

	fclose(fout);
	fclose(fp);
}
#include <stdio.h>
#include <string.h>

#define MAX_NO 100000

char happy_numbers[11][MAX_NO + 1];
int visit[MAX_NO + 1];

void process(FILE *fp, FILE *fout) {
	int T, i, j, k, index;
	int bases[10];
	int unhappy = 0;
	char str[100];
	char *tok;

	fscanf(fp, "%d\n", &T);
	for(i = 1; i <= T; i++) {
		fgets(str, 100, fp);
		tok = strtok(str, " ");
		index = 0;
		while (tok != NULL) {
			bases[index++] = atoi(tok);
			tok = strtok(NULL, " ");
		}
		for (j = 2; j <= MAX_NO; j++) {
			unhappy = 0;
			for(k = 0; k < index; k++) {
				if (happy_numbers[bases[k]][j] == 0) {
					unhappy = 1;
					break;
				}
			}
			if (!unhappy) {
				fprintf(fout, "Case #%d: %d\n", i, j);
				break;
			}
		}
	}
}

int convert_10_base(int number, int base, int *array) {
	int temp = 1;
	int index = 0;
	while (1) {
		if (temp * base > number) break;
		temp *= base;
	}
	while (1) {
		array[index] = number / temp;
		number %= temp;
		index ++;
		temp /= base;
		if (temp == 0) break;
	}
	return index;
}
void find_happy_numbers(int base) {
	int number[20];
	int len, i, j, sum;
	int first, first_flag;
	for (i = 2; i <= MAX_NO; i++) {
		sum = i;
		while (1) {
			len = convert_10_base(sum, base, number);
			sum = 0;
			for (j = 0; j < len; j++) {
				sum += number[j] * number[j];
			}
			if (visit[sum] == i) {
				break;
			}
			visit[sum] = i;
			first_flag = 0;
			if (sum == 1) {
				happy_numbers[base][i] = 1;
				break;
			}
		}
	}
}
void main() {
	FILE *fp;
	FILE *fout;
	char input[100];
	int base;

	printf("> ");
	gets(input);
	
	for (base = 2; base <= 10; base++) {
		find_happy_numbers(base);
	}

	fp   = fopen(input, "r");
	fout = fopen("output.txt", "w+");
	
	process(fp, fout);

	fclose(fp);
	fclose(fout);
}
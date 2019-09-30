#include <stdio.h>
#define MAX 50

int main() {
	int t, T, n, i, j, row[MAX], count, tmp, last;
	char line[MAX];
	scanf("%d", &T);
	for(t = 1; t <= T; t++) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%s", line);
			row[i] = -1;
			for(j = 0; line[j]; j++)
				if(line[j] == '1')
					row[i] = j;
//			printf("[%d]\n", row[i]);
		}
		count = 0;
		for(i = 0; i < n; i++) {

				last = row[i];
				for(j = i+1; j < n && last > i; j++, count++) {
					tmp = row[j];
					row[j] = last;
					last = tmp;
				}
				row[i] = last;
		}
		printf("Case #%d: %d\n", t, count);
	}
	return 0;
}
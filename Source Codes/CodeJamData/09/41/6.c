#include <stdio.h>

char m[50][50];
int index[50];

int main(void)
{
	int t, ti;
	scanf("%d", &t);
	for (ti = 1; ti <= t; ti++) {
		int n, i, j, k = 0, l;
		scanf("%d\n", &n);
		for (i = 0; i < n; i++) {
			gets(m[i]);
			index[i] = i;
		}
		for (i = 0; i < n; i++) {
			for (j = i; j < n; j++) {
				for (l = i+1; l < n; l++) {
					if (m[index[j]][l] == '1') goto rossz;
				}
				break;
rossz:;
			}
			for (; j > i; j--) {
				int x;
				k++;
				x = index[j];
				index[j] = index[j-1];
				index[j-1] = x;
			}
		}
		printf("Case #%d: %d\n", ti, k);
	}
	return 0;
}

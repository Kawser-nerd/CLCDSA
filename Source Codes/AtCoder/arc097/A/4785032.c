#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char str[5005];
	int k;
	int len;
	char dict[25005][6] = {};
	int cnt;
	int ans_indx;

	scanf("%s", str);
	scanf("%d", &k);

	len = strlen(str);

	cnt = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j + i < len; j++) {

			for (int ii = j; ii <= j + i; ii++) {
				dict[cnt][ii - j] = str[ii];
			}
			cnt++;

		}
	}

	qsort(*dict, cnt, 6, (int (*)(const void *, const void *))strcmp);

	ans_indx = -1;
	int ccnt = 0;
	while (ccnt < k) {
		if (strcmp(dict[ans_indx], dict[ans_indx + 1])) { 
			ccnt++;
		}

		ans_indx++;
	}

	printf("%s\n", dict[ans_indx]);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", str);
  ^
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &k);
  ^
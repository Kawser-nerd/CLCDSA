#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[30];

int cmp( const void *a , const void *b )
{
	return *(char *)a - *(char *)b;
}


void work() {
	int len = strlen(buf);
	int i, j, k;
	char tmp;

	for(i = len - 2; i >= 0; -- i) {

		k = -1;
		for(j = len - 1; j > i; -- j) {
			if(buf[j] > buf[i]) {
				if(k == -1 || buf[k] >= buf[j])
					k = j;
			}
		}

		if(k == -1) continue;

		tmp = buf[k];
		buf[k] = buf[i];
		buf[i] = tmp;
		qsort(buf + i + 1, len - i - 1, sizeof(char), cmp);
		break;
	}

	if(i == -1) {
		k = -1;
		for(j = 0; j < len; ++ j)
			if(buf[j] != '0')
				if(k == -1 || buf[j] < buf[k])
					k = j;

		tmp = buf[k];
		buf[k] = buf[0];
		buf[0] = tmp;

		qsort(buf + 1, len - 1, sizeof(char), cmp);
		for(j = len - 1; j >= 1; -- j)
			buf[j + 1] = buf[j];
		buf[1] = '0';
		buf[len + 1] = '\0';
	}

	return;
}

int main() {
	int cases;
	int i;

	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	scanf("%d", &cases);
	for(i = 1; i <= cases; ++ i) {
		scanf("%s", buf);
		work();
		printf("Case #%d: %s\n", i, buf);
	}

	return 0;
}

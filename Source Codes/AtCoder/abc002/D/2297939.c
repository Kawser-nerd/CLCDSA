#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *x, *y, i, j, n, m, s, t, k = 1, tmp, count, a[12], max = 1;
	scanf("%d %d", &n, &m);
	x = (int*)malloc(sizeof(int) * m);
	y = (int*)malloc(sizeof(int) * m);
	for(i = 0; i < m; ++i)
		scanf("%d %d", x+i, y+i);

	for(i = 0; i < n; ++i)
		k *= 2;
	for(i = 1; i < k; ++i) {
		tmp = i, count = 0, j = 1;
		while(tmp) {
			if(tmp & 1)
				a[count++] = j;
			tmp >>= 1, j++;
		}

		for(s = 0; s < count-1; s++) {
			for(t = s+1; t < count; t++) {
				for(j = 0; j < m; j++) {
					if(x[j] == a[s] && y[j] == a[t])
						goto next;
				}
				goto exit;

				next:;
			}
		}

		if(max < count)
			max = count;

		exit:;
	}

	printf("%d\n", max);
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &m);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", x+i, y+i);
   ^
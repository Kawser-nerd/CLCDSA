#include <stdio.h>

char s[555][555];
int h, w;
int ans[555][555];

int main(void){
	int i, j;
	scanf("%d%d", &h, &w);
	for (i = 0; i < h; i++) {
		scanf("%s", s[i]);
	}

	// ??AC.
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (s[i][j] == '#') {
				ans[i][j] = 3;
			} else if (j == 0 || j == w - 1) {
				ans[i][j] = (j ? 2 : 1);
			} else {
				ans[i][j] = (i % 2 + 1);
			}
		}
	}

	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			putchar((ans[i][j] & 1) ? '#' : '.');
		}
		puts("");
	}
	puts("");

	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			putchar((ans[i][j] & 2) ? '#' : '.');
		}
		puts("");
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &h, &w);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s[i]);
   ^
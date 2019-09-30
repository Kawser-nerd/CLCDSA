#include <stdio.h>

int flag[200005];

int main() {

	int N, x;

	scanf("%d %d",&N,&x);

	int i;

	if (x == 1 || x == (2 * N) - 1) {
		printf("No\n");
	}
	else if (N == 2) {
		printf("Yes\n");
		printf("1\n2\n3\n");
	}
	else {
		printf("Yes\n");
		if (x == 2) {
			int cnt = 5;
			for (i = 0; i < (2 * N) - 1; i++) {
				if (i == (((2 * N) - 1) / 2) - 1) {
					printf("3\n");
				}
				else if (i == (((2 * N) - 1) / 2)) {
					printf("2\n");
				}
				else if (i == (((2 * N) - 1) / 2) + 1) {
					printf("1\n");
				}
				else if (i == (((2 * N) - 1) / 2) + 2) {
					printf("4\n");
				}
				else {
					printf("%d\n",cnt);
					cnt++;
				}
			}
		}
		else {
			flag[x - 2] = 1;
			flag[x - 1] = 1;
			flag[x] = 1;
			flag[x + 1] = 1;
			int cnt = 1;
			for (i = 0; i < (2 * N) - 1; i++) {
				if (i == (((2 * N) - 1) / 2) - 1) {
					printf("%d\n",x-1);
				}
				else if (i == (((2 * N) - 1) / 2)) {
					printf("%d\n",x);
				}
				else if (i == (((2 * N) - 1) / 2) + 1) {
					printf("%d\n",x+1);
				}
				else if (i == (((2 * N) - 1) / 2) + 2) {
					printf("%d\n",x-2);
				}
				else {
					while (1) {
						if (flag[cnt] == 0) { break; }
						cnt++;
					}
					printf("%d\n", cnt);
					cnt++;
				}
			}
		}
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&x);
  ^
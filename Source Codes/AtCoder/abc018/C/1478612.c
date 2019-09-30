#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int in_y, in_x, in_k, up_max, down_max;
char **list;

int proc_up(int i, int j, int k)
{
	if (i < k) {
		return 0;
	}
	if (list[i][j] == 'x') {
		return -1;
	}
	proc_up(i - 1, j, k);
}

int proc_down(int i, int j, int k)
{
	if (i > k) {
		return 0;
	}
	if (list[i][j] == 'x') {
		return -1;
	}
	proc_down(i + 1, j, k);
}

int proc_left(int i, int j, int k, int up, int down)
{
	if (j < k) {
		return 0;
	}
	if (list[i][j] == 'x') {
		return -1;
	}
	if (j >= k + 1) {
		if (proc_up(i, j, up)) {
			return -1;
		}
		if (proc_down(i, j, down)) {
			return -1;
		}
	}
	proc_left(i, j - 1, k, up + 1, down - 1);
}

int proc_right(int i, int j, int k, int up, int down)
{
	if (j > k) {
		return 0;
	}
	if (list[i][j] == 'x') {
		return -1;
	}
	if (j <= k - 1) {
		if (proc_up(i, j, up)) {
			return -1;
		}
		if (proc_down(i, j, down)) {
			return -1;
		}
	}
	proc_right(i, j + 1, k, up + 1, down - 1);
}

int main(void)
{
	int i, j, ans = 0;
	
	scanf("%d %d %d", &in_y, &in_x, &in_k);

	list = calloc(sizeof(char *), in_y);

	for (i = 0; i < in_y; i++) {
		list[i] = calloc(1, in_x);
		scanf("%s", list[i]);
	}

	for (i = in_k - 1; i <= in_y - in_k; i++) {
		for (j = in_k - 1; j <= in_x - in_k; j++) {
			up_max = i - (in_k - 1);
			if (proc_up(i, j, up_max)) {
				continue;
			}
			down_max = i + (in_k - 1);
			if (proc_down(i, j, down_max)) {
				continue;
			}
			if (proc_left(i, j, j - (in_k - 1), up_max, down_max)) {
				continue;
			}
			if (proc_right(i, j, j + (in_k - 1), up_max, down_max)) {
				continue;
			}
			ans++;
		}
	}

	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:72:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &in_y, &in_x, &in_k);
  ^
./Main.c:78:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", list[i]);
   ^
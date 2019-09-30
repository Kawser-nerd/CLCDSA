#include <stdio.h>
#include <string.h>

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int min(int a, int b) {
	if (a > b) return b;
	else return a;
}

int main(void) {
	char s[101] = { 0 };
	int len, i, j, sp, x, ans, pre_ans;
	int *eq;

	scanf("%s", &s);
	len = strlen(s);
	eq = (int*)malloc(sizeof(int)*len);
	for (i = 0; i < len; i++) eq[i] = 0;

	ans = len;
	for (i = 0; i < len; i++) {
		if (eq[i] == 0) {
			x = i;
			j = i + 1;
			pre_ans = i;
			while (j < len) {
				if (s[x] == s[j]) {
					sp = j - x - 1;
					x = j;
					eq[j] = 1;
					pre_ans = max(sp, pre_ans);
				}
				else if (j == len - 1) {
					pre_ans = max(pre_ans, len - x - 1);
				}
				j++;
			}
			ans = min(ans, pre_ans);
		}
	}

	printf("%d\n", ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[101]’ [-Wformat=]
  scanf("%s", &s);
        ^
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", &s);
  ^
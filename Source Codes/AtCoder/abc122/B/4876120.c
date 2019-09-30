#include<stdio.h>

int main(void) {
	char S[11];
	int i, count = 0, ans = 0;
	scanf("%s", &S);
	for (i = 0; i < 11; ++i) {
		switch (S[i]) {
		case'A':
		case'G':
		case'C':
		case'T':
			++count;
			break;

		default:
			if (count > ans) {
				ans = count;
				count = 0;
			}
			else {
				ans = ans;
				count = 0;
			}
			break;
		}
	}
	printf("%d", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[11]’ [-Wformat=]
  scanf("%s", &S);
        ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", &S);
  ^
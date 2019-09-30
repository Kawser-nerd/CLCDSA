#include<stdio.h>
int main() {
	char S[100002];
	scanf("%s", S);
	int len = strlen(S);
	int cnt = 0, ans = 0;
	for (int i = 0; i < len; i++)
	{
		if (S[i] == 'p') {
			cnt++;
		}
	}
	ans = len / 2 - cnt;
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:12: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
  int len = strlen(S);
            ^
./Main.c:5:12: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:5:12: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^
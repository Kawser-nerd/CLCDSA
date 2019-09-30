#include<stdio.h>
int main() {
	char S[100002];
	scanf("%s", S);
	int ans = 0;
	for (int i = 1; i < strlen(S); i++)
	{
		if (S[i] != S[i - 1]) {
			ans++;
		}
	}
	ans = ans;
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:22: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
  for (int i = 1; i < strlen(S); i++)
                      ^
./Main.c:6:22: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:6:22: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^
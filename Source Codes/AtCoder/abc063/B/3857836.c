#include <stdio.h>

int main()
{
	char S[27];
	scanf("%s", S);
	int i, j;
	int flag=0;
	for (i = 0; S[i] != '\0'; i++) {
		for (j = i+1; S[j] != '\0'; j++) {
			if (S[i] == S[j]) {
				flag = 1;
				break;
			}
		}
	}
	if (flag == 1) {
		printf("no\n");
	} else {
		printf("yes\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^
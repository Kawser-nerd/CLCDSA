#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char S[100010];
	scanf("%s", S);

	int i, j, k;
	char ans = 'a';
	int flag[26];
	for (i = 0; i < 26; i++) {
		flag[i] = 0;
	}
	k = 0;
	for (i = 'a'; i <= 'z'; i++) {
		for (j = 0; S[j] != '\0'; j++) {
			if (i == S[j]) {
				flag[k] = 1;
			}
		}
		k++;
	}
	for (i = 0; i < 26; i++) {
		if (flag[i] != 1) {
			printf("%c\n", 'a' + i);
			break;
		}
	}
	if (i == 26) {
		printf("None\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^
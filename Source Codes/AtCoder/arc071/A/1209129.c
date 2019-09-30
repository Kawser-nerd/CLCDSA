#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
char S[50][51];

int comp(const void *p1, const void *p2) { return *(const char*)p1 - *(const char *)p2; }
int min(int a, int b) { return a < b ? a : b; }

void make_string(char str1[], char str2[]) {
	int index1 = 0, index2 = 0, index = 0;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	char tmp[51];

	while (1) {
		if (str1[index1] == str2[index2]) {
			tmp[index++] = str1[index1];
			index1++;
			index2++;
		}
		else if (str1[index1] > str2[index2])
			index2++;
		else 
			index1++;

		if (index1 >=  len1 || index2 >= len2)
			break;
	}
	tmp[index] = '\0';
	memcpy(str1, tmp, index + 1);
}

int main(void) {
	int i;
	char ans[50];

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", S[i]);
		qsort(S[i], strlen(S[i]), sizeof(char), comp);
	}

	memcpy(ans, S[0], strlen(S[0]));
	for (i = 1; i < n; i++)
		make_string(ans, S[i]);

	printf("%s\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:39:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:41:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S[i]);
   ^
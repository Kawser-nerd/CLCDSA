#include<stdio.h>
#include<string.h>

#define MYSTRINGMAX 200000 // ??20????
#define SIZE MYSTRINGMAX + 2 // MYSTRINGMAX+2????SIZE??????????? SIZE = 200002

int main(void) {
	char s[SIZE], t[SIZE];
	char c1[SIZE] = {0};
	char c2[SIZE] = {0};

	fgets(s, SIZE, stdin);
	fgets(t, SIZE, stdin);

	int length = strlen(s) - 1; // length??????????strlen?????s??????
	
	for (int i = 0; i < length; i++) {
		int in1 = s[i] - 'a';
		if (c1[in1] == 0) {
			c1[in1] = t[i];
		} else {
			if (c1[in1] != t[i]) {
				printf("No\n");
				return 0;
			}
		}
		int in2 = t[i] - 'a';
		if (c2[in2] == 0) {
			c2[in2] = s[i];
		} else {
			if (c2[in2] != s[i]) {
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n"); // ??????Yes???
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(s, SIZE, stdin);
  ^
./Main.c:13:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(t, SIZE, stdin);
  ^
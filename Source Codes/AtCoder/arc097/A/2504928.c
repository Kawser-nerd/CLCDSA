#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int eq(char *str1, char *str2) {
	int count = 0;
	while (str1[count] != 0 || str2[count] != 0) {
		if (str1[count] != str2[count])return 0;
		count++;
	}
	return 1;
}

int main(void) {
	char s[5001];
	char list[10000][5001];
	int listcount = 0;
	char a = 'a';
	int k = 0, count = 0;
	scanf("%s", &s);
	scanf("%d", &k);
	for (int i = 0; i < 5001; i++) {
		if (s[i] == 0) {
			count = i;
		}
	}
	for (int ch = 0; ch < 26; ch++) {
		char moji = a + ch;
		for (int i = 0; i < count; i++) {//offset
			if (s[i] == moji) {
				for (int j = 0; j + i < count && j < k; j++) {
					char str[5001] = "";
					strncpy(str, s + i, j+1);
					str[j + 1] = 0;
					int flag = 0;
					for (int lc = 0; lc < listcount; lc++) {
						if (eq(list[lc], str)) {
							flag = 1;
							break;
						}
					}
					if (flag) {
						flag = 0;
						continue;
					}
					strncpy(list[listcount], str, j+1);
					list[listcount][j + 1] = 0;
					listcount++;
				}
			}
		}
		if (listcount >= k) {
			char temp[5001];
			char s[5001];
			for (int i = 0; i < listcount; i++) {
				for (int j = i + 1; j < listcount; j++) {
					if (strcmp(list[i], list[j]) > 0) {
						strcpy(s, list[i]);
						strcpy(list[i], list[j]);
						strcpy(list[j], s);
					}
				}
			}
			printf("%s\n", list[k - 1]);
			return 0;
		}
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[5001]’ [-Wformat=]
  scanf("%s", &s);
        ^
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", &s);
  ^
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &k);
  ^
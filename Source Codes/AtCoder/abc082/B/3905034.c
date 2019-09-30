#include<stdio.h>
#include<string.h>
int main() {
	long long int n, s[5000] = {}, m, min = 100, max = 0, count = 0, x,memo,memo2;
	char str[3000], str2[3000];
	scanf("%s%s", str, str2);
next:
	min = 100, max = -1;
	for (int i = 0; i < strlen(str2); i++) {
		if (str2[i] == 'Z') { continue; }
		if (max < str2[i] - 'a') { max = str2[i] - 'a'; memo2 = i; }
	}

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 'Z') { continue; }
		if (min > str[i] - 'a') { min = str[i] - 'a'; memo = i; }
	}
	if (max == -1) {
		printf("No"); return 0;
	}
	if (min == 100) {
		printf("Yes"); return 0;
	}
	if (max == min) { str2[memo2] = 'Z'; str[memo] = 'Z';goto next; }
	
	if (max > min) { printf("Yes"); }
	else { printf("No"); }
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s", str, str2);
  ^
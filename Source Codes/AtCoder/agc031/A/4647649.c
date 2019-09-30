#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

#define MOD 1000000007

typedef struct _words {
	int size;
	char *s;
} words;

int main(void) {
	long int answer = 1;
	int alphabets[26];
	for (int i = 0; i < 26; i++) {
		alphabets[i] = 1;
	}
	words w;
	scanf("%d", &(w.size));
	w.s = (char *)malloc(sizeof(char) * w.size);
	scanf("%s", w.s);
	for (int i = 0; i < w.size; i++) {
		alphabets[(int)(w.s[i]) - 97]++;
	}
	for (int i = 0; i < 26; i++) {
		answer = (answer * alphabets[i]) % MOD;
	}
	answer -= 1;
	if (answer == -1) {
		answer += MOD;
	}
	printf("%ld\n", answer);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &(w.size));
  ^
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", w.s);
  ^
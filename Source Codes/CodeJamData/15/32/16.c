#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

unsigned int
strcount(char* haystack, char *needle)
{
	size_t haylen;
	size_t needlen;
	unsigned int i;
	unsigned int ret;

	haylen  = strlen(haystack);
	needlen = strlen(needle);
	ret = 0;

	for(i = 0; i < haylen - (needlen - 1); i++)
		if(strncmp(haystack + i, needle, needlen) == 0)
			ret++;

	return ret;
}

uint64_t
pow_ui(uint64_t b, uint64_t k)
{
	if(k == 0) return 1;
	if(k & 1 ) return pow_ui(b * b, k / 2) * b;
	else       return pow_ui(b * b, k / 2);
}

double
solve(
	size_t length,
	char* keyboard,
	size_t keyboard_length,
	char* target,
	size_t target_length)
{
	unsigned int i;
	unsigned int j;

	unsigned int m;
	unsigned int c;
	unsigned int t;

	char** dirty;
	unsigned int maxStr;

	double ret;

	/* If we cannot write enough */
	if(length < target_length)
		return 0;

	/* Check if eveyr characters are there */
	for(i = 0; i < target_length; i++)
		if(strchr(keyboard, target[i]) == NULL)
			return 0;

	/* Don't judge me. */
	maxStr = pow_ui(keyboard_length, length);
	dirty  = (char**)malloc(sizeof(char*) * maxStr);

	for(i = 0; i < maxStr; i++) {
		dirty[i] = (char*)malloc(sizeof(char) * (length + 1));
		memset(dirty[i], 0, length + 1);
	}

	/* Generates every possibilities */
	for(i = 0; i < maxStr; i++) {
		c = i;
		for(j = 0; j < length; j++) {
			dirty[i][j] = keyboard[c % keyboard_length];
			c = c / keyboard_length;
		}
	}

	c = 0;
	m = 0;
	for(i = 0; i < maxStr; i++) {
		t = strcount(dirty[i], target);
		if(t > m)
			m = t;
		c += t;
	}

	ret = c;
	ret = ret / maxStr;

	return m - ret;
}

int
main(int argc, char* argv[], char* envp[])
{
	unsigned int T;
	unsigned int K, L, S;
	unsigned char *keyboard;
	unsigned char *target;
	unsigned int i;

	scanf("%u", &T);

	for(i = 0; i < T; i++) {
		scanf("%u %u %u", &K, &L, &S);
		keyboard = (char*)malloc(sizeof(char) * (K + 1));
		target   = (char*)malloc(sizeof(char) * (L + 1));

		scanf("%s", keyboard);
		scanf("%s", target);

		keyboard[K] = 0;
		target[L]   = 0;

		printf("Case #%d: %.6f\n", i + 1, solve(S, keyboard, K, target, L));

		free(keyboard);
		free(target);
	}

	return EXIT_SUCCESS;
}

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int W;
int wordlen[530000];
char words[530000][13];

void load_words(void)
{
	FILE *f = fopen("garbled_email_dictionary.txt", "r");
	char word[64];
	while (fscanf(f, "%s", word) == 1) {
		int len = strlen(word);
		wordlen[W] = len;
		strcpy(words[W], word);
		W += 1;
	}
	fclose(f);
}

int L;
char input[64];

int last_changes;
int last_penalty;
bool matches(const char *a, const char *b, int len, int penalty)
{
	last_changes = 0;
	for (int i = 0; i < len; --penalty, ++i) {
		if (a[i] == b[i])
			continue;
		if (penalty > 0)
			return false;
		penalty = 5;
		last_changes += 1;
	}
	if (penalty < 0)
		penalty = 0;
	last_penalty = penalty;
	return true;
}

int cache[64][6];
int min_from(int pos, int penalty)
{
	if (pos == L)
		return 0;
	assert(pos < L);
	if (cache[pos][penalty] != -1)
		return cache[pos][penalty];
	int res = 123456789;

	for (int w = 0; w < W; ++w) {
		if (pos+wordlen[w] > L)
			continue;
		if (!matches(input+pos, words[w], wordlen[w], penalty))
			continue;
		int lc = last_changes;
		int nres = lc + min_from(pos+wordlen[w], last_penalty);
		if (nres < res)
			res = nres;
	}

	cache[pos][penalty] = res;
	return res;
}

int main(void)
{
	load_words();
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		fprintf(stderr, "T = %d\n", tc);
		memset(cache, -1, sizeof cache);
		scanf("%s", input);
		L = strlen(input);
		printf("Case #%d: %d\n", tc, min_from(0, 0));
	}
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

static int compar(const void* pa, const void* pb)
{
	char a = *(char*)pa;
	char b = *(char*)pb;
	return a - b;
}

int check(int n, int k, char* s, const char* o)
{
	int i;
	int cnt[256] = { 0 };
	int diff = 0;

	for (i = 0; i < n; ++i){
		++cnt[s[i]];
		--cnt[o[i]];
	}
	for (i = 'a'; i <= 'z'; ++i){
		if (cnt[i] > 0) diff += cnt[i];
	}
	if (diff > k){
		return 0;
	}
	else {
		return 1;
	}
}

int calc(int n, int k, char* s, const char* o)
{
	int i;
	//	qsort(s, n, sizeof(*s), compar);
	for (i = 0; i < n; ++i){
		int dk;
		char tmp = s[0];
		s[0] = s[i];
		s[i] = tmp;
		dk = s[0] != o[0] ? -1 : 0;
		if (check(n - 1, k + dk, s + 1, o + 1)){
			return calc(n - 1, k + dk, s + 1, o + 1);
		}
	}
}

int main(void)
{
	int n, k;
	char s[101], o[101];
	scanf("%d%d%s", &n, &k, o);
	strcpy(s, o);

	qsort(s, n, sizeof(*s), compar);
	calc(n, k, s, o);
	printf("%s\n", s);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:54:2: warning: implicit declaration of function ‘strcpy’ [-Wimplicit-function-declaration]
  strcpy(s, o);
  ^
./Main.c:54:2: warning: incompatible implicit declaration of built-in function ‘strcpy’
./Main.c:54:2: note: include ‘<string.h>’ or provide a declaration of ‘strcpy’
./Main.c:53:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%s", &n, &k, o);
  ^
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int len;
	char S[100010], T[10], U[10];
	scanf("%s", &S);

	while (1) {
//		printf("%s\n", S);
		len = strlen(S);
		if (!len) break;
		memset(T, 0, 10);
		memset(U, 0, 10);
		memmove(T, S, 7);
		if (!strcmp(T,"dreamer")) { // dreamerase(d,e,r) or dreamer(d,e)
			memmove(U, S+5, 6);
			if (!strcmp(U,"eraser")) {
				memmove(S, S+11, len-11);
				memset(S+len-11, 0, 11);
			} else if (!strcmp(U,"erasee") || !strcmp(U,"erased")) {
				memmove(S, S+10, len-10);
				memset(S+len-10, 0, 10);
			} else if (!strcmp(U,"ereras") || !strcmp(U,"erdrea")) {
				memmove(S, S+7, len-7);
				memset(S+len-7, 0, 7);
			} else if (!strcmp(U,"er\0")) {
				memmove(S, S+7, len-7);
				memset(S+len-7, 0, 7);
			} else {
				printf("NO\n"); return 0;
			}
		} else if (!strcmp(T,"dreamdr")) { // dreamdream(er)
			memmove(S, S+5, len-5);
			memset(S+len-5, 0, 5);
		} else {
			memset(T, 0, 10);
			memmove(T, S, 6);
			if (!strcmp(T,"eraser")) {
				memmove(S, S+6, len-6);
				memset(S+len-6, 0, 6);				
			} else {
				memset(T, 0, 10);
				memmove(T, S, 5);
				if (!strcmp(T,"dream")) {
					memmove(S, S+5, len-5);
					memset(S+len-5, 0, 5);
				} else if (!strcmp(T,"erase")) {
					memmove(S, S+5, len-5);
					memset(S+len-5, 0, 5);
				} else {
					printf("NO\n");
					return 0;
				}
			}
		}
	}
	
	printf("YES\n");

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100010]’ [-Wformat=]
  scanf("%s", &S);
        ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", &S);
  ^
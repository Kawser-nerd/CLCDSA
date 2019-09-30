/*
AtCoder Regular Contest 031 A - ??
??:
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

//#define DEBUG1
//#define DEBUG2
//#define DEBUGF

int main() {
	static char A[101];
	static int len, n = 0, i, j, ans;

	scanf("%s", A);
	len = strlen(A);
	for (i = 0; i < (len / 2); i++) {
		int l2 = len - 1 - i;
		if (A[i] != A[l2]) {
			n++;
		}
	}
	if (n != 0) {
		printf("%s\n", "NO");
	}
	else {
		printf("%s\n", "YES");
	}

#ifdef DEBUGF
	getch();
#endif
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", A);
  ^
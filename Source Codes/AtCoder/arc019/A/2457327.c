/*
AtCoder Regular Contest 019 A - ????????? ??:
*/

#include<stdio.h>
#include<string.h>
#include<math.h>

//#define DEBUG1
//#define DEBUG2
//#define DEBUGF
//#ifdef DEBUG1
//#ifdef DEBUG2
//#ifdef DEBUGF
//#endif

int main() {
	char S[9];
	scanf("%s", S);
#ifdef DEBUG1
	printf("%s\n", S);
#endif
	for (int i = 0; S[i] != '\0'; i++) {
		if (S[i] == 'O' || S[i] == 'D') {
			S[i] = '0';
		}
		else if (S[i] == 'I') {
			S[i] = '1';
		}
		else if (S[i] == 'Z') {
			S[i] = '2';
		}
		else if (S[i] == 'S') {
			S[i] = '5';
		}
		else if (S[i] == 'B') {
			S[i] = '8';
		}
	}
		printf("%s", S);
		printf("\n");
#ifdef DEBUG2
#endif

#ifdef DEBUGF
	getch();
#endif
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^
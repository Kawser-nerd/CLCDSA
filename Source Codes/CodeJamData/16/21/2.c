#include <stdio.h>
#include <assert.h>
#include <string.h>
#define CNT(x) cnt[(x)-'A']
#define DEC(a, b) CNT(a) -= CNT(b)
char buf[2010];
int cnt[26], v[10];
int main() {
	int c;
	scanf("%d", &c);
	for(int p = 1; p <= c; p++) {
		scanf("%s", buf);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; buf[i] != 0; i++)
			CNT(buf[i])++;
		//TWO
		v[2] = CNT('W');
		CNT('T') -= CNT('W');
		CNT('O') -= CNT('W');
		CNT('W') = 0;

		//SIX
		v[6] = CNT('X');
		CNT('S') -= CNT('X');
		CNT('I') -= CNT('X');
		CNT('X') = 0;

		//ZERO
		v[0] = CNT('Z');
		CNT('E') -= CNT('Z');
		CNT('R') -= CNT('Z');
		CNT('O') -= CNT('Z');
		CNT('Z') = 0;

		//FOUR
		v[4] = CNT('U');
		CNT('F') -= CNT('U');
		DEC('O', 'U');
		DEC('R', 'U');
		CNT('U') = 0;

		//FIVE
		v[5] = CNT('F');
		DEC('I', 'F');
		DEC('V','F');
		DEC('E','F');
		CNT('F')=0;

		//SEVEN
		v[7] = CNT('V');
		DEC('S','V');
		DEC('N', 'V');
		CNT('E') -= 2*CNT('V');
		CNT('V') = 0;

		//ONE
		v[1] = CNT('O');
		DEC('N','O');
		DEC('E','O');
		CNT('O')=0;

		//THREE
		v[3] = CNT('R');
		DEC('T','R');
		DEC('H','R');
		CNT('E')-=2*CNT('R');
		CNT('R')=0;

		v[8]=CNT('G');
		DEC('E','G');
		DEC('I','G');
		DEC('H','G');
		DEC('T','G');
		CNT('G')=0;

		v[9] = CNT('I');
		CNT('N')-=2*v[9];
		CNT('E')-=v[9];
		CNT('I')=0;

		for(int i = 0; i < 26; i++)
			assert(cnt[i] == 0);
		printf("Case #%d: ", p);
		for(int i = 0; i < 10; i++)
			for(int j = 0; j < v[i]; j++)
				printf("%d", i);
		printf("\n");
	}
}

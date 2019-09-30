#include<stdio.h>
int main(void){

	//3?????????->?
	//S->0 W->1
	//S->0x53
	//W->0x57
	//o->0x6f
	//x->0x78
	//012345
	//oxooxo
	//SSWWSS
	long long int N, i, h, x = 0, ok = 0;
	char c;
	static char say[100015];
	static long long int dou[100015];
	long long int  sta[2];
	volatile int stop;
	scanf("%lld", &N);
	fflush(stdin);
	for (i = 0; i < N; i++) {
		scanf(" %c", &say[i]);
	}say[N] = say[0]; say[N + 1] = say[1]; say[N + 2] = say[2];
	for (h = 0; h < 4; h++) {
		if (h == 0) { sta[0] = 0; sta[1] = 0; }
		if (h == 1) { sta[0] = 0; sta[1] = 1; }
		if (h == 2) { sta[0] = 1; sta[1] = 0; }
		if (h == 3) { sta[0] = 1; sta[1] = 1; }
		dou[0] = sta[0];
		dou[1] = sta[1];
		for (i = 2; i < N + 2; i++) {
			if (say[i - 1] == 0x6f) { x = 0; }
			else { x = 1; }
			if ((x + dou[i - 1] + dou[i - 2]) % 2 == 1) { dou[i] = 1; }
			else { dou[i] = 0; }
		}
		if (dou[N] == sta[0] && dou[N + 1] == sta[1]) {
			dou[1] = dou[N + 1];
			for (i = 0; i <N; i++) {
				if (dou[i] == 0) { c = 0x53; }
				else { c = 0x57; }
				printf("%c", c);
				ok = 1;
			}
			break;
		}
	}
	if (ok == 0) { printf("-1"); }


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf(" %c", &say[i]);
   ^
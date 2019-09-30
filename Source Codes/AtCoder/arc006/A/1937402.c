/*
AtCoder Regular Contest 006 A - ???
Ver1
??:
*/

#include <stdio.h>

//#define DEBUG1

int main(void)
{
	int e[6];
	int b;
	int l[6];
	int cnt[10] = {0,0,0,0,0,0,0,0,0,0};
	int r = 0;
	int f = 0;

	for (int i = 0; i < 6; i++) {
		scanf("%d", &e[i]);
	}
	scanf("%d", &b);
	for (int i = 0; i < 6; i++) {
		scanf("%d", &l[i]);
	}

#ifdef DEBUG1
	for (int i = 0; i < 6; i++) {
		printf("e[%d] = %d\n", i, e[i]);
	}
	printf("b = %d\n", b);
	for (int i = 0; i < 6; i++) {
		printf("l[%d] = %d\n", i, l[i]);
	}
#endif
	for (int i = 0; i < 6; i++) {
		cnt[e[i]] = cnt[e[i]] + 1;
		cnt[l[i]] = cnt[l[i]] + 1;
	}
	for (int i = 0; i < 10; i++) {
		if (cnt[i] == 2) { r++; }
	}

	for (int i = 0; i < 6; i++) {
		if (b == l[i]) { f++; }
	}

#ifdef DEBUG1
	for (int i = 0; i < 10; i++) {
		printf("cnt[%d] = %d\n", i, cnt[i]);
	}
#endif

	if (r == 6) { puts("1"); }
	if (r == 5 && f == 1) { puts("2"); }
	if (r == 5 && f != 1) { puts("3"); }
	if (r == 4) { puts("4"); }
	if (r == 3) { puts("5"); }
	if (r <= 2) { puts("0"); }
#ifdef DEBUG1
	getch();
#endif

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &e[i]);
   ^
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &b);
  ^
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &l[i]);
   ^
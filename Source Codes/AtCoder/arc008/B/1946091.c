/*
AtCoder Regular Contest 008 B - ??????????
Ver1
??:
*/

#include<stdio.h>

//#define DEBUG1

int main() {
	int n, m, i;
	int ans = 1;
	char name[51];
	char kit[51];
	scanf("%d %d %s %s", &n, &m, name, kit);

	for (i = 'A'; i <= 'Z'; i++) {
		int name_tmp = 0, kit_tmp = 0, j;
		for (j = 0; j < n; j++) {
			if (name[j] == i) { name_tmp++; }
		}
		for (j = 0; j < m; j++) {
			if (kit[j] == i) { kit_tmp++; }
		}
		if (name_tmp >= 1 && kit_tmp == 0) {
			ans = -1;
			break;
		}
		while (name_tmp > kit_tmp * ans) {
			ans++;
		}
	}
#ifdef DEBUG1
printf("%d", ans);
getch();
#endif
printf("%d", ans);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %s %s", &n, &m, name, kit);
  ^
#include <stdio.h>
#include <string.h>

//B
int main(void) {
	int n;
	char s[101];
	int ans = -1;
	int ngflg = 0;
	int len, i;

	scanf("%d", &n);
	scanf("%s", s);

	len = strlen(s);
	if (len % 2 == 0) { ngflg = 1; }//????NG
	if (len == 1 && s[0] == 'b') { ans = 0; }//b??
	if (ngflg != 1 && ans != 0) {
		i = 0;
		if (len % 6 == 3) {//a**???
			while (i < len) {
				if (s[i] != 'a' && (i + 1) % 3 == 1) { ngflg = 1; }
				i++;
				if (i == len) { break; }
				if (s[i] != 'b' && (i + 1) % 3 == 2) { ngflg = 1; }
				i++;
				if (i == len) { break; }
				if (s[i] != 'c' && (i + 1) % 3 == 0) { ngflg = 1; }
				i++;
				if (i == len) { break; }
			}
		}
		if (len % 6 == 1) {//b**???
			while (i < len) {
				if (s[i] != 'b' && (i + 1) % 3 == 1) { ngflg = 1; }
				i++;
				if (i == len) { break; }
				if (s[i] != 'c' && (i + 1) % 3 == 2) { ngflg = 1; }
				i++;
				if (i == len) { break; }
				if (s[i] != 'a' && (i + 1) % 3 == 0) { ngflg = 1; }
				i++;
				if (i == len) { break; }
			}
		}
		if (len % 6 == 5) {//a**???
			while (i < len) {
				if (s[i] != 'c' && (i + 1) % 3 == 1) { ngflg = 1; }
				i++;
				if (i == len) { break; }
				if (s[i] != 'a' && (i + 1) % 3 == 2) { ngflg = 1; }
				i++;
				if (i == len) { break; }
				if (s[i] != 'b' && (i + 1) % 3 == 0) { ngflg = 1; }
				i++;
				if (i == len) { break; }
			}
		}
	}
	if (ngflg == 1) { ans = -1; }
	else { ans = (len - 1) / 2; }

	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^
#include <stdio.h>
#include <string.h>

int main(void) {
	int n, sb3, db3;
	int  i = 0, f = 1;
	char acsr[100] = {};
	scanf("%d %s", &n, acsr);
	sb3 = n % 3;
	db3 = n / 3;
	
	if (strlen(acsr) % 2 == 0) f = 0;
	switch (sb3) {
	case 0:
		while (db3) {
			if(acsr[i] != 'a') f = 0;
			if(acsr[i + 1] != 'b') f = 0;
			if(acsr[i + 2] != 'c') f = 0;
			i += 3;
			db3--;
		}
		break;
	case 1:
		while (db3) {
			if(acsr[i] != 'b') f = 0;
			if(acsr[i + 1] != 'c') f = 0;
			if(acsr[i + 2] == '\0') break;
			if(acsr[i + 2] != 'a') f = 0;
			i += 3;
			db3--;
		}
		break;
	case 2:
		while (db3) {
			if(acsr[i] != 'c') f = 0;
			if(acsr[i + 1] == '\0') break;
			if(acsr[i + 1] != 'a') f = 0;
			if(acsr[i + 2] != 'b') f = 0;
			i += 3;
			db3--;
		}
		break;
	}

	f ? printf("%d\n", n / 2) : printf("%d\n", -1);

} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %s", &n, acsr);
  ^
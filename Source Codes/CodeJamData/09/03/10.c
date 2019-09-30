#include <stdio.h>

char key[] = "welcome to code jam";
int table[20][505];

int main() {
	int n, i, j, k, caso = 1, ans;
	char s[505];
	
	scanf("%d\n",&n);
	while (n--) {
		gets(s);
		
		for (i=0; s[i]; i++)
			table[0][i] = (s[i] == key[0]);
		for (k=1; k <= 18; k++) {
			for (i=0; s[i]; i++) {
				table[k][i] = 0;
				if (s[i] != key[k])
					continue;
				for (j=0; j < i; j++)
					table[k][i] = (table[k][i] + table[k-1][j]) % 10000;
			}
		}
		
		for (i=ans=0; s[i]; i++) {
			ans = (ans + table[18][i]) % 10000;
		}
		
		printf("Case #%d: %04d\n",caso++,ans);
	}
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int len;
char S[32];
char *C, *J;

int best;
char BS[32];

int bt(char *C, char *J, int i) {
	if (i == len) {
		int d = abs(atoi(C) - atoi(J));
		if (d < best) {
			best = d;
			sprintf(BS, "%s %s", C, J);
		}
		return best;
	}
	
	if (C[i] == '?') {
		for (char k = '0'; k <= '9'; ++k) {
			C[i] = k;
			if (J[i] == '?')
				bt(C, J, i);
			else
				bt(C, J, i+1);
		}
		C[i] = '?';
	} else if (J[i] == '?') {
		for (char k = '0'; k <= '9'; ++k) {
			J[i] = k;
			if (C[i] == '?')
				bt(C, J, i);
			else
				bt(C, J, i+1);
		}
		J[i] = '?';
	} else {
		bt(C, J, i+1);
	}
	return 0;
}

int main() {
	int T, x = 1;
	scanf("%d\n", &T);
	while (T--) {
		scanf("%[^\n]%n\n", S, &len);
		len /= 2;
		S[len] = '\0';
		C = S;
		J = S+len+1;

		best = 10000;
		bt(C, J, 0);
		
		printf("Case #%d: %s\n", x++, BS);
	}
	return 0;
}

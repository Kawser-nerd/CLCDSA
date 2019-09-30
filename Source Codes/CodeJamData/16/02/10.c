#include <stdio.h>

int N;
char P[101];

void flip(int k) {
	char T[101];
	for (int i = 0; i < k; ++i) {
		T[k-i-1] = P[i] == '-' ? '+' : '-';
	}

	for (int i = 0; i < k; ++i) {
		P[i] = T[i];
	}
}

int solve() {
	int last = N;
	int f = 0;
	while (last > 0) {
		while (last > 0 && P[last-1] == '+') last--;
		if (last) { 
			int j = 0;
			while (j < last && P[j] == '+') j++;
			if (j > 0)
				flip(j);
			else
				flip(last);
			f++;
		}
	}
	return f;
}

int main() {
	int T, x = 1;
	scanf("%d\n", &T);
	while (T--) {
		scanf("%[^\n]%n\n", P, &N);
		printf("Case #%d: %d\n", x++, solve());
	}
}

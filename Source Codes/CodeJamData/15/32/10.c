#include <stdio.h>

int gbanana(int g, int l, int s) {
	if(s < l)
		return 0;
	if(s == l)
		return 1;
	return 1 + gbanana(g, l, s-g);
}

int main() {
	int t, T;
	int K, L, S;
	int i, j, flag, g;
	double a;
	int keys[26];
	char keyboard[200];
	char target[200];
	double targetp[200];
	double dynamic[100];
	int fold[100];
	int l = 0;

	scanf("%d", &T);
	for(t = 1; t <= T; t++) {
		scanf("%d %d %d", &K, &L, &S);
		a = 0;
		for(i = 0; i < 26; i++)
			keys[i] = 0;
		for(i = 0; i < 100; i++) {
			dynamic[i] = 0;
			fold[i] = 0;
		}

		scanf("%s", keyboard);
		for(i = 0; keyboard[i] != '\0'; i++)
			keys[keyboard[i] - 'A']++;

		scanf("%s", target);
		flag = 0;
		for(i = 0; i < L; i++) {
			if(keys[target[i] - 'A'] == 0) {
				flag = 1;
				break;
			}
		}
		if(flag) {
			printf("Case #%d: %.6lf\n", t, 0.0);
			continue;
		}
		for(i = 1; i < L; i++) {
			flag = 1;
			for(j = i; j < L; j++) {
				if(target[j-i] != target[j]) {
					flag = 0;
					break;
				}
			}
			if(flag == 1)
				fold[i] = 1;
		}
		for(i = 1; i < L; i++)
			if(fold[i] == 1) break;
		g = gbanana(i, L, S);

		targetp[L] = 1.0;
		for(i = L-1; i >= 0; i--) {
			targetp[i] = targetp[i+1] * keys[target[i] - 'A'] / K;
		}

		a = g - targetp[0] * (S - L + 1);

		printf("Case #%d: %.6lf\n", t, a);
	}
	return 0;
}

// vj 259706 B
#include <cstdio>

int main() {
	int N, ans = 0;
	scanf("%d", &N);
	for (int i = 3; i <= N; i += 2) {
		int cnt = 0;
		for (int j = 1; j * j <= i; j++)
			if (i % j == 0) {
				++cnt;
				if (i * i != j) ++cnt;
			}
		if (cnt == 8) ++ans;;
	}
	printf("%d\n", ans);
	return 0;
}
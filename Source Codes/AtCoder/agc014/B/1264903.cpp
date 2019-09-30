#include <stdio.h>
#include <algorithm>

int main() {
	int N, M, a, b, T[100000] = { 0 };
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		T[a - 1]++, T[b - 1]++;
	}
	bool can = true;
	for (int i = 0; i < N; i++)
		can &= T[i] % 2 == 0;
	printf("%s\n", (can ? "YES" : "NO"));
}
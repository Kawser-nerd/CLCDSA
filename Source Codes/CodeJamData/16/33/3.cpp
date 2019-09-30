#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		static int id;
		printf("Case #%d: ", ++id);
		int j, p, s, k;
		scanf("%d%d%d%d", &j, &p, &s, &k);
		if (k < s) {
			int ans = j * p * k;
			printf("%d\n", ans);
			for (int a = 1; a <= j; ++a) {
				for (int b = 1; b <= p; ++b) {
					for (int c = 0; c < k; ++c) {
						printf("%d %d %d\n", a, b, (a + b + c) % s + 1);
					}
				}
			}
		} else {
			int ans = j * p * s;
			printf("%d\n", ans);
			for (int a = 1; a <= j; ++a) {
				for (int b = 1; b <= p; ++b) {
					for (int c = 1; c <= s; ++c) {
						printf("%d %d %d\n", a, b, c);
					}
				}
			}
		}
	}
	return 0;
}

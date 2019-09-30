#include <cstdio>
#include <algorithm>
using namespace std;

int T, Case;
long long a, b, t;

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%lld/%lld", &a, &b);
		t = __gcd(a, b);
		a /= t;
		b /= t;
		t = 1;
		while (t < b)	t *= 2;
		if (t != b) {
			printf("Case #%d: impossible\n", ++Case);
			continue;
		}
		for (int i = 1; i <= 40; i++)
			if (a * (1LL << i) >= b) {
				printf("Case #%d: %d\n", ++Case, i);
				break;
			}
	}
}
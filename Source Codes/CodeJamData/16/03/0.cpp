#include <cstdio>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int cnt, N, J;

void out(long long x) {
	while (x) {
		printf("%lld", x % 2);
		x /= 2;
	}
}

bool ok(long long x) {
	for (int i = 2; i <= 10; i++) {
		bool ok = false;
		for (int j = 2; j <= 100; j++) {
			long long x1 = x;
			int v = 0;
			while (x1 > 0) {
				v = (v * i + x1 % 2) % j;
				x1 /= 2;
			}
			if (!v) {
				ok = true;
				break;
			}
		}
		if (!ok)
			return false;
	}
	out(x);
	for (int i = 2; i <= 10; i++) {
		bool ok = false;
		for (int j = 2; j <= 1000; j++) {
			long long x1 = x;
			int v = 0;
			while (x1 > 0) {
				v = (v * i + x1 % 2) % j;
				x1 /= 2;
			}
			if (!v) {
				printf(" %d", j);
				ok = true;
				break;
			}
		}
	}
	printf("\n");
	return true;
}

int main() {
	printf("Case #1:\n");
	scanf("%*d%d%d", &N, &J);
	for (long long i = (1LL << (N - 1)) + 1; cnt < J ;i += 2) {
		if (ok(i))
			cnt += 1;
	}
}

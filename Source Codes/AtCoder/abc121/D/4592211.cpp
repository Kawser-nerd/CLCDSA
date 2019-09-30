#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<functional>
#include <random>
using namespace std;
long long A, B, ans;

long long p(long long a, long long b) {
	long long ret = (((b + 1) - a) / 2) % 2;
	return ret;
}

int main(void) {

	scanf("%lld %lld", &A, &B);
	if (A % 2 == 0 && B % 2 == 1) {
		ans = p(A, B);
	}
	if (A % 2 == 1 && B % 2 == 1) {
		ans = p(A + 1, B) ^ A;
	}
	if (A % 2 == 0 && B % 2 == 0) {
		ans = p(A, B - 1) ^ B;
	}
	if (A % 2 == 1 && B % 2 == 0) {
		ans = p(A + 1, B - 1) ^ A ^ B;
	}
	printf("%lld\n", ans);
}
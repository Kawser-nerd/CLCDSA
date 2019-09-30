#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

int p;

int pot(int a, int b) {
	int res = 1;
	for (; b > 0; b >>= 1) {
		if (b & 1) res = (LL(res) * a) % p;
		a = (LL(a) * a) % p;
	}
	return res;
}

int odw(int x) {
	return pot(x, p - 2);
}

int t[11];
int d, k;

int a, b;

bool good() {
	for (int i = 0; i < k - 1; ++i) {
		if ((a * LL(t[i]) + b) % p != t[i + 1])
			return false;
	}
	return true;
}

int calc() {
	if (t[0] == t[1]) {
		a = 1;
		b = 0;
		if (good())
			return t[0];
		else
			return -2;
	}
	if (k >= 3) {
		a = (LL(t[2] - t[1] + p) * odw(t[1] - t[0] + p)) % p;
		b = (t[1] - ((LL(a) * t[0]) % p) + p ) % p;
		if (good())
			return (LL(a) * t[k - 1] + b) % p;
		else
			return -1;
	} else {
		return -2;
	}
}

bool np[1000005];

void era() {
	for (int i = 2; i <= 1000000; ++i) {
		if (!np[i]) {
			for (int j = i + i; j <= 1000000; j += i)
				np[j] = 1;
		}
	}
}

void alg() {
	scanf("%d %d", &d, &k);
	for (int i = 0; i < k; ++i)
		scanf("%d", &t[i]);
	int p10 = 1;
	while (d--)
		p10 *= 10;
	int res = -1;
	int mx = 2;
	for (int i = 0; i < k; ++i)
		mx = max(mx, t[i] + 1);
	for (int i = mx; i <= p10; ++i) {
		if (!np[i]) {
			p = i;
			int c = calc();
			if (c != -1) {
				if (res != -1) {
					if (res != c) res = -2;
				} else
					res = c;
			}
		}
	}
	if (res >= 0)
		printf("%d\n", res);
	else
		printf("I don't know.\n");
}

int main() {
	era();
	int d;
	scanf("%d", &d);
	for (int caseNo = 1; caseNo <= d; ++caseNo) {
		printf("Case #%d: ", caseNo);
		alg();
	}
}

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

int Hd,  Ad,  Hk,  Ak,  B,  D;


long long calc1(int b, int Hd, int Hd1, int Ad, int Hk, int Ak, int B) {
	int sum = 0;
	bool conti = false;

	conti = false;
	for (int i = 1; i <= b; i++) {
		if (Hd <= Ak) {
			sum += 1;
			Hd = Hd1;
			i -= 1;
			if (conti)
				return 1e18;
			conti = true;
		}else {
			conti = false;
			sum += 1;
			Ad += B;
		}
		Hd -= Ak;
	}
	// printf("%d %d\n", , Hk);
	conti = false;
	while (true) {
		if (Ad >= Hk)
			return sum + 1;
		sum += 1;
		if (Hd <= Ak) {
			Hd = Hd1;
			if (conti)
				return 1e18;
			conti = true;
		}else {
			conti = false;
			Hk -= Ad;
		}
		Hd -= Ak;
	}
	return sum;
}

bool ok(int Ad, int Hk, int B, long long l, long long x) {
	if (x < 0 || x > l)
		return false;
	long long A = Ad + 1LL * x * B;
	long long X = l - x;
	return X && A >= (Hk + X - 1) / X;

}

bool can1(int Ad, int Hk, int B, long long l) {
	if (!B)
		return ok(Ad, Hk, B, l, 0);
	return ok(Ad, Hk, B, l, 0) || ok(Ad, Hk, B, l, l) || ok(Ad, Hk, B, l, (l - Ad / B) / 2) || ok(Ad, Hk, B, l, (l - Ad / B) / 2 + 1) || ok(Ad, Hk, B, l, (l - Ad / B) / 2 - 1);
}

bool can(int Hd, int Hd1, int Ad, int Hk, int Ak, int B, long long l) {
	if (!Ak) {
		return can1(Ad, Hk, B, l);
	}
	int tot = (Hd + Ak - 1) / Ak;
	if (tot >= l) {
		return can1(Ad, Hk, B, l);
	}else {
		long long sum = tot - 1;
		l -= tot;
		Hd1 -= Ak;
		int x = (Hd1 + Ak - 1) / Ak;
		if (!x)
			return can1(Ad, Hk, B, 1);
		if (l % x == 0)
			return can1(Ad, Hk, B, sum + l - l / x + 1);
		else
			return can1(Ad, Hk, B, sum + l - l / x);
	}
}

long long calc(int Hd, int Hd1, int Ad, int Hk, int Ak, int B) {
	// static int cnt = 0;
	// cnt += 1;
	// printf("%d\n", cnt);
	long long l = -1, r = 4e9;
	while (l < r - 1) {
		long long mid = (l + r) / 2;
		if (can(Hd, Hd1, Ad, Hk, Ak, B, mid))
			r = mid;
		else
			l = mid;
	}
	if (r == 4e9)
		return 1e18;
	else
		return r;
}

void doit() {
	scanf("%d%d%d%d%d%d", &Hd, &Ad, &Hk, &Ak, &B, &D);
	// printf("?? %d %d %d %d %d %d\n", Hd, Ad, Hk, Ak, B, D);
	long long ans = 1e18;
	ans = min(ans, calc(Hd, Hd, Ad, Hk, Ak, B));
	if (D) {
		long long sum = 0;
		bool conti = false;
		int Hd1 = Hd;
		int pre = (Hd + Ak - 1) / Ak;
		while (Ak > 0) {
			if (Hd <= Ak - D) {
				sum += 1;
				Hd = Hd1;
				if (conti)
					break;
				conti = true;
				Hd -= Ak;
			}else {
				conti = false;
				sum += 1;
				Ak = max(0, Ak - D);
				Hd -= Ak;
				if (1LL * Ak * pre < Hd1) {
					ans = min(ans, sum + calc(Hd, Hd1, Ad, Hk, Ak, B));
					if (Ak)
						pre = (Hd1 + Ak - 1) / Ak;
				}
			}
		}
	}
	if (ans > 1e16)
		printf("IMPOSSIBLE\n");
	else
		printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        doit();
    }
}
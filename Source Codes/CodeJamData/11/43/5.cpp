#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if (!a) return b;
	return gcd(b % a, a);
}

vector<char> isPrime(1000001, true);
vector<long long> primes;

void solve() {
	long long n;
	cin >> n;
	long long res = 0;
	for (int i = 0; i < (int)primes.size(); i++) {
		long long curP = primes[i] * primes[i];
		while (curP <= n) {
			res++;
			curP *= primes[i];
		}
	}
	if (n > 1) res++;
	cout << res << std::endl;
}

int main() {
	isPrime[1] = false;
	for (int i = 2; i <= 1000000; i++) {
		if (!isPrime[i]) continue;
		primes.push_back(i);
		for (int j = 2 * i; j <= 1000000; j += i) {
			isPrime[j] = false;
		}
	}
	int nt;
	scanf("%d", &nt);
	for (int it = 1; it <= nt; it++) {
		printf("Case #%d: ", it);
		solve();
	}
	return 0;
}

#include <iostream>
using namespace std;
int main() {
	int N, P;
	cin >> N >> P;
	int even = 0, odd = 0;
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		if (x % 2 == 0) ++even;
		else ++odd;
	}
	if (odd == 0) cout << (P == 0 ? (1LL << N) : 0) << endl;
	else cout << (1LL << (N - 1)) << endl;
	return 0;
}
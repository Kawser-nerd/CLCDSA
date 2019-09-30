#include <iostream>
using namespace std;
int main() {
	int N, P, evens = 0, odds = 0;
	cin >> N >> P;
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		if (x % 2 == 0) ++evens;
		else ++odds;
	}
	if (odds == 0) cout << (P == 0 ? (1LL << evens) : 0) << endl;
	else cout << (1LL << (evens + odds - 1)) << endl;
	return 0;
}
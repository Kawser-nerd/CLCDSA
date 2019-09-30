#include <iostream>
#include <cassert>

using namespace std;

int P[1000];

int solve() {
	int D;
	cin >> D;
	assert(D >= 1 && D <= 1000);
	for (int i = 0; i < D; i++) {
		cin >> P[i];
		assert(P[i] >= 1 && P[i] <= 1000);
	}
	int best = 1000;
	for (int i = 1; i <= 1000; i++) {
		// first do all the swapping,
		// then let them eat for no more than i minutes
		int cur = i;
		for (int j = 0; j < D; j++) {
			cur += (P[j] - 1) / i;
		}
		best = min(best, cur);
	}
	return best;
}

int main() {
	int T;
	cin >> T;
	assert(T >= 1 && T <= 100);
	for (int i = 0; i < T; i++) {
		cout << "Case #" << (i + 1) << ": " << solve() << endl;
	}
	return 0;
}

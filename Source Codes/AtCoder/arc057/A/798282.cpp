#include <iostream>
using namespace std;

long long solve() {
	long long A,K;
	cin >> A >> K;

	long long t = A;

	long long  day = 0;

	if (K == 0) {
		return 2000000000000 - A;
	}

	while(t < 2000000000000) {
		t += (1 + K * t);

		day++;

	}
	return day;
}

int main() {
	cout << solve() << endl;

	return 0;
}
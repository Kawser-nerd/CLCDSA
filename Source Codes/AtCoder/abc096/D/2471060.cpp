#include <iostream>
using namespace std;

bool isprime(int p) {
	if (p == 1) return false;
	for (int i=2; i<p; i++) {
		if (p % i == 0) return false;
	}
	return true;
}

int main() {
	int N;
	cin >> N;
	for (int i=31; i<=55555; i+=30) {
		if (isprime(i) == true) {
			if (i != 31) cout << " ";
			cout << i;
			N--;
		}
		if (N == 0) break;
	}
	cout << endl;
	return 0;
}
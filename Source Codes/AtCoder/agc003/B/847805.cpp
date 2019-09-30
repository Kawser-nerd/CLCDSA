#include <iostream>
#include <string>

using namespace std;

int main() {
	long N , a[100010];

	cin >> N;

	for (long i = 0; i < 100010; i++) {
		a[i] = 0;
	}

	for (long i = 0; i < N; i++) {
		long t;
		cin >> t;
		a[i] = t;
	}

	long count = 0;


	for (long i = 0; i < N; i++) {
		long g = max(0L, ((a[i] -1) / 2 ));
		count += g;
		a[i] -= g * 2;
	}

	for (long i = 0; i < N - 1; i++) {
		if (a[i] == 2) {
			a[i] = 0;
			count ++;		
		}

		long g = min(a[i],a[i+1]);
		count += g;
		a[i] -= g;
		a[i+1] -=g;
	}

	for (long i = 0; i < N; i++) {
		long g = a[i] / 2;
		count += g;
		a[i] -= g * 2;
	}

	cout << count << endl;
	return 0;
}
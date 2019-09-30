#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, T, c[1000], t[1000];
	
	cin >> N >> T;
	for (int i = 0; i < N; ++i) cin >> c[i] >> t[i];

	int min = c[0];
	int count = 0;
	for (int i = 0; i < N; ++i) {
		if (t[i] <= T && c[i] < min) min = c[i];
		if (T < t[i]) ++count;
	}

	if (count == N) cout << "TLE" << endl;
	else cout << min << endl;
}
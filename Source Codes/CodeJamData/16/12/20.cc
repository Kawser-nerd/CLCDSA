#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int seen[2501];

int main() {
	int N, T, prob=1;
	for (cin >> T; T--;) {
		cout << "Case #" << prob++ << ":";

		memset(seen, 0, sizeof(seen));
		cin >> N;
		for (int i = 0, x; i < N*(2*N-1); i++) {
			cin >> x;
			seen[x]++;
		}

		for (int i = 0; i <= 2500; i++) if (seen[i] & 1) {
			cout << ' ' << i;
		}
		cout << endl;
	}
}

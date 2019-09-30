#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int N, M;
    cin >> N >> M;
	int D = 1;
	for(int i=1; i<=sqrt(M); i++) {
		if(M % i == 0) {
			if (M / i >= N) {
				D = max(i, D);
			}
			if (i >= N) {
				D = max(M/i, D);
			}

		}
	}
	cout << D << endl;
}
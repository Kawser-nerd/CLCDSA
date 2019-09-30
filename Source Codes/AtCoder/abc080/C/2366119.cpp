#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;
using ll = long long;

const int NMAX = 100;
int F[NMAX][10];
int P[NMAX][11];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> F[i][j];
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 11; j++) {
			cin >> P[i][j];
		}
	}

	int ans = -(1 << 31);

	for (int i = 1; i < 1024; i++) {
		int sumP = 0;
		for (int j = 0; j < N; j++) {
			int sumi = 0;
			for (int k = 0; k < 10; k++) {
				if ((i >> k) & 1 && F[j][k]) {
					sumi++;
				}
			}
			sumP += P[j][sumi];
		}
		ans = max(ans,sumP);
	}

	cout << ans << endl;
	return 0;
}
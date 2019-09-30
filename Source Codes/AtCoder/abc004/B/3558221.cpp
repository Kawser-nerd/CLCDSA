#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(i, m, k) for(int i = m; i < k; ++i)
#define REP(i, k) for(int i = 0; i < k; ++i)

int main() {
	char K[4][4];
	for (int k = 0; k < 4; ++k) {
		cin >> K[k][0] >> K[k][1] >> K[k][2] >> K[k][3];
	}
	for (int k = 3; k >= 0; --k) {
		cout << K[k][3] << " " << K[k][2] << " " << K[k][1] << " " << K[k][0] << endl;
	}
	system("pause");
	return 0;
}
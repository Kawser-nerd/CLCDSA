#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long int lli;

#define INF (1e9)


int solv(int a, int b) {
	int tmp = a;
	int c = 0;
	while(tmp > 0) {
		c += tmp % b;
		tmp /= b;
	}
	return c;
}

int main() {
	int N;
    cin >> N;

	int ans = INF;
	for(int i=0; i<=N ; i++) {
		int c = solv(i, 6) + solv(N-i, 9);
		ans = min(c, ans);
	}

	cout << ans << endl;
}
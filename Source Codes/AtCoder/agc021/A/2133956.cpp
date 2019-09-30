#include <iostream>
#include <algorithm>
using namespace std;
long long N;
int main() {
	cin >> N;
	int ret = 0;
	for (int i = 0; i < 18; i++) {
		long long mul = 1;
		for (int j = 0; j < i; j++) mul *= 10;
		for (int j = 1; j <= 9; j++) {
			long long x = mul * (j + 1) - 1;
			if (x <= N) ret = max(ret, i * 9 + j);
		}
	}
	cout << ret << endl;
	return 0;
}
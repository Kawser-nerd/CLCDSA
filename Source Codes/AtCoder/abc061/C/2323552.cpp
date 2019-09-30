#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
	int N;
	long long K,total;
	cin >> N >> K;

	map<int, long long> mp;
	total = 0;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		mp[a] += b;
	}

	for (auto&& var : mp) {
		total += var.second;
		if (total >= K) {
			cout << var.first << endl;
			break;
		}
	}

	return 0;
}
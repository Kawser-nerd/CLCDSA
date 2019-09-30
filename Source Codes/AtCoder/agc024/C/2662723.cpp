#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<functional>
#include<cmath>
#include<algorithm>
typedef  long long ll;

int main() {
	ll n = 0, s = 0;
	ll count = 0;
	bool kiyomaru = false;
	std::vector<int> v;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> s;
		v.push_back(s);
	}
	v.push_back(0);
	if (v[0] != 0) {
		std::cout << -1 << std::endl;
		return 0;
	}
	for (int i = 1; i < n; i++) {
		count += v[i];
		if (v[i + 1] == v[i] + 1) {
			count -= v[i];
		}
		if (v[i + 1] - v[i] > 1) {
			std::cout << -1 << std::endl;
			return 0;
		}
	}
	std::cout << count << std::endl;
}
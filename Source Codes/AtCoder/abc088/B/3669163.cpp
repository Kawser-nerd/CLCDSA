#include <iostream>
#include <vector>

std::vector<int> v;
int main() {
	int N;
	int alice, bob;
	alice = bob = 0;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		std::cin >> input;
		v.push_back(input);
	}
	std::sort(v.begin(), v.end(), std::greater<int>());

	for (int i = 0; i < v.size(); i++) {
		if (i % 2 == 0) alice += v[i];
		else bob += v[i];
	}

	std::cout << alice - bob << std::endl;
	return 0;
}
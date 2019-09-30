#include<iostream>
#include<algorithm>
int main() {
	int N, M, X;
	std::cin >> N >> M >> X;

	int grid[101]{};

	for (int i{}; i < M; ++i) {
		int ai;
		std::cin >> ai;
		grid[ai] = 1;
	}


	auto left = std::count(std::begin(grid), std::begin(grid) + X, 1);
	std::cout << std::min(left, M - left) << "\n";
	return 0;
}
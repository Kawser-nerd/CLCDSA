#include <vector>
#include <cstdint>
#include <algorithm>
#include <iostream>
#include <map>

template <typename T>
T ncond(const std::vector<T> &a, T m)
{

	std::map<T, T> nums;
	nums[0]++;

	T sum = 0;
	for (auto x : a) {
		sum += x;
		nums[sum % m]++;
	}

	T ret = 0;
	for (auto x : nums) {
		ret += x.second * (x.second - 1) / 2;
	}

	return ret;
}

int main(int argc, const char *argv[])
{
	std::int64_t N, M;
	std::cin >> N >> M;

	std::vector<std::int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	std::cout << ncond(A, M) << std::endl;

	return 0;
}
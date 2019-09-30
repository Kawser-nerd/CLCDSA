#include <iostream>

int main () {
	int N, A, B;
	int sum, num;
	int ans = 0;
	std::cin >> N >> A >> B;
	for (int i = 1; i <= N; i++) {
		sum = 0;
		num = i;
		while (num > 0) {
			sum += num % 10;
			num /= 10;
		}
		if (A <= sum && sum <= B) {
			ans += i;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}
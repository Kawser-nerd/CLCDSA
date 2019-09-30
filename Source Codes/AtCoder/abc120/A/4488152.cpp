#include<iostream>
#include<algorithm>
int main() {
	int a, b, c;
	std::cin >> a >> b >> c;

	std::cout << std::min(b/a ,c) << "\n";
	return 0;
}
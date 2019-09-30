#include<iostream>

int main() {
	int A, B, X;
	std::cin >> A >> B >> X;

	std::cout << (A <= X && X <= A + B ? "YES" : "NO") << "\n";
	return 0;
}
#include<iostream>
#include<string>

int main(void) {

	std::string s;
	int A = 0, Z = 0, X = 0;
	std::cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A') {
			A = i + 1;
			break;
		}
	}
	for (int j = s.size() - 1; j > 0; j--) {
		if (s[j] == 'Z') {
			Z = j + 1;
			break;
		}
	}
	X = Z - A + 1;
	std::cout << X << std::endl;

}
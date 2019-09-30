#include <string>
#include <iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	int len_parity = s.length() % 2;
	int last_parity = (s.front() == s.back() ? 1 : 0);
	cout << (last_parity == len_parity ? "Second" : "First") << endl;
	return 0;
}
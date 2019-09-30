#include <iostream>
#include <string>

using namespace std;
int main() {
	string s;
	cin >> s;

	int out = 0;
	for(int i = 1; i < s.size(); i++) {
		if((s[i - 1] == '0' && s[i] == '1') || (s[i - 1] == '1' && s[i] == '0')) {
			s.erase(i - 1, 2);
			out+=2;
			i -= 2;
		}
	}
	cout << out << endl;
}
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
using lli = long long int;

lli nc2(lli l) {
	if (l < 2)return 0;
	lli ret = l;
	return (l * (l - 1)) / 2;
}

int main() {
	string s,t;
	cin >> s >> t;
	for (int i = 0; i < s.size(); i++) {
		rotate(s.begin(), s.begin() + 1, s.end());
		if (s == t) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string s; cin >> s;
	long long sum = s.size()*(s.size() - 1);
	for (int i = 1; i < s.size() - 1; i++) {
		if (s[i] == 'U')sum += i;
		else sum += (s.size() - i - 1);
	}
	cout << sum << endl;
	char ch; cin >> ch;
}
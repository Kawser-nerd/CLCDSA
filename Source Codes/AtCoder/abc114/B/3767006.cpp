#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <cstdlib>
using namespace std;

int main() {
	string S;
	string s[10];
	int x = 0;
	int res = 0;

	cin >> S;
	for (int i = 0; i < S.size() - 2; ++i) s[i] = S.substr(i, 3);

	for (int i = 0; i < S.size() - 2; ++i) {
		if (abs(753 - x) > abs(753 - stoi(s[i]))) x = stoi(s[i]);
	}
	res = abs(753 - x);
	cout << res << endl;
}
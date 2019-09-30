#include <iostream>
using namespace std;

int main() {
	char c;
	char v[5];

	cin >> c;
	v[0] = 'a';
	v[1] = 'i';
	v[2] = 'u';
	v[3] = 'e';
	v[4] = 'o';
	bool isV = false;

	for (int i = 0; i < 5; ++i) {
		if (v[i] == c) isV = true;
		}
	if (isV) cout << "vowel" << endl;
	else cout << "consonant" << endl;
}
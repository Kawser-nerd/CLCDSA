#include <iostream>
#include <string>

using namespace std;

int main() {
	char S[50];

	cin >> S;

	if (S[strlen(S) - 1] == 'T') {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}
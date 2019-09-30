#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int A, B;	cin >> A >> B;
	if (A == B) {
		cout << "Draw" << endl;
		return 0;
	}
	if (A == 1) {
		cout << "Alice" << endl;
		return 0;
	}
	if (B == 1) {
		cout << "Bob" << endl;
		return 0;
	}

	if (A > B) {
		cout << "Alice" << endl;
		return 0;
	}
	cout << "Bob" << endl;

	return 0;
}